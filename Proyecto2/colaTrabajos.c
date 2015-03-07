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
	nuevoC->sig = NULL;
	strcpy(nuevoC->archivo, nuevo);

	if ( c->primero == NULL ) {
		c->primero = nuevoC;
		c->ultimo = nuevoC;
	} else {

		c->ultimo->sig = nuevoC;
		c->ultimo = nuevoC;
	}
}

char* TopeColaT(ColaT* c) {
	if (c != NULL) {
		return c->primero->archivo;
	}
	return NULL;
}

void DesencolarT(ColaT* c) {
	NodoC* aux;

	if ( c->primero != NULL ) {
		aux = c->primero;


		if ( c->primero == c->ultimo ) {
			c->ultimo = NULL;
		}	
		c->primero = c->primero->sig;
	}
	return;
	free(aux); // este free trae problemas
		
	
}

void ImprimirColaT(ColaT* c) {
	NodoC* aux;

	aux = c->primero;
	while (aux != NULL) {
		printf("COLA:::%s:::\n", aux->archivo);
		aux = aux->sig;
	}


}
