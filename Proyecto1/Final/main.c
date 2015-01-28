/**

* @file main.c
* @author	Jose Pascarella	<11-10743@usb.ve>
* @author 	Daniela Socas  	<11-10979@usb.ve>
* 
* @section Descripción
*
* Programa que calcula los caminos entre una estacion de bomberos (nodo inicio)
* y el lugar de un incendio (nodo llegada)
*/

#include "grafo.h"


int main(int argc, char const *argv[]) {
	
	FILE* archE;	

	Grafo* g;

	int destino, ini, fin; 	
	int caso = 1;
	ini = 1;

	if (argc != 2) {
		printf("%s\n", "La llamada debe hacerse con un y solo un parametro");
		return 0;
	}

	archE = fopen(argv[1], "r");
	if (archE == 0) {
		printf("El archivo %s no existe\n", argv[1]);
		return 0;
	}

	while ( fscanf(archE, "%d", &destino)  != EOF ) {
				
		g = CrearGrafo();
		while (ini != 0) {
			fscanf(archE, "%d %d", &ini, &fin);
			if ( ini != 0 ) {
				AgregarPar(g, ini, fin);
			}
		}
		printf("CASO %d:\n", caso++);
		printf("Hay %d rutas desde la estacion hasta la esquina %d.\n", dfs(g, destino), destino);
		
		DestructorGrafo(g);
		ini = 1;
	}
	fclose(archE);
	return 0;
}