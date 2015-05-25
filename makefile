CC=gcc
CFLAGS=-Wall -std=c11 -ftrapv -O1 -ggdb
DEPS=stack.h

%.o: %.c $(DEPS)

test: test.o stack.o
	$(CC) $(CFLAGS) -o test test.o stack.o

all: test
