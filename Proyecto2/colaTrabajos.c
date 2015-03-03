#include "colaTrabajos.h"

ColaT* CrearColaT() {
	ColaT* c;
	c = (ColaT*)malloc(sizeof(ColaT));
	c->primero = NULL;
	c->ultimo = NULL;
	return c;
}

int esVaciaColaT(ColaT* c) {
	if ( c->primero == NULL ) {
		return 1;
	}
	return 0;
}

void EncolarT(ColaT* c, char* nuevo) {
	NodoC* nuevoC;
	nuevoC = (NodoC*)malloc(sizeof(NodoC));
	strcpy(nuevoC->archivo, nuevo);

	if ( c->primero == NULL ) {
		c->primero = nuevoC;
		c->ultimo = nuevoC;
	} else {

		c->ultimo->sig = nuevoC;
		c->ultimo = nuevoC;
	}
}

char* DesencolarT(ColaT* c) {
	char* buffer;
	NodoC* aux;

	if ( c->primero != NULL ) {
		
		
		aux = c->primero;
		buffer = aux->archivo;

		if ( c->primero == c->ultimo ) {
			c->ultimo = NULL;

		}	
		c->primero = c->primero->sig;
	}
	// ESTE FREE DA PROBLEMAS free(aux);
	return buffer;
}
