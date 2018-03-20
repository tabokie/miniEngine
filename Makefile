INCLUDE = ./include
LIB = ./lib
DATA = ./data
SETUP = ./Setup

# engine build
# use main.cpp as 

all : main.o
	g++ -o main -I./include main.o -L./lib -lsqlite3 -lstem -std=c++11
main.o : main.cpp engine.hpp $(INCLUDE)/memmap.hpp $(INCLUDE)/disc_reader.hpp
	g++ -I./include -c main.cpp -std=c++11

setup : $(SETUP)/data/text, $(SETUP)/data/text_manifest, $(SETUP)/data/main.db, $(SETUP)/data/index

$(SETUP)/data/text, $(SETUP)/data/text_manifest, $(SETUP)/data/tokenizer_meta, $(SETUP)/data/raw_token : $(SETUP)/tokenizer/tokenizer.py
	python27 $(SETUP)/tokenizer/tokenizer.py

$(SETUP)/data/main.db : stat.exe
	stat.exe

stat.exe : $(SETUP)/data/token, $(SETUP)/data/token_manifest, $(SETUP)/data/tokenizer_meta
	g++ -o stat -I$(INCLUDE) -L$(LIB) -llibsqlite3 $(SETUP)/stat/stat.cpp -std=c++11

$(SETUP)/data/token, $(SETUP)/data/token_manifest : $(SETUP)/stemmer/stemmer.exe
	$(SETUP)/stemmer/stemmer.exe

$(SETUP)/stemmer/stemmer.exe : $(SETUP)/stemmer/stemmer.c
	gcc -o stemmer $(SETUP)/stemmer/stem_algorithm.c $(SETUP)/stemmer/api.c $(SETUP)/stemmer/stemmer.c $(SETUP)/stemmer/utilities.c

$(SETUP)/data/index : $(SETUP)/stat/indexer.cpp
	g++ -I$(INCLUDE) -L$(LIB) -llibsqlite3 $(SETUP)/stat/indexer.cpp -std=c++11

	
	