#include "db_interface.hpp"
#include "disc_reader.hpp"
#include <vector>
#include <string>
#include <memory>
#include <tuple>

using namespace std;

using namespace disc_reader;
using namespace db_interface;
using mmap = MemMap;

string find_next(string full, string term){

	int idx = full.find(term);
	if(idx == string::npos)return string("");
	int temp;
	if(  (temp=full.find(term,idx+1)) < string::npos)idx = temp;
	idx = full.find(' ', idx);
	if(idx == string::npos)return string("");

 	istringstream full_s(full.substr(idx+1));
 	string word;
 	if(!getline(full_s, word,' '))return string("");

 	return word;
}

string tokenize(string word){
	char* new_str = new char[word.size()+1];
	int cur = 0;
	for(int i=0; i<word.size(); i++){
		if(word[i] <= 'Z' && word[i] >= 'A'){
			new_str[cur++] = word[i] - 'A' + 'a';
		}
		else if(word[i] <= 'z' && word[i] >= 'a'){
			new_str[cur++] = word[i];
		}
	}
	new_str[cur] = '\0';
	return string(new_str);
}

string find(string full, string term){
	istringstream full_s(full);
	string word;
	term = term.substr(0,term.size()-1);
	while(getline(full_s, word, ' ' )){
		if(tokenize(word).find(term) < string::npos){
			return word;
		}
	}
	return string("");
}

struct LinkedNode{
	int key;
	int freq;
	shared_ptr<LinkedNode> next;
	LinkedNode(int k, int f = 1): key(k),freq(f),next(nullptr){ }
	~LinkedNode(){ }
	void add_match(void){
		if(freq < 0) freq = 0;
		freq ++;
	}
};

class LinkedList{
	shared_ptr<LinkedNode> head_;

 public:

	LinkedList():head_(nullptr){ }
	~LinkedList(){ }

	void Insert(int key){
		shared_ptr<LinkedNode> cur = head_;
		if(!cur){
			head_ = make_shared<LinkedNode>(key);
			return ;
		}
		while(cur->next){
			if(cur->key == key){
				cur->add_match();
				return ;
			}
			else if(cur->key < key){
				shared_ptr<LinkedNode> new_node = make_shared<LinkedNode>(key);
				new_node->next = cur->next;
				cur->next = new_node;
				return ;
			}
			cur = cur->next;
		}
	}

	tuple<int,int> FindTwo(void){
		shared_ptr<LinkedNode> cur = head_;
		int first_freq = -1;
		int first_key = -1;
		int second_freq = -1;
		int second_key = -1;
		while(cur){
			if(cur->freq >= first_freq){
				second_freq = first_freq;
				second_key = first_key;
				first_freq = cur->freq;
				first_key = cur->key;
			}
			else if(cur->freq > second_freq){
				second_freq = cur->freq;
				second_key = cur->key;
			}
			cur = cur->next;
		}
		return make_tuple(first_key, second_key);
	}

	void Clear(void){ 
		head_ = nullptr;
		return;
	}

};



int main(void){


	// token
	mmap token_map;
	mmap temp_map; // for read in meta

	// read in token manifest
	temp_map.Open("token_manifest");
	temp_map.Map("token_manifest_map");
	string token_manifest_str(temp_map.get_ptr());
	// de-serialize
	Manifest token_manifest(token_manifest_str);
	temp_map.Close(); // close disc map

	// refer to token text
	token_map.Open("token");
	token_map.Map("token_map");
	string token_str(token_map.get_str());
	// build up interface
	TextRefer ref_token;
	ref_token.set_manifest(&token_manifest);
	ref_token.set_text(&token_str);

	// token
	mmap text_map;

	// read in token manifest
	temp_map.Open("text_manifest");
	temp_map.Map("text_manifest_map");
	string text_manifest_str(temp_map.get_ptr());
	// de-serialize
	Manifest text_manifest(text_manifest_str);
	temp_map.Close(); // close disc map

	// refer to token text
	text_map.Open("text");
	text_map.Map("text_map");
	string text_str(text_map.get_str());
	// build up interface
	TextRefer ref_text;
	ref_text.set_manifest(&text_manifest);
	ref_text.set_text(&text_str);


	mmap map;
	map.Open("index");
	map.Map("index_map");
	char* index_ptr(map.get_ptr());
	IndexRefer index_ref(index_ptr);

	DB db("main.db");
	LocalTermTABLE lterm(&db);
	lterm.Init();
	GlobalTermTABLE gterm(&db);
	gterm.Init();
	PredictTABLE ptable(&db);
	ptable.Init();

	int size = kTermSize;

	LinkedList collector;

	string term;
	bitset<kPassageSize> index;
	for(int id = 1; id <= size; id++){
		term = get<0>(gterm.Query(id));
		index = index_ref.get_index(id);

		string first,second;
		string full;

		cout << endl << term << ":";

		for(int p_id = 1; p_id <= kPassageSize; p_id++){
			if(!index[p_id-1])continue;

			auto res = lterm.Query(term, p_id);
			int first = get<1>(res), last = get<2>(res);
			int s_id = first;
			string sentence;
			string next;
			int next_id;

			// get full
			sentence = ref_text.get_line(p_id, s_id);
			full = find(sentence, term);
			sentence = ref_token.get_line(p_id,s_id);
			if(full == string(""))full = term;

			// stat
			do{
				sentence = ref_token.get_line(p_id,s_id);
				if(sentence == string(""))break;
				next = find_next(sentence, term);
				if(next == string(""))continue;
				cout << next<<',';
				next_id = get<0>(gterm.Query(next));
				collector.Insert(next_id); // use id as hash
			}while(++s_id <= last);
		}

		auto res = collector.FindTwo();
		first = get<0>(gterm.Query( get<0>(res) ));
		second = get<0>(gterm.Query( get<1>(res) ));
		// ptable.Insert(term, full, first, second);
		collector.Clear();
	}
}
