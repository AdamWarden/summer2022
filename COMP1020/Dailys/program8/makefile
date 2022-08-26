CC = gcc
CFLAGS = -Wall --std=c99
OBJECTS = main.o pqueue.o

all: pqueue

pqueue: $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o pqueue

main.o: main.c priority_queue.c priority_queue.h
	$(CC) $(CFLAGS) -c main.c -o main.o 
pqueue.o: priority_queue.c priority_queue.h 
	$(CC) $(CFLAGS) -c priority_queue.c -o pqueue.o

clean:
	rm pqueue $(OBJECTS)