#include "algosEncriptacion.h"

struct datosHiloI {
	int nHijosH;
	char* resultado;
	long inicio;
	long nc;
	char modo;
};

struct datosHiloH {
	char* resultado;
	long inicio;
	int nc;
	char modo;
};

void* HiloHoja(void* argumentoHilo);

void* HiloIntermedio(void* argumentoHilo);