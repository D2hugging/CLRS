.PHONY : all clean

all : test

test : ds.c
	gcc -g -Wall -std=c99 -o $@ $^

clean :
	rm -f test