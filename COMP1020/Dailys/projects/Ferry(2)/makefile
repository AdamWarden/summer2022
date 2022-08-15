CC = gcc
CFLAGS = -Wall --std=c99
OBJECTS = main.o queue.o

all: queue

queue: $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o queue

main.o: main.c queue.c queue.h 
	$(CC) $(CFLAGS) -c main.c -o main.o 
queue.o: queue.c queue.h status.h
	$(CC) $(CFLAGS) -c queue.c -o queue.o

clean:
	rm queue $(OBJECTS)