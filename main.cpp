#include "engine.hpp"

#include <iostream>
#include <algorithm>

using namespace std;
using namespace search_engine;

int main(int argc, char* argv[]){

	Engine* eng = new Engine(argv[1]);
	eng->Setup();
	string query;
	getline(cin, query);
	eng->Query(query);
	
	eng->Close();

	return 0;
}