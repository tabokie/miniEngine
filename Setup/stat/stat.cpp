#include "disc_reader.hpp"
#include "db_interface.hpp"

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <fstream>

using namespace std;
using namespace disc_reader;
using namespace db_interface;


struct term_meta{
	string term;
	size_t freq;
	int first;
	int last;
	term_meta(string s = string(""), size_t f = 0, int a = -1, int b = -1): 
		term(s),freq(f),first(a),last(b) { }
	~term_meta(){ }
};

struct passage_meta{
	int id;
	string name;
	size_t size;
	vector<term_meta> terms;
	passage_meta(): id(-1), name(""), size(-1){ }
	passage_meta(int i, string n): id(i), name(n), size(-1){ }
	~passage_meta(){ }
	void set_size(size_t s){ size = s; }
	void new_term(string n){
		terms.push_back(term_meta(n));
	}
	void set_freq(int f){
		terms[terms.size()-1].freq = f;
	}
	void set_first(int f){
		terms[terms.size()-1].first = f;
	}
	void set_last(int l){
		terms[terms.size()-1].last = l;
	}
};

const size_t MAX_WORD = 30;

class PassageMeta{
	vector<passage_meta> p_vec_;

 public:
 	PassageMeta() = default;
	PassageMeta(string str){
		Serialize(str);
	}
	~PassageMeta(){ }
	void Serialize(string str){
		size_t cursor = 0;
		int p_id;
		string p_name;
		while(true){
			cursor = str.find('{',cursor); // parse passage obj
			if(cursor == string::npos)break;
			// parse id
			cursor = str.find("id",cursor);
			cursor = str.find(':',cursor);
			p_id = atoi(&str.c_str()[cursor+1]);
			// parse name
			cursor = str.find("name",cursor);
			cursor = str.find(':',cursor);
			cursor = str.find('\"',cursor)+1;
			istringstream name_s(str.substr(cursor, MAX_WORD));
			getline(name_s,p_name,'\"');
			p_name = p_name.substr(p_name.find_first_not_of(' '), p_name.find_last_not_of(' ')-p_name.find_first_not_of(' ')+1);
			passage_meta m(p_id,p_name);
			cout << p_id <<" "<<p_name<<endl;
			// init member
			p_vec_.push_back(m);
			cursor = str.find("},",cursor);
		}
		// std::sort(p_vec_.begin(), p_vec_.end(),[]bool(manifest_meta a, manifest_meta b){return a.id < b.id;} )
	}
	bool ParseTermMeta(int id, string str){
		if(id <=0 || id > p_vec_.size()){return false;}
		passage_meta& p = p_vec_[id-1];
		size_t ctrl_idx = str.find_first_not_of('$');
		str.erase(0,ctrl_idx);
		ctrl_idx = str.find('$');
		str.erase(ctrl_idx, str.size()-ctrl_idx);
		istringstream terms_s(str);
		string term;
		while(getline(terms_s, term, ',')){
			istringstream term_s(term);
			string member; 
			getline(term_s, member, ':');
			p.new_term(member); // term name
			getline(term_s, member, '.');
			p.set_freq(atoi(member.c_str())); // frequency
			getline(term_s, member, '.');
			p.set_first(atoi(member.c_str())); // first_occu
			getline(term_s, member, '.');
			p.set_last(atoi(member.c_str())); // last_occu
		}
	}
	void Write(const char* path){
		ofstream fout;
		fout.open( path, ios::out | ios::trunc);
		for(auto& p : p_vec_){
			fout << "{\n    ";

			fout << "\"id\":" << p.id << ",\n    ";
			fout << "\"name\":\"" << p.name << "\",\n    ";
			fout << "\"size\":" << p.size << ",\n    ";

			fout << "\"terms\":[\n    ";
			for(auto& t : p.terms){
				fout << "{\"term\":" << t.term << ",";
				fout << "\"freq\":" << t.freq << ",";
				fout << "\"first\":" << t.first << ",";
				fout << "\"last\":" << t.last << "},\n    ";
			}
			fout << "]\n";

			fout << "},\n";
		}
	}
	// bad practice
	void WriteDB(int id, LocalTermTABLE* table){
		if(id<=0 || id>p_vec_.size())return;
		passage_meta& p = p_vec_[id-1];
		if(id != p.id){
			cout << "error matching id" << endl;
			return;
		}
		for(auto& t : p.terms){
			table->Insert(t.term, id,\
				static_cast<int>(t.freq),\
				static_cast<int>(t.first),\
				static_cast<int>(t.last) );
		}

	}
	inline void Put(void){
		for(auto i : p_vec_){
			cout << i.name << " ";
		}
	}
	inline passage_meta get_item(size_t idx){
		if(idx > p_vec_.size() || idx <= 0)return passage_meta();
		return p_vec_[idx-1];
	}
	inline string get_name(size_t idx){
		return get_item(idx).name;
	}
	inline bool set_size(size_t idx, size_t size){
		if(idx > p_vec_.size() || idx <= 0)return false;
		p_vec_[idx-1].set_size(size);
		return true;
	}
	inline int get_size(size_t idx){
		if(idx > p_vec_.size() || idx <= 0)return -1;
		return static_cast<int>(p_vec_[idx-1].size);
	}
	inline size_t size(void){
		return p_vec_.size();
	}
};

struct TrieNode{
	char key;
	int freq;
	shared_ptr<TrieNode> childs[26];
	int first_occ;
	int last_occ;

	TrieNode(char ch = '\0', int f = 0):
		key(ch),freq(f),first_occ(-1),last_occ(-1){
			for(int i;i <26; i++)childs[i] = nullptr;
		}
	~TrieNode(){ }
	shared_ptr<TrieNode> get_branch(char ch){
		int idx = int(ch) - int('a');
		if(idx >= 26 || idx < 0)return nullptr;
		if(childs[idx] == nullptr){
			childs[idx] = make_shared<TrieNode>(ch);
			// childs[idx]->parent = shared_ptr<TrieNode>(this);
		}
		return childs[idx];
	}
	inline void add_match(int id){
		freq++;
		if(id == 1)return; // title not count in sentence identify
		if(first_occ == -1)first_occ = id;
		else last_occ = id;
	}
};

class Trie{
	shared_ptr<TrieNode> root_;
 public:
	Trie():root_(nullptr){ }
	~Trie(){ }

	void Insert(string str, int id){
		if(!root_)root_ = make_shared<TrieNode>('\0',-1);
 		int idx = 0;
		shared_ptr<TrieNode> cur = root_;
		while(idx < str.size()){
			cur = cur->get_branch(str[idx]);
			if(cur == nullptr){
				cout << "Error branching" << endl;
				exit(0);
			}
			idx++;
		}
		cur->add_match(id);
	}
	void Clear(void){
		root_ = nullptr;
	}
	void Put(string & s){
		s = "$";
		for(auto& i : root_->childs){
			recurPut(s, i, string(""));
		}
		s += "$";
		return ;
	}
	void recurPut(string & s, shared_ptr<TrieNode> node, string str){
		if(!node)return;
		if(node->freq > 0){
			s += (str + node->key + ":" + to_string(node->freq) +'.'+ to_string(node->first_occ)+'.'+ to_string(node->last_occ) + ",");
		}
		for(auto& i : node->childs){
			recurPut(s, i, str + node->key);
		}
	}

};

using mmap = MemMap;

int main(int argc, char *argv[]){

	if(argc>1){
		string PATH(argv[1]);
	}
	else string PATH("");
	
	// prepare data access //

	mmap map;
	mmap temp_map; // for read in meta

	// read in token manifest
	temp_map.Open((PATH+"token_manifest").c_str());
	temp_map.Map("token_manifest_map");
	string token_manifest_str(temp_map.get_ptr());
	// de-serialize
	Manifest token_manifest(token_manifest_str);
	temp_map.Close(); // close disc map

	// refer to token text
	map.Open((PATH+"token").c_str());
	map.Map("token_map");
	string token_str(map.get_str());
	// build up interface
	TextRefer ref_token;
	ref_token.set_manifest(&token_manifest);
	ref_token.set_text(&token_str);

	// read in passage manifest (p_id to p_name)
	temp_map.Open((PATH+"tokenizer_meta").c_str());
	temp_map.Map("tokenizer_meta_map");
	string tokenizer_meta_str(temp_map.get_ptr());
	PassageMeta passage_meta(tokenizer_meta_str);
	PassageMeta & ref_p = passage_meta;
	temp_map.Close();

	// open and link to database
	DB db((PATH+"main.db").c_str());
	PassageTABLE passage(&db);
	passage.Init();
	LocalTermTABLE lterm(&db);
	lterm.Init();
	GlobalTermTABLE gterm(&db);
	gterm.Init();

	// stat passage meta, write to db::PassageTABLE //
	// p_id to p_name and p_size
	// stat local term meta, write to db::LocalTermTABLE //
	// term + p_id to freq and first and last

	Trie dict; // Trie tree for stat word freq
	size_t p_size = ref_p.size();
	for(int i = 1; i <= p_size; i++){
		// stat passage size
		size_t size = 0;

		int j = 1;
		while(true){ // p = i, s = j
			string line = ref_token.get_line(i,j);
			// cout << line << endl;
			if(line[0] == '\0'){
				break;
			}
			istringstream line_s(line);
			string word;
			while(getline(line_s, word, ' ')){
				if(word.size() > 2){
					size++;
					dict.Insert(word, j); // insert word to Trie
				}
			}
			j ++ ;
		}
		cout <<i<<" "<<j<<" "<<size <<" "<<ref_p.get_name(i)<< endl<< flush;
		ref_p.set_size(i, size);
		// write to db
		passage.Insert(i, ref_p.get_name(i), ref_p.get_size(i));

		// stat passage term freq
		string term_meta;
		dict.Put(term_meta);
		passage_meta.ParseTermMeta(i, term_meta);
		passage_meta.WriteDB(i, &lterm);
		// passage_meta.Write("out");
		dict.Clear();
	}

	// stat global term and write to db::GlobalTermTABLE //
	// term to term_id and freq and occu 
	gterm.Run("insert into GTERM (NAME,FREQ,OCCU) select NAME, sum(freq), count(NAME) from LTERM group by NAME;");

	map.Close();
	db.Close();

	return 0;
}

