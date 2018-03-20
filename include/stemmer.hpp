#ifndef STEMMER_HPP_
#define STEMMER_HPP_


#include "api.h"
#include "stem_algorithm.h"
#include <cstdlib>
#include <string>

class Stemmer{

	struct SN_env * env_;

 public:

	Stemmer(){
		Init();
	}
	~Stemmer(){
		Close();
	}
	std::string Stem(std::string in){
		symbol * b = (symbol*)malloc(sizeof(char)*in.size());
		for(int i = 0; i<in.size(); i++)b[i] = in[i];
		SN_set_current(env_, in.size(), b);
		stem(env_);
		char* ret = new char[env_->l+1];
		for(int i = 0; i<env_->l; i++)ret[i] = env_->p[i];
		ret[env_->l] = '\0';
		free(b);
		return std::string(ret);
	}
	inline void Init(void){
		env_ = create_env();
	}
	inline void  Close(void){
		close_env(env_);
	} 

};


#endif /* STEMMER_HPP_ */