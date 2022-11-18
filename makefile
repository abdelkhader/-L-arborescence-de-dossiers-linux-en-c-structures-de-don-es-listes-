treetest: treetest.o mylib/libmylib.a
	cc -o $@ treetest.o -Lmylib -lmylib

treetest.o: treetest.c mylib/mylib.h
	cc -c -Wall treetest.c 
