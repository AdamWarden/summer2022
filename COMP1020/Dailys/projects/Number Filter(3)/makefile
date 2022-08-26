CC = gcc
CFLAGS = -Wall --std=c99
OBJECTS = main.o bit_flags.o

all: bit_flags

bit_flags: $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o bit_flags

main.o: main.c BIT_FLAGS_1.c BIT_FLAGS_1.h status.h
	$(CC) $(CFLAGS) -c main.c -o main.o

bit_flags.o: BIT_FLAGS_1.c BIT_FLAGS_1.h status.h
	$(CC) $(CFLAGS) -c BIT_FLAGS_1.c -o bit_flags.o

clean:
	rm bit_flags $(OBJECTS)