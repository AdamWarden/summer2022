CC = gcc
CFLAGS = -Wall --std=c99
OBJECTS = program7.o stack.o

all: stack

stack: $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o stack

program7.o: program7.c linked_list_stack.c stack.h
	$(CC) $(CFLAGS) -c program7.c -o program7.o 
stack.o: linked_list_stack.c stack.h status.h
	$(CC) $(CFLAGS) -c linked_list_stack.c -o stack.o

clean:
	rm stack $(OBJECTS)