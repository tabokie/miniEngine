# miniEngine

## Set-up Procedure

* **Basic IO support**

Using Memory Mapping tech on OS

see file `./include/memmap.hpp`

* **Web to text : python parser**

`./Setup/tokenizer/tokenizer.py`

Using regex to parse url link in web's html, in order to traverse in father link (index -> book page -> section page)

Using BeautifulSoup module to get raw text from html form.

**procedure** : traverse -> clip off irrelevent -> write passage name and id to file `tokenizer_meta` -> write text in sentence to file `text` -> write offset infomation to file `text_manifest` -> tokenize (make Upper to Lower, clip off symbol) -> write tokens in sentence to file `raw_token`

* **Token to term(stemmed)**

`./Setup/stemmer/stemmer.c`

Using Snowball compiler to translate simple rules in `my_stem.sbl` to C program in file `stem_algorithm.c`, later packed into MinGW lib `./lib/libstem.a`


**Procedure** : make rules (**add** irregular verb and antient english word to snowball standard rules) -> compile to C -> use stemmer to stem token in file `raw_token` -> write term and offset information to file `token` and `token_manifest`

* **statistic operation on term**

`./Setup/stat/stat.cpp`

Using SQLite to store statistical information, packed into `./lib/libsqlite3.a`

**Procedure** : Open data_in {tokenizer_meta{passage id, passage name}, token{terms}, token_manifest{offset of file token}}, Open data_out {database{Three table used, see `./include/db_interface.hpp`}} 

-> parse passage id and name from file -> write to PassageTABLE

-> stat term frequency in passage, using TrieTree -> write to LocalTermTABLE

-> Using SQL to stat term frequency in whole doc -> write to GlobalTermTABLE

* **indexer**

`./Setup/stat/indexer.cpp`

Using Bitset to store fixed-length index (bad practice for large scale indexing)

**Procedure** : Use Database

**Improvements** : 

first, weakness of fixed bitmap : too long when passage grows, hard to modify passage change

second, improve solution: Distributed Bitset Index

**1**. compress bitset, 0000001100000111 -> 6(0)+11+5(0)+111 -> |0|110| 11 |0|101| 111

the compress length (3 in this case) affect compress rate

simple to append

**2**. distributedly store bitset to files {meta, term0,bitset0, term1,bitset1 ...}

to insert, maintain freelist.

to retrive, first identify the file: using BloomFilter(see online)(in which case meta have to store string for bloom) or Using overall hash/database

second identify the slot: using local hash

* **Predictor**

`./Setup/stat/predictor.cpp`

N-gram model, bad performance, abandoned

## Runtime

`./engine.hpp`

data_in : index(`./include/disc_reader.hpp`), text(to show abstract)(`./include/disc_reader.hpp`), database(to calc weight)(`./include/db_interface.hpp`) 

data_out : ranked {title, link, first presence sentence}

**Procedure** : query in form of string 

->(parse) terms(with NOT operation identified) 

->(database) term ids 

->(IndexRefer, offset=id\*x) bitset 

->(from bit to id vector) index vector 

->(using weight formula) ranking // see comment of get_weight, Check other rsc

-> sort 

->(textRefer and database for title) output

