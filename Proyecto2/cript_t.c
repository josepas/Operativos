#include "algosEncriptacion.h"
#include "extras.h"
#include "pthread.h"

struct datosHilo {
   int hola;
};

void* Funcion () {

}

int main(int argc, char const *argv[]) {
	
	FILE* archE;
	FILE* archS;
	
	pthread_t* hilos;
	struct datosHilo* arregloDatos;

	int i;

	long nHijos;
	long* ra;		//Numero de caracteres a procesar por hijo;


	if (argc != 5) {
		printf("llamada hecha incorrectamente.\n");
		printf("cript_p [-c/-d] <NumeroHijos> <archivoEntrada> <archivoSalida> \n");
		return 0;
	}

	archE = fopen(argv[3], "r");
	if (archE == 0) {
		printf("El archivo %s no existe\n", argv[3]);
		return 0;
	}

	archS = fopen(argv[4], "w");

	nHijos = atoi(argv[2]);

	hilos = (pthread_t*)malloc(sizeof(pthread_t) * nHijos);
	arregloDatos = (datosHilo*)malloc(sizeof(pthread_t) * nHijos);

	fseek(archE, 0, SEEK_END);
	long tamano = ftell(archE) - 1;

	ra = rangos(tamano, nHijos);

	for (i = 0; i < nHijos; ++i) {

		pthread_create(&hilos[i], NULL, Funcion, (void *)&arregloDatos[i]);
		
	}

	

	pthread_exit(NULL);
}