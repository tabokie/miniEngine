#ifndef DISC_MANIFEST_HELPER_HPP_
#define DISC_MANIFEST_HELPER_HPP_

#include <sstream>
#include <string>
#include <iostream>
#include <vector>

namespace disc_reader{

using namespace std;

struct manifest_meta{
	int id;
	size_t offset;
	vector<size_t> sentences;
	manifest_meta():id(-1){ }
	manifest_meta(int i, size_t o):id(i),offset(o){ }
	~manifest_meta(){ }

	void push(size_t item){sentences.push_back(item);}
};

// Serialize JSON manifest
// {"id" : i, "offset" : i, "sentences": [i,,]},
class Manifest{
	vector<manifest_meta> p_vec_;

 public:
 	Manifest() = default;
	Manifest(string str){
		Serialize(str);
	}
	~Manifest(){ }
	void Serialize(string str){
		size_t p_idx = 0;
		size_t obj_idx = 0;
		size_t end_idx = 0;
		int id;
		size_t offset;
		
		while(true){

			p_idx = str.find('{',p_idx); // parse passage obj
			if(p_idx == string::npos)break;
			// parse id
			obj_idx = str.find("id",p_idx);
			obj_idx = str.find(':',obj_idx);
			id = atoi(&str.c_str()[obj_idx+1]);
			p_idx = obj_idx;
			// parse offset
			obj_idx = str.find("offset",p_idx);
			obj_idx = str.find(':',obj_idx);
			offset = atoi(&(str.c_str()[obj_idx+1]));
			p_idx = obj_idx;
			// init meta
			manifest_meta m = manifest_meta(id,offset);
			// parse sentence
			obj_idx = str.find("sentences",p_idx);
			obj_idx = str.find('[',obj_idx)+1;
			end_idx = str.find(']',obj_idx)-1;
			istringstream sentence_s(str.substr(obj_idx, end_idx-obj_idx+1));
			string num;
			while(getline(sentence_s,num,',')){
				size_t temp ;
				istringstream(num) >> temp;
				m.push(temp);
			}
			p_idx = end_idx;
			// cout << "**" << m.sentences.size() << "* ";

			p_vec_.push_back(m);

			p_idx = str.find("},",p_idx);
		}
		// std::sort(p_vec_.begin(), p_vec_.end(),[]bool(manifest_meta a, manifest_meta b){return a.id < b.id;} )
	}
	void Put(void){
		for(auto p : p_vec_){
			cout << p.id << " " << p.offset << endl;
		}
	}
	size_t size(void){
		return p_vec_.size();
	}
	manifest_meta get_item(size_t idx){
		if(idx > p_vec_.size())return manifest_meta();
		return p_vec_[idx-1];
	}
};


} /* namespace disc_reader */

#endif /* DISC_MANIFEST_HELPER_HPP_ */