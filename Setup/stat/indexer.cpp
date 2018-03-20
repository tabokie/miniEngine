#include "db_interface.hpp"

#include <fstream>
#include <string>
#include <bitset>
#include <tuple>

using namespace std;
using namespace db_interface;

int main(void){

	DB db("../data/main.db");
	GlobalTermTABLE gterm(&db);
	gterm.Init();
	LocalTermTABLE lterm(&db);
	lterm.Init();

	ofstream fout("../data/index", ios::binary);
	for(int i=1;i<=kTermSize;i++){
		string term = get<0>(gterm.Query(i));
		cout << term << endl;
		bitset<kPassageSize> bits = lterm.FuzzyQuery(term);
		fout.write((char*)&bits, sizeof(bits));
	}
	fout.close();

	return 0;
}



