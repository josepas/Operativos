CC=gcc
CFLAGS=-g -Wall
EXEC1=cript
EXEC2=cript_p
EXEC3=cript_t

all: algosDesencriptacion.o algosEncriptacion.o cript.o
	$(CC) $(CFLAGS) cript.o algosEncriptacion.o algosDesencriptacion.o -o $(EXEC1)

cript.o: cript.c
	$(CC) $(CFLAGS) -c cript.c

algosDesencriptacion.o: algosDesencriptacion.c
	$(CC) $(CFLAGS) -c algosDesencriptacion.c	

algosEncriptacion.o: algosEncriptacion.c
	$(CC) $(CFLAGS) -c algosEncriptacion.c

clean:
	rm *.o $(EXEC1)