#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <dirent.h> 



typedef struct NodoC {
	char archivo[2048];
	struct NodoC* sig;
} NodoC;

typedef struct ColaT {
	NodoC* primero;
	NodoC* ultimo;
} ColaT;

ColaT* CrearColaT();

void EncolarT(ColaT* c, char* nuevo);

int esVaciaColaT(ColaT* c);

char* DesencolarT(ColaT* c);

