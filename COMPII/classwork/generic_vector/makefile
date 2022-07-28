CC = gcc
CFLAGS = -Wall --std=c99
OBJECTS = main.o generic_vector.o

all: generic_vector

generic_vector: $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o generic_vector

main.o: main.c generic_vector.c generic_vector.h
	$(CC) $(CFLAGS) -c main.c -o main.o 
generic_vector.o: generic_vector.c generic_vector.h status.h
	$(CC) $(CFLAGS) -c generic_vector.c -o generic_vector.o

clean:
	rm generic_vector $(OBJECTS)