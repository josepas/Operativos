/**
* @file grafo.c
* @author	Jose Pascarella	<11-10743@usb.ve>
* @author 	Daniela Socas  	<11-10979@usb.ve>
* 
* @section Descripción
*
* Libreria que contiene la implementacion de un TAD Grafo
*/

#include "grafo.h"

/**
* Constructor de la estructura grafo
* @return apuntador al nuevo grafo creado
* 
*/
Grafo* CrearGrafo() {
	Grafo* g;
	g = (Grafo*)malloc(sizeof(Grafo));
	g->primero = NULL;
	return g;
}

/**
* Libera la memoria usada por la estructura.
* @param apuntador al grafo a liberar
* @return void
* 
*/
void DestructorGrafo(Grafo* g) {
	Nodo* actualN;
	Nodo* sigN;
	
	Arista* actualA;
	Arista* sigA;

	actualN = g->primero;

	while (actualN != NULL) {
		actualA = actualN->adyacentes;
		while (actualA != NULL) {
			sigA = actualA->sig;
			free(actualA);
			actualA = sigA;
		}
		sigN = actualN->sig;
		free(actualN);
		actualN = sigN;
	}
	free(g);
}

/**
* Verifica la existencia de un nodo en el grafo
* @param apuntador al grafo.
* @param identificador del nodo a buscar.
* @return apuntador al nodo encontrado o NULL si no existe
* 
*/
Nodo* ExisteNodo(Grafo* g, int buscado) {
	if ( g->primero == NULL ) {
		return NULL;
	}
	Nodo* actual;
	actual = g->primero;
	
	while (actual != NULL) {
		
		if (actual->valor == buscado) {
			return actual;
		}
		actual = actual->sig;
	}
	return NULL;
}

/**
* Agrega un Nodo al Grafo
* @param apuntador al grafo a expandir
* @param identificador del nodo a agregar
* @return void
* 
*/
void AgregarNodo(Grafo* g, int valor) {
	Nodo* nuevo;
	nuevo = (Nodo*)malloc(sizeof(Nodo));

	nuevo->valor = valor;
	nuevo->adyacentes = NULL;

	nuevo->sig = g->primero;
	g->primero = nuevo;
	
}

/**
* Agrega una Arista al grafo
* @param apuntador al grafo
* @param apuntador al nodo ya creado de inicio de la arista
* @param apuntador al nodo ya creado de llegada de la arista
* @return void
* 
*/
void AgregarArista(Grafo* g, Nodo* inicio, Nodo* llegada) {
	Arista* nueva;
	nueva = (Arista*)malloc(sizeof(Arista));
	
	nueva->sig = inicio->adyacentes;
	nueva->conecta = llegada;

	inicio->adyacentes = nueva;

}

/**
* Agrega la dupla de nodos y los conecta mediante la arista
* @param apuntador al grafo
* @param nodo inicio de la arista
* @param nodo llegada de la arista
* @return void
* 
*/
void AgregarPar(Grafo* g, int valor, int conecta) {
	Nodo* inicio;
	Nodo* llegada;

	inicio = ExisteNodo(g, valor);
	llegada = ExisteNodo(g, conecta);

	if ( inicio == NULL ) {
		AgregarNodo(g,valor);
		inicio = ExisteNodo(g, valor);
	}
	if ( llegada == NULL ) {
		AgregarNodo(g, conecta);
		llegada = ExisteNodo(g, conecta);
	}

	AgregarArista(g, inicio, llegada);
	AgregarArista(g, llegada, inicio);
}

/**
* Proceso auxiliar recursivo que aplica DFS sobre nodos
* @param apuntador al nodo actual del DFS
* @param apuntador a la pila donde se van guardando los resultados
* @param entero que indica el nodo buscado por el DFS
* @return el numero de caminos posibles hasta el destino.
* 
*/
int dfsNodo(Nodo* inicio, Pila* p, int destino) {
	int co = 0;

	EmpilarEnt(p, inicio->valor);

	if ( inicio->valor == destino ) {
		ImprimirPilaEnt(p);
		DesempilarEnt(p);
		return 1;
	}
	if ( inicio->adyacentes == NULL ) {
		DesempilarEnt(p);
		return 0;
	}

	Arista* aux;
	aux = inicio->adyacentes;
	while (aux != NULL) {
		if ( PertenecePilaEnt(p, aux->conecta->valor) == 0 ) {
			co += dfsNodo(aux->conecta, p, destino);
		}
		aux = aux->sig;
	}
	DesempilarEnt(p);
	return co;
}

/**
* Proceso que invoca el dfs desde un apuntador a grafo.
* @param apuntador al grafo.
* @param entero identificador del nodo destino
* @return el numero de caminos hasta el nodo destino
* 
*/
int dfs(Grafo* g, int destino) {
	Nodo* inicio;
	Pila* p;
	int co = 0;
	p = CrearPilaEnt();

	inicio = ExisteNodo(g, 1);

	co = dfsNodo(inicio, p, destino);
	free(p);
	return co;
}





