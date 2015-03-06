CC=gcc
CFLAGS=-g -Wall

all: usoDisco.o colaTrabajos.o 
	$(CC) $(CFLAGS) usoDisco.o colaTrabajos.o -o usoDisco

usoDisco.o: usoDisco.c
	$(CC) $(CFLAGS) -c usoDisco.c

colaTrabajos.o: colaTrabajos.c
	$(CC) $(CFLAGS) -c colaTrabajos.c

clean:
	rm -rf *.o usoDisco
