CC = gcc
CFLAGS = -Wall --std=c99
OBJECTS = program7.o stack.o

all: stack

stack: $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o stack

program7.o: program7.c stack.c stack.h
	$(CC) $(CFLAGS) -c program7.c -o program7.o 
stack.o: stack.c stack.h status.h
	$(CC) $(CFLAGS) -c stack.c -o stack.o

clean:
	rm stack $(OBJECTS)