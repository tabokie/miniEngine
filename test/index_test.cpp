#include "disc_reader.hpp"

#include <iostream>

using namespace std;
using namespace disc_reader;
using namespace win_mmap;
using mmap = MemMap;


mmap* index_map_;
IndexRefer* index_;

void openIndex_(void){
	index_map_ = new mmap("E:/code/C++/ADS/P2/data/index");
	index_map_->Map("index_map");
	char* index_ptr(index_map_->get_ptr());
	index_ = new IndexRefer(index_ptr);
}

int main(void){

	openIndex_();
	int id;

	while(true){
		cin >> id;
		auto x = index_->get_index(id);
		for(int i = 0;i<888;i++){
			if(x[i]){
				cout << i+1 << " " << flush;
 			}
		}
	}

	

	return 0;
}