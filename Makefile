CC = gcc
CFLAGS = -std=c11 -Wall -Wextra -Werror -pedantic

all: demo

demo: dynarray.c main.c dynarray.h
	$(CC) $(CFLAGS) dynarray.c main.c -o demo

test: dynarray.c test_dynarray.c dynarray.h
	$(CC) $(CFLAGS) dynarray.c test_dynarray.c -o test_dynarray
	./test_dynarray

clean:
	rm -f demo test_dynarray

.PHONY: all test clean
