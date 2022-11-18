libmylib.a: structure.o load.o search.o parse.o
	ar -rs $@ structure.o load.o search.o parse.o 


structure.o: structure.c mylib.h
	cc -c structure.c mylib.h

load.o: load.c mylib.h
	cc -c load.c mylib.h
search.o: search.c mylib.h
	cc -c search.c mylib.h

parse.o: parse.c mylib.h
	cc -c parse.c mylib.h
