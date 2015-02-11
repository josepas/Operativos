CC=gcc
CFLAGS=-g -Wall
EXEC1=cript
EXEC2=cript_p
EXEC3=cript_t

all: algosEncriptacion.o extras.o procesos.o hilos.o cript.o cript_p.o cript_t.o 
	$(CC) $(CFLAGS) cript.o algosEncriptacion.o extras.o -o $(EXEC1)
	$(CC) $(CFLAGS) cript_p.o algosEncriptacion.o extras.o procesos.o -o $(EXEC2)
	$(CC) $(CFLAGS) -pthread cript_t.o hilos.o algosEncriptacion.o extras.o  -o $(EXEC3)

cript_t.o: cript_t.c
	$(CC) $(CFLAGS) -c cript_t.c

cript_p.o: cript_p.c
	$(CC) $(CFLAGS) -c cript_p.c

cript.o: cript.c
	$(CC) $(CFLAGS) -c cript.c

procesos.o: procesos.c
	$(CC) $(CFLAGS) -c procesos.c	

hilos.o: hilos.c 
	$(CC) $(CFLAGS) -c hilos.c 

algosEncriptacion.o: algosEncriptacion.c
	$(CC) $(CFLAGS) -c algosEncriptacion.c

extras.o:
	$(CC) $(CFLAGS) -c extras.c	

clean:
	rm *.o $(EXEC1) $(EXEC2) $(EXEC3)