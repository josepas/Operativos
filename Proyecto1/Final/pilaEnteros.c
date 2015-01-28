/**
* @file	pilaEnteros.c
* @author	Jose Pascarella	<11-10743@usb.ve>
* @author 	Daniela Socas  	<11-10979@usb.ve>
* 
* @section Descripción
*
* Libreria para la estructura Pila de Enteros.
*/

#include "pilaEnteros.h"


/**
* Crea una Pila de enteros vacia
* @return apuntador a la nueva pila creada
* 
*/
Pila* CrearPilaEnt() {
	Pila* p;
	p = (Pila*)malloc(sizeof(Pila));
	p->tope = NULL;
	return p;
}

/**
* Agrega un elemento a la pila
* @param apuntador a la pila
* @param nuevo entero a agregar a la pila
* @return void
* 
*/
void EmpilarEnt(Pila* p, int nuevo) {
	NodoP* nuevoNP;
	nuevoNP = (NodoP*)malloc(sizeof(NodoP));
	nuevoNP->valor = nuevo;

	nuevoNP->sig = p->tope;
	p->tope = nuevoNP;
}

/**
* Verifica por la existencia de un entero en la pila
* @param apuntador a la pila
* @param entero buscado
* @return 0 => no existe el entero en la pila
*         1 => existe el entero en la pila
*/
int PertenecePilaEnt(Pila* p, int buscado) {
	NodoP* actual;
	actual = p->tope;

	while ( actual != NULL ) {
		if ( actual->valor == buscado ) {
			return 1;
		}
		actual = actual->sig;
	}
	return 0;
}

/**
* Elimina y libera la memoria ocupada por un elemento de la pila
* @param apuntador a la pila
* @return void
* 
*/
void DesempilarEnt(Pila* p) {
	NodoP* aux;

	if (p == NULL) {
		return;
	}
	aux = p->tope;
	p->tope = p->tope->sig;
	free(aux);
}

/**
* Imprime los elementos de una pila de Enteros
* @param Nodo actual a imprimir
* @return void
* 
*/
void ImprimirAux(NodoP* actual) {
	if ( actual == NULL ) {
		return;
	}
	ImprimirAux(actual->sig);
	printf("%d ", actual->valor);
}

/**
* Imprime los elementos de la pila.
* @param apuntador a la pila
* @return void
* 
*/
void ImprimirPilaEnt(Pila* p) {
	ImprimirAux(p->tope);
	printf("\n");
}

