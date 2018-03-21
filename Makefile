INCLUDE = ./include
LIB = ./lib
DATA = ./data
SETUP = ./Setup
# engine build
all : main.o
	clang++ -o main -I./include main.o -L./lib -lsqlite3 -lstem -lpthread -ldl -std=c++11
main.o : main.cpp engine.hpp $(INCLUDE)/memmap.hpp $(INCLUDE)/disc_reader.hpp $(LIB)/libstem.a $(LIB)/libsqlite3.a
	clang++ -I./include -c main.cpp -std=c++11
$(LIB)/libstem.a : $(LIB)/stem/stem_algorithm.o $(LIB)/stem/api.o $(LIB)/stem/utilities.o
	ar -rv $(LIB)/libstem.a $(LIB)/stem/api.o $(LIB)/stem/stem_algorithm.o $(LIB)/stem/utilities.o

$(LIB)/stem/stem_algorithm.o : $(LIB)/stem/stem_algorithm.c
	g++ -c $(LIB)/stem/stem_algorithm.c -o $(LIB)/stem/stem_algorithm.o
$(LIB)/stem/api.o : $(LIB)/stem/api.c
	g++ -c $(LIB)/stem/api.c -o $(LIB)/stem/api.o
$(LIB)/stem/utilities.o : $(LIB)/stem/utilities.c
	g++ -c $(LIB)/stem/utilities.c -o $(LIB)/stem/utilities.o

$(LIB)/libsqlite3.a : $(LIB)/sqlite3/sqlite3.o $(LIB)/sqlite3/shell.o
	ar -rv $(LIB)/libsqlite3.a $(LIB)/sqlite3/sqlite3.o $(LIB)/sqlite3/shell.o
$(LIB)/sqlite3/sqlite3.o : $(LIB)/sqlite3/sqlite3.c
	gcc -c $(LIB)/sqlite3/sqlite3.c -o $(LIB)/sqlite3/sqlite3.o
$(LIB)/sqlite3/shell.o : $(LIB)/sqlite3/shell.c
	gcc -c $(LIB)/sqlite3/shell.c -o $(LIB)/sqlite3/shell.o

.PHONY
clean : 
	-rm main.o $(LIB)/stem/stem_algorithm.o $(LIB)/stem/api.o $(LIB)/stem/utilities.o \
	$(LIB)/sqlite3/sqlite3.o $(LIB)/sqlite3/shell.o

# setup : $(SETUP)/data/text, $(SETUP)/data/text_manifest, $(SETUP)/data/main.db, $(SETUP)/data/index

# $(SETUP)/data/text, $(SETUP)/data/text_manifest, $(SETUP)/data/tokenizer_meta, $(SETUP)/data/raw_token : $(SETUP)/tokenizer/tokenizer.py
# 	python27 $(SETUP)/tokenizer/tokenizer.py

# $(SETUP)/data/main.db : stat.exe
# 	stat.exe

# stat.exe : $(SETUP)/data/token, $(SETUP)/data/token_manifest, $(SETUP)/data/tokenizer_meta
# 	g++ -o stat -I$(INCLUDE) -L$(LIB) -llibsqlite3 $(SETUP)/stat/stat.cpp -std=c++11

# $(SETUP)/data/token, $(SETUP)/data/token_manifest : $(SETUP)/stemmer/stemmer.exe
# 	$(SETUP)/stemmer/stemmer.exe

# $(SETUP)/stemmer/stemmer.exe : $(SETUP)/stemmer/stemmer.c
# 	gcc -o stemmer $(SETUP)/stemmer/stem_algorithm.c $(SETUP)/stemmer/api.c $(SETUP)/stemmer/stemmer.c $(SETUP)/stemmer/utilities.c

# $(SETUP)/data/index : $(SETUP)/stat/indexer.cpp
# 	g++ -I$(INCLUDE) -L$(LIB) -llibsqlite3 $(SETUP)/stat/indexer.cpp -std=c++11

	
	