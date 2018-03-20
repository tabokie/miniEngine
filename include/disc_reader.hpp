#ifndef DISC_READER_HPP_
#define DISC_READER_HPP_

#include "manifest_helper.hpp"
#include "memmap.hpp"
#include "db_interface.hpp"


#include <string>
#include <bitset>
#include <fstream>
#include <cstring>

namespace disc_reader{

using namespace std;
using namespace db_interface;


const size_t MAX_SENTENCE = 300;

class TextRefer{
	Manifest* manifest_;
	string* text_;
 public:
	TextRefer() = default;
	~TextRefer(){ }
	void set_manifest(Manifest* m){
		manifest_ = m;
	}
	void set_text(string* s){
		text_ = s;
	}
	string get_line(int p_id, int s_id){
		if(p_id > manifest_->size() || p_id <= 0){
			return string("");
		}
		manifest_meta m = manifest_->get_item(p_id);
		if(s_id > m.sentences.size() - 1 || s_id <= 0){ // size = num_of_sen + 1
			return string("");
		}
		size_t offset = m.offset + m.sentences[s_id-1];
		size_t len = MAX_SENTENCE;
		if(m.sentences.size()<2)return string("");
		if(s_id < m.sentences.size())len = m.sentences[s_id] - m.sentences[s_id-1] - 1;
		istringstream text_s(text_->substr(offset,len));
		string ret;
		getline(text_s, ret, '\n');
		return ret;
	}
};


class IndexRefer{

	char* index_;

 public:
 	IndexRefer(char* ptr):index_(ptr){ }
 	~IndexRefer(){ }

 	bitset<kPassageSize> get_index(int t_id){
 		bitset<kPassageSize> bits;
 		char* ptr = (index_ + (kPassageSize / 8 + 1) * (t_id-1));
 		memcpy((char*)&bits, ptr, sizeof(bits));
 		return bits;
 	}

};

} /* namespace disc_reader */


#endif /* DISC_READER_HPP_ */