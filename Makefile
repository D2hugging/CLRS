.PHONY : all clean

all : test

test : common.c list.c sort.c tree.c bit.c test.c
	gcc -g -Wall -std=c99 -o $@ $^

clean :
	rm -f test