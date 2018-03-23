#ifndef STEMMER_HPP_
#define STEMMER_HPP_

#include "api.h" // Snowball utilities
#include "stem_algorithm.h" // Snowball compiled algorithm
#include <cstdlib> // malloc(), free()
#include <string> // string

class Stemmer{

	struct SN_env * env_;

 public:

	Stemmer(){
		Init();
	}
	~Stemmer(){
		Close();
	}
	// read in input word as string
	// output stemmed term as string
	std::string Stem(std::string in){
		// put char in string into built-in container 'symbol'
		symbol * b = (symbol*)malloc(sizeof(char)*in.size());
		for(int i = 0; i<in.size(); i++)b[i] = in[i];
		// send to stem algorithm
		SN_set_current(env_, in.size(), b);
		// activate stemming
		stem(env_);
		// fetch stemmed from env output
		char ret[env_->l+1];
		for(int i = 0; i<env_->l; i++)ret[i] = env_->p[i];
		ret[env_->l] = '\0';
		// release symbol
		free(b);
		// return string from char*
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