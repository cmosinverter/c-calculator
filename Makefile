CC = gcc
CFLAGS = -Wall -O2 -g

all: calculator

calculator: calculator.o stack.o
	$(CC) $(CFLAGS) -o calculator calculator.o stack.o

calculator.o: calculator.c
	$(CC) $(CFLAGS) -c calculator.c

stack.o: stack.c stack.h
	$(CC) $(CFLAGS) -c stack.c

.PHONY: clean
clean:
	rm -f myprogram *.o