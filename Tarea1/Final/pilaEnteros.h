/**
* @file	pilaEnteros.h
* @author	Jose Pascarella	<11-10743@usb.ve>
* @author 	Daniela Socas  	<11-10979@usb.ve>
* 
* @section Descripción
*
* Libreria para la estructura Pila de Enteros.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct NodoP {
	int valor;
	struct NodoP* sig;
} NodoP;

typedef struct Pila {
	struct NodoP* tope;
} Pila;

Pila* CrearPilaEnt();

void EmpilarEnt(Pila* p, int nuevo);

int PertenecePilaEnt(Pila* p, int buscado);

void DesempilarEnt(Pila* p);

void ImprimirAux(NodoP* actual);

void ImprimirPilaEnt(Pila* p);

