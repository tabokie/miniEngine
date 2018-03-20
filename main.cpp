#include "engine.hpp"

#include <iostream>
#include <algorithm>

using namespace std;
using namespace search_engine;

int main(void){

	Engine* eng = new Engine();
	eng->Setup();
	string query;
	while(true){
		getline(cin, query);
		eng->Query(query);
	}
	
	eng->Close();

	return 0;
}