CC = gcc
CFLAGS = -Wall --std=c99
OBJECTS = main.o stack.o

all: stack

stack: $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o stack

main.o: main.c stack.c stack.h
	$(CC) $(CFLAGS) -c main.c -o main.o 
stack.o: stack.c stack.h status.h
	$(CC) $(CFLAGS) -c stack.c -o stack.o

clean:
	rm stack $(OBJECTS)