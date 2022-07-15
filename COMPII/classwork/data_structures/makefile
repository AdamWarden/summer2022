CC = gcc
CFLAGS = -Wall --std=99
OBJECTS = main.o 

all: stack_execute

stack_execute: $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o stack_execute

main.o: main.c stack.c stack.h
	$(CC) $(CFLAGS) -c main.c -o main.o 

clean:
	rm stack_execute $(OBJECTS)