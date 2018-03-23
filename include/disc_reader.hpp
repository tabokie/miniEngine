#ifndef DISC_READER_HPP_
#define DISC_READER_HPP_

#include "manifest_helper.hpp" /* class Manifest */
#include "db_interface.hpp" /* kPassageSize, kTermSize */
#include "memmap.hpp"

#include <string>
#include <bitset>
#include <sstream> /* istringstream */
#include <cstring>

namespace disc_reader{

using namespace std;
using namespace db_interface; // use kPassageSize, kTermSize

// for get_line(id)
const size_t MAX_SENTENCE = 300;

// Refer to Text on disc //
class TextRefer{
	Manifest* manifest_; // store offset meta
	string* text_; // virtual text ptr mapped from disc
 public:
	TextRefer():manifest_(nullptr),text_(nullptr){ }
	~TextRefer(){ }
	void set_manifest(Manifest* m){
		manifest_ = m;
	}
	void set_text(string* s){
		text_ = s;
	}
	string get_line(int p_id, int s_id){
		// null reference
		if(!manifest_ || !text_)return string("");
		// invalid id request
		if(p_id > manifest_->size() || p_id <= 0){
			return string("");
		}
		// get sentence meta
		manifest_meta m = manifest_->get_item(p_id);
		// invalid sentence id request
		if(s_id > m.sentences.size() - 1 || s_id <= 0){ // size = num_of_sen + 1
			return string("");
		}
		// calc offset
		size_t offset = m.offset + m.sentences[s_id-1];
		size_t len = MAX_SENTENCE;
		if(m.sentences.size()<2)return string("");
		// get exact length of sentence
		if(s_id < m.sentences.size())len = m.sentences[s_id] - m.sentences[s_id-1] - 1;
		// make stream
		istringstream text_s(text_->substr(offset,len));
		string ret;
		// clip off line
		getline(text_s, ret, '\n');
		// return string
		return ret;
	}
}; /* class TextRefer */


// Refer to bitset index on disc //
class IndexRefer{

	char* index_; // virtual index ptr mapped from disc

 public:
 	IndexRefer(char* ptr = nullptr):index_(ptr){ }
 	~IndexRefer(){ }

 	// return bitset length of passageSize
 	bitset<kPassageSize> get_index(int t_id){
 		bitset<kPassageSize> bits; // all 0
 		if(t_id <= 0 || t_id > kTermSize || !index_)return bits; // return empty
 		// calc offset
 		char* ptr = (index_ + (kPassageSize / 8 + 1) * (t_id-1));
 		// copy mem to bitset object
 		memcpy((char*)&bits, ptr, sizeof(bits));
 		// return bitset
 		return bits;
 	}

}; /* class IndexRefer */

} /* namespace disc_reader */


#endif /* DISC_READER_HPP_ */