/**
* @file	grafo.h
* @author	Jose Pascarella	<11-10743@usb.ve>
* @author 	Daniela Socas  	<11-10979@usb.ve>
* 
* @section Descripción
*
* Libreria para la estructura Grafo.
*/

#include "pilaEnteros.h"

struct Nodo;

typedef struct Arista {
	struct Nodo* conecta;
	struct Arista *sig;
} Arista;

typedef struct Nodo {
	int valor;
	struct Arista* adyacentes;
	struct Nodo* sig;
} Nodo;

typedef struct Grafo_ {
	Nodo* primero;
} Grafo;


Grafo* CrearGrafo();

void DestructorGrafo(Grafo* g);

Nodo* ExisteNodo(Grafo* g, int buscado);

void AgregarNodo(Grafo* g, int valor);

void AgregarArista(Grafo* g, Nodo* inicio, Nodo* llegada);

void AgregarPar(Grafo* g, int valor, int conecta);

int dfsNodo(Nodo* inicio, Pila* p, int destino);

int dfs(Grafo* g, int destino);








