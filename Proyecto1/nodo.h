#ifndef NODO
#define NODO

#include "arista.h"

typedef struct Nodo {
	int valor;
	struct Arista *adyacentes;
	struct Nodo *sig;
} Nodo;


#endif