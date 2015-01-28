CC=gcc
CFLAGS=-g -Wall
EXEC=tarea

all: main.o grafo.o pilaEnteros.o
	$(CC) $(CFLAGS) -o $(EXEC) main.o grafo.o pilaEnteros.o 

main.o: main.c grafo.o pilaEnteros.o
	$(CC) $(CFLAGS) -c main.c grafo.c pilaEnteros.c

grafo.o: grafo.c pilaEnteros.o
	$(CC) $(CFLAGS) -c grafo.c pilaEnteros.c 

pilaEnteros.o: pilaEnteros.c
	$(CC) $(CFLAGS) -c pilaEnteros.c

clean:
	rm *.o $(EXEC)

