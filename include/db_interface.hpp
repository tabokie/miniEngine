#ifndef DB_INTERFACE_HPP_
#define DB_INTERFACE_HPP_

/*
Base :
	class DB(const char* db_name);
		class TABLE(DB* db_ptr);
		TABLE.Init();
		TABLE.Insert(*);
		TABLE.Query(*);
	DB.Close();
Derived :
	class PassageTABLE:
		bool Insert(int id, string name, int size = -1);
		tuple<string name, int size> Query(int id);
	class LocalTermTABLE:
		bool Insert(string name, int id, int freq = -1, int first = -1, int last = -1);
		tuple<int freq, int first, int last> Query(string name, int id);
	class GlobalTermTABLE:
		deleted : // bool Insert(int id, string name, int freq = -1, int occu = -1);
		tuple<int id, int freq, int occu> Query(string name);
		tuple<string term, int freq, int occu> Query(int id);
	class PredictTABLE:
		bool Insert(string term, string full, string first, string second);
		tuple<string, string, string> Query(string term);
*/

#include "sqlite3.h" /* sqlite3_open(), sqlite3_close(), sqlite3_exec() */

#include <iostream>
#include <sstream>
#include <tuple> /* tuple<*>, get<x>, make_tuple() */
#include <bitset> /* bitset<n> */
// #include <windows.h>

namespace db_interface{

using namespace std;

// Global Var //
const int kPassageSize = 888;
const int kTermSize = 13989;

// Global Communicator and Flags //
stringstream kStrStream; 
bool kResponding = false;
int kRespondingSize = 0;

static int query_callback(void *NotUsed, int argc, char **argv, char **azColName){
	// sending to global stream
	kStrStream << '$';
	for(int i=0; i<argc; i++){
		if(i!=0)kStrStream<< ":";
		kStrStream << azColName[i] << "=" << (argv[i] ? argv[i] : "") ;
	}
	kStrStream << '$';
	// turning flags
	kResponding = true;
	kRespondingSize ++;
	return 0;
}

class DB{
	// database handle
	sqlite3 * db_;
	// flags
	bool is_opened_;
	// error msg
	char* err_msg_;
 public:
	DB():db_(nullptr),is_opened_(false){ }
	DB(const char* path):db_(nullptr),is_opened_(false){
		Open(path);
	}
	~DB(){if(is_opened_)Close();}

	// accessor //
	bool is_opened(void){return is_opened_;}

	// Open Routine //
	void Open(const char* path){
		if(is_opened_)Close();
		int res = sqlite3_open(path, &db_);
		if(res){
			cout << "Can't open database." << endl << flush;
			exit(0);
		}
		is_opened_ =  true;
	}
	// Close Routine //
	void Close(void){
		sqlite3_close(db_);
	}
	// Run sql line //
	void Run(const char* sql){
		int res = sqlite3_exec(db_, sql, query_callback, 0, &err_msg_);
		if(res != SQLITE_OK){
			cout << "SQL error : " << err_msg_ << endl;
			cout << sql << endl << flush;
			sqlite3_free(err_msg_);
		}
	}
}; /* class DB */

class TABLE{
 public:
 	TABLE():db_(nullptr){ }
	TABLE(DB* db){
		Reset_bool(); 
		if(!Link(db))cout << "Can't link to database." << endl;
	}
	virtual ~TABLE(){ }

	void Reset_bool(){
		db_linked_ = false;
		table_created_ = false;
	}

	bool Link(DB * db){
		if(db && db->is_opened()){
			db_ = db;
			db_linked_ = true;
			return true;
		}
		return false;
	}

	void Run(const char* sql){
		db_->Run(sql);
	}
 protected:
 	// database handle
	DB * db_;
	// flags
	bool db_linked_;
	bool table_created_;
 
	bool Init_(const char* name, const char* meta){
		if(!db_linked_)return false;
		string create_sql = string("CREATE TABLE IF NOT EXISTS ")+name+ "(" +meta+");";
		db_->Run(create_sql.c_str());
		table_created_ = true;
		return true;
	}
	
}; /* class TABLE */

// preset initial sql and meta info //
const char* passage_table_meta =  "ID INT PRIMARY KEY NOT NULL,"\
								  "NAME TEXT NOT NULL,"\
								  "SIZE INT";
const char* passage_table_list = "ID,NAME,SIZE";
const char* passage_table_name = "PASSAGE";

class PassageTABLE : public TABLE{
 public:
 	PassageTABLE(DB* db){ 
 		Reset_bool(); 
		if(!Link(db))cout << "Can't link to database." << endl;
 	}
	~PassageTABLE(){ }
	bool Init(void){
		return Init_(passage_table_name,passage_table_meta);
	}
	bool Insert(int id, string name, int size = -1){
		if(!db_linked_ || !table_created_)return false;
		string insert_sql = string("INSERT INTO ")+ passage_table_name+"("+passage_table_list+") "+\
							"VALUES ("+to_string(id)+","\
							"\'"+name+"\',"+\
							to_string(size)+");";
		db_->Run(insert_sql.c_str());
		return true;
	}
	tuple<string,int> Query(int id){
		string query_sql = string("SELECT NAME,SIZE FROM ")+ passage_table_name +" WHERE ID = "+to_string(id)+";";
		db_->Run(query_sql.c_str());

		if(!kResponding)return make_tuple(string(""),-1);

		string str;
		getline(kStrStream,str,'$');
		getline(kStrStream,str,'$');
		if(str == "")return make_tuple(string(""),-1);

		kResponding = false;
		kRespondingSize = 0;

		string name;int size,idx;
		istringstream stream(str);
		getline(stream,str,':');
		if((idx=str.find("NAME"))==-1)return make_tuple(string(""),-1);
		name = &(str.c_str()[idx+5]);
		getline(stream,str,':');
		if((idx=str.find("SIZE"))==-1)return make_tuple(string(""),-1);
		size = atoi(&(str.c_str()[idx+5]));

		return make_tuple(name,size);
	}
}; /* PassageTABLE */

// preset initial sql and meta info //
const char* local_term_table_meta = "NAME TEXT NOT NULL,"\
									"ID INT NOT NULL,"\
									"FREQ INT,"\
									"FIRST INT,"\
									"LAST INT,"\
									"PRIMARY KEY(NAME, ID)";
const char* local_term_table_list = "NAME,ID,FREQ,FIRST,LAST";
const char* local_term_table_name = "LTERM";
class LocalTermTABLE : public TABLE{
 public:
 	LocalTermTABLE(DB* db){ 
 		Reset_bool(); 
		if(!Link(db))cout << "Can't link to database." << endl;
 	}
	virtual ~LocalTermTABLE(){ }
	bool Init(void){
		return Init_(local_term_table_name, local_term_table_meta);
	}
	bool Insert(string name, int id, int freq = -1, int first = -1, int last = -1){
		if(!db_linked_ || !table_created_)return false;
		string insert_sql = string("INSERT INTO ")+ local_term_table_name+"("+local_term_table_list+") "+\
							"VALUES (\'"+name+"\',"+\
							to_string(id)+","+\
							to_string(freq)+","+\
							to_string(first)+","+\
							to_string(last)+");";
		db_->Run(insert_sql.c_str());
		return true;
	}
	tuple<int,int,int> Query(string name, int id){
		string query_sql = string("SELECT FREQ,FIRST,LAST FROM ")+local_term_table_name+
			" WHERE NAME = \'" +name+ "\' AND ID = "+to_string(id)+";";
		db_->Run(query_sql.c_str());

		if(!kResponding)return make_tuple(-1,-1,-1);

		string str;
		getline(kStrStream,str,'$');
		getline(kStrStream,str,'$');
		if(str == "")return make_tuple(-1,-1,-1);

		kResponding = false;
		kRespondingSize = 0;

		int freq,first,last,idx;
		istringstream stream(str);
		getline(stream,str,':');
		if((idx=str.find("FREQ"))==-1)return make_tuple(-1,-1,-1);
		freq = atoi(&(str.c_str()[idx+5]));
		getline(stream,str,':');
		if((idx=str.find("FIRST"))==-1)return make_tuple(-1,-1,-1);
		first = atoi(&(str.c_str()[idx+6]));
		getline(stream,str,':');
		if((idx=str.find("LAST"))==-1)return make_tuple(-1,-1,-1);
		last = atoi(&(str.c_str()[idx+5]));	

		return make_tuple(freq,first,last);
	}
	// bad practice : coupling
	bitset<kPassageSize> FuzzyQuery(string name){
		string query_sql = string("SELECT ID FROM ")+local_term_table_name+
			" WHERE NAME = \'" +name+ "\';";
		db_->Run(query_sql.c_str());

		bitset<kPassageSize> bits;

		if(!kResponding)return bits;
				
		string str;
		while(kRespondingSize--){
			getline(kStrStream,str,'$');
			getline(kStrStream,str,'$');
			if(str == "")break;
			int id = atoi(&(str.c_str()[3]));
			bits.set(id-1);
		}

		kResponding = false;
		kRespondingSize = 0;
		return bits;
	}
}; /* class LocalTABLE */


// preset initial sql and meta info //
const char* global_term_table_meta = "ID INTEGER PRIMARY KEY AUTOINCREMENT,"\
									"NAME TEXT NOT NULL UNIQUE,"\
									"FREQ INT,"\
									"OCCU INT";
const char* global_term_table_list = "ID,NAME,FREQ,OCCU";
const char* global_term_table_name = "GTERM";
class GlobalTermTABLE : public TABLE{
	// deleted insert method on a static db table
	bool Insert_(int id, string name, int freq = -1, int occu = -1){
		if(!db_linked_ || !table_created_)return false;
		string insert_sql = string("INSERT INTO ")+ global_term_table_name+"("+global_term_table_list+") "+\
							"VALUES ("+to_string(id)+",\'"
							+name+"\',"+\
							to_string(freq)+","+\
							to_string(occu)+")";
		db_->Run(insert_sql.c_str());
		return true;
	}
 public:
 	GlobalTermTABLE(DB* db){ 
 		Reset_bool(); 
		if(!Link(db))cout << "Can't link to database." << endl;
 	}
	virtual ~GlobalTermTABLE(){ }
	bool Init(void){
		return Init_(global_term_table_name, global_term_table_meta);
	}
	tuple<int,int,int> Query(string name){
		string query_sql = string("SELECT ID,FREQ,OCCU FROM ")+ global_term_table_name +" WHERE NAME = \'"+name+"\';";
		db_->Run(query_sql.c_str());

		if(!kResponding)return make_tuple(-1,-1,-1);

		string str;
		getline(kStrStream,str,'$');
		getline(kStrStream,str,'$');
		if(str == "")return make_tuple(-1,-1,-1);

		kResponding = false;
		kRespondingSize = 0;

		int idx,id,freq,occu;
		istringstream stream(str);
		getline(stream,str,':');
		if((idx=str.find("ID"))==-1)return make_tuple(-1,-1,-1);
		id = atoi(&(str.c_str()[idx+3]));
		getline(stream,str,':');
		if((idx=str.find("FREQ"))==-1)return make_tuple(-1,-1,-1);
		freq = atoi(&(str.c_str()[idx+5]));
		getline(stream,str,':');
		if((idx=str.find("OCCU"))==-1)return make_tuple(-1,-1,-1);
		occu = atoi(&(str.c_str()[idx+5]));
		return make_tuple(id,freq,occu);
	}
	tuple<string,int,int> Query(int id){
		string query_sql = string("SELECT NAME,FREQ,OCCU FROM ")+ global_term_table_name +" WHERE ID = "+to_string(id)+";";
		db_->Run(query_sql.c_str());

		if(!kResponding)return make_tuple(string(""),-1,-1);

		string str;
		getline(kStrStream,str,'$');
		getline(kStrStream,str,'$');
		if(str == "")return make_tuple(string(""),-1,-1);

		kResponding = false;
		kRespondingSize = 0;

		int idx,freq,occu;
		string name;
		istringstream stream(str);
		getline(stream,str,':');
		if((idx=str.find("NAME"))==-1)return make_tuple(string(""),-1,-1);
		name = &(str.c_str()[idx+5]);
		getline(stream,str,':');
		if((idx=str.find("FREQ"))==-1)return make_tuple(string(""),-1,-1);
		freq = atoi(&(str.c_str()[idx+5]));
		getline(stream,str,':');
		if((idx=str.find("OCCU"))==-1)return make_tuple(string(""),-1,-1);
		occu = atoi(&(str.c_str()[idx+5]));
		return make_tuple(name,freq,occu);
	}
}; /* class GlobalTABLE */

// preset initial sql and meta info //
const char* predict_table_meta = "NAME TEXT PRIMARY KEY NOT NULL,"\
									"FULL TEXT,"\
									"FIRST TEXT,"\
									"SECOND TEXT";
const char* predict_table_list = "NAME,FULL,FIRST,SECOND";
const char* predict_table_name = "PREDICT";
class PredictTABLE : public TABLE{
 public:
 	PredictTABLE(DB* db){ 
 		Reset_bool(); 
		if(!Link(db))cout << "Can't link to database." << endl;
 	}
	virtual ~PredictTABLE(){ }
	bool Init(void){
		return Init_(predict_table_name, predict_table_meta);
	}
	bool Insert(string name, string full, string first, string second){
		if(!db_linked_ || !table_created_)return false;
		string insert_sql = string("INSERT INTO ")+ predict_table_name+"("+predict_table_list+") "+\
							"VALUES (\'"+name+"\',"+\
							"\'"+full+"\',"+\
							"\'"+first+"\',"+\
							"\'"+second+"\');";
		db_->Run(insert_sql.c_str());
		return true;
	}
	tuple<string,string,string> Query(string name){
		string query_sql = string("SELECT FULL,FIRST,SECOND FROM ")+predict_table_name+
			" WHERE NAME = \'" +name +"\';";
		db_->Run(query_sql.c_str());

		if(!kResponding)return make_tuple(string(""),string(""),string(""));

		string str;
		getline(kStrStream,str,'$');
		getline(kStrStream,str,'$');
		if(str == "")return make_tuple(string(""),string(""),string(""));

		kResponding = false;
		kRespondingSize = 0;

		string full,first,second;
		int idx;
		istringstream stream(str);
		getline(stream,str,':');
		if((idx=str.find("FULL"))==-1)return make_tuple(string(""),string(""),string(""));
		first = &(str.c_str()[idx+5]);
		getline(stream,str,':');
		if((idx=str.find("FIRST"))==-1)return make_tuple(string(""),string(""),string(""));
		first = &(str.c_str()[idx+6]);
		getline(stream,str,':');
		if((idx=str.find("SECOND"))==-1)return make_tuple(string(""),string(""),string(""));
		second = &(str.c_str()[idx+7]);

		return make_tuple(full,first,second);
	}
}; /* class PredictTABLE */

} /* namespace db_interface */

#endif /* DB_INTERFACE_HPP_ */