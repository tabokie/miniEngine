output = ../data/stemmed, ../data/token, ../data/token_manifest
object = stemmer.o utilities.o api.o stem_algorithm.o

output : stemmer
	stemmer.exe

stemmer : $(object)
	gcc -o stemmer $(object)

stemmer.o : stemmer.c
	gcc -c stem_algorithm.c api.c stemmer.c utilities.c

.PHONY : clean
clean :
	-rm stemmer.exe $(object)

