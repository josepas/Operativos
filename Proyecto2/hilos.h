#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <pthread.h>
#include "algosEncriptacion.h"

struct datosHiloI {
	char entrada[25];
	char salida[25];
	int hiloId;
	int nHijosH;
	int nc;
	long inicio;

};

struct datosHiloH {
	char entrada[25];
	int hiloId;
	long inicio;
	int nc;

};

void* HiloHoja(void* argumentoHilo);

void* HiloIntermedio(void* argumentoHilo);