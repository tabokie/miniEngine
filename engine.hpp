#ifndef ENGINE_HPP_
#define ENGINE_HPP_

#include "stemmer.hpp" /* class Stemmer */
#include "db_interface.hpp" /* class DB, class TABLE */
#include "disc_reader.hpp" /* class MemMap, class IndexRefer, class TextRefer, class Manifest */

#include <iostream>
#include <algorithm> /* sort() */

namespace search_engine{

using namespace std;
using namespace disc_reader;
using namespace db_interface;

class Engine{

 private:
 	// stemmer
	Stemmer* stemmer_;
	// read index
	MemMap* index_map_;
	IndexRefer* index_;
	// read text
	MemMap* text_map_;
	Manifest* text_manifest_;
	TextRefer* text_;
	// read database
	DB* db_;
	PassageTABLE* ptable_;
	LocalTermTABLE* lterm_;
	GlobalTermTABLE* gterm_;
    string root_path_;

 public:
 	Engine() = default;
 	~Engine(){ }
    Engine(string path):root_path_(path) { }
	void Setup(){
		openStemmer_();
		openIndex_();
		openText_();
		openDatabase_();
	}
	void Close(){
		closeMap_();
		closeDatabase_();
	}
	// query string -> id and operation -> bitset bool op => index vector
	// index vector -> ranking -> sort
	void Query(string str){
		// Parse //
		auto tokens = ParseToken(str); 
		// Fetch Index // 
		auto bits = ComposeIndex(tokens);
		vector<passage_> passages = MapIndex(bits);
		// Ranking //
		for(auto & p : passages){
			for(auto & t : tokens){
				if(!t.op)
					p.rank = get_weight( p.id, t.term );
			}
		}
		sort(passages.begin(), passages.end());
		// mod output //
		// title
		vector<string> titles;
		for(auto &p : passages){
			titles.push_back(text_->get_line(p.id, 1));
		}
		// link
		vector<string> links;
		string head = "http://shakespeare.mit.edu/";
		string tail = ".html";
		for(auto &p : passages){
			string name = get<0>(ptable_->Query(p.id));
			int idx;
			if(( idx = name.find('.')) < name.size() - 1 && name.find("sonnet") != 0){
				string book = name.substr(0,idx);
				links.push_back( head+ book+'/'+name +tail );
			}
			else{
				links.push_back( head + "Poetry/" + name + tail);
			}
		}
		// sentence
		vector<string> sentences;
		for(auto &p : passages){
			int first = 0;
			for(auto &t : tokens){
				first = get<1>(lterm_->Query(t.term, p.id));
				if(first > 0)break;
			}
			if(first <= 0)
				sentences.push_back(text_->get_line(p.id, 1));
			else
				sentences.push_back(text_->get_line(p.id, first) + text_->get_line(p.id, first+1) + text_->get_line(p.id, first+2));
		}

        int n = titles.size();
        cout << "{\"data\":[";
        for (int i = 0; i < n; i++) {
            cout << "{";
            cout << "\"title\":\"" << titles[i] << "\",";
            cout << "\"link\":\"" << links[i] << "\",";
            cout << "\"sentence\":\"" << sentences[i] << "\""; 
            cout << "}" << (i < n - 1 ? "," : ""); 
        }
        cout << "]}";
    }

 private:
 	// Open Subroutines //
	void openStemmer_(void){ 
		stemmer_ = new Stemmer();
	}
	void openIndex_(void){
		index_map_ = new MemMap((root_path_ + "/data/index").c_str());
		index_map_->Map("index_map");
		char* index_ptr(index_map_->get_ptr());
		index_ = new IndexRefer(index_ptr);
	}
	void openText_(){

		MemMap temp_map;
		temp_map.Open((root_path_ + "/data/text_manifest").c_str());
		temp_map.Map("text_manifest_map");
		string text_manifest_str(temp_map.get_ptr());
		// de-serialize
		text_manifest_ = new Manifest(text_manifest_str);
		temp_map.Close(); // close disc map

		text_map_ = new MemMap((root_path_ + "/data/text").c_str());
		text_map_->Map("text_map");
		static string text_str(text_map_->get_ptr()); // bad practice
		text_ = new TextRefer();
		text_->set_manifest(text_manifest_);
		text_->set_text(&text_str);
	}
	void openDatabase_(void){

		db_ = new DB((root_path_ + "/data/main.db").c_str());
		ptable_ = new PassageTABLE(db_);
		ptable_->Init();
		lterm_ = new LocalTermTABLE(db_);
		lterm_->Init();
		gterm_ = new GlobalTermTABLE(db_);
		gterm_->Init();
	}

	// Close Subroutines
	void closeMap_(void){
		index_map_->Close();
		text_map_->Close();
	}
	void closeDatabase_(void){
		db_->Close();
	}
	
	// Internal Structure //
	struct term_{
		int id;
		string term;
		bool op; // 0: or, 1: not
		term_(int i = -1,string t = string(""), bool o = false):id(i),term(t),op(o){ }
	};
	struct passage_{
		int id;
		float rank;
		passage_(int i = -1, float r = 0):id(i),rank(r){ }
		~passage_(){ }
		// inverse order
		bool operator < (passage_ that) const{
			return rank > that.rank;
		}
	};

	// Parse Subroutine //
	// get lower text form of string
	static string lower(string str){
		char* new_ptr = new char[str.size()+1];
		int cur = 0;
		for(int i = 0; i < str.size(); i++){
			if(str[i] <= 'Z' && str[i] >= 'A'){
				new_ptr[cur++] = str[i] - 'A' + 'a';
			}
			else if(str[i] <= 'z' && str[i] >= 'a'){
				new_ptr[cur++] = str[i];
			}
		}
		new_ptr[cur] = '\0';
		return string(new_ptr);
	}
	// Parse Routine //
	vector<term_> ParseToken(string str){

		bool not_flag = false;
		istringstream str_s(str);
		string term;
		int id;
		vector<term_> v;
		while(getline(str_s, term, ' ')){
			if(term == string("-")){
				not_flag = true;
			}
			term = stemmer_->Stem(lower(term));
			int id = get<0>(gterm_->Query(term));
			if(id <= 0)continue;
			v.push_back(term_(id,term, not_flag));
		}

		return v;
	}
	// Indexer Subroutines //
	// fetch bitset form of index from file
	bitset<kPassageSize> ComposeIndex(vector<term_> tokens){
		bitset<kPassageSize> bits;
		if(tokens.empty())return bits;
		bits.set();
		int occu;
		for(auto token : tokens){
			if(token.op)continue; // not op
			occu = get<2>(gterm_->Query(token.id));
			if(occu > kPassageSize / 9.0)
				bits = bits & index_->get_index(token.id);
		}
		for(auto token : tokens){
			occu = get<2>(gterm_->Query(token.id));
			if(occu <= kPassageSize / 9.0)
				bits = bits | index_->get_index(token.id);
		}
		for(auto token : tokens){
			if(!token.op)continue; // not op
			bits = bits & ~(index_->get_index(token.id));
		}
		return bits;
	}
	// convert bitset to vector
	vector<passage_> MapIndex(bitset<kPassageSize> bits){
		vector<passage_> passages;
		for(int i = 0;i<kPassageSize;i++){
			if(bits[i]){
				passages.push_back(passage_(i+1));
			}
		}
		return passages;
	}

	// Ranking Subroutines //
	// weight calc
	inline float get_weight(int p_id, string term){
		float tf = static_cast<float>(get<0>(lterm_->Query(term, p_id))) / sqrt( static_cast<float>(get<1>(ptable_->Query(p_id))) );
		float idf = log( static_cast<float>(kPassageSize) / get<2>(gterm_->Query(term)) );
		return tf * idf;
	}


}; /* class Engine */

} /* namespace search_engine */


#endif /* ENGINE_HPP_ */

// float cluster_index(vector<float> v1, vector<float> v2){
// 	vector<float> index;
// 	int size = v1.size();
// 	for(int i=0;i<size;i++){
// 		index.push_back((v1[i]+v2[i])/(v2[i]-v1[i]));
// 	}
// 	return index.var();
// }

// float get_weight(p_id, term){
// 	local_term_table.get_freq(p_id, term) / passage_table.get_size(p_id) * log(passage.size() / global_term_table.get_occu() );
// 	local_term_table.get_freq(p_id, term) / sqrt(passage_table.get_size(p_id)) * log(passage.size() / global_term_table.get_occu() );
// }
