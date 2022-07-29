CC = gcc
CFLAGS = -Wall --std=c99
OBJECTS = main.o BIT_FLAGS_1.o

all: BIT_FLAGS_1

BIT_FLAGS_1: $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o BIT_FLAGS_1

main.o: main.c BIT_FLAGS_1.c BIT_FLAGS_1.h
	$(CC) $(CFLAGS) -c main.c -o main.o

BIT_FLAGS_1.o: BIT_FLAGS_1.c BIT_FLAGS_1.h
	$(CC) $(CFLAGS) -c BIT_FLAGS_1.c -o BIT_FLAGS_1.o

clean:
	rm BIT_FLAGS_1 $(OBJECTS)