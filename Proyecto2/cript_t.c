#include "hilos.h"

int main(int argc, char const *argv[]) {
	
	FILE* archE;
	FILE* archS;
	
	pthread_t* hilosI;
	struct datosHiloI* arregloDatosI;
	int i;
	
	long nHijos;
	long inicio;
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

	hilosI = (pthread_t*)malloc(sizeof(pthread_t) * nHijos);
	arregloDatosI = (struct datosHiloI*)malloc(sizeof(struct datosHiloI) * nHijos);

	fseek(archE, 0, SEEK_END);
	long tamano = ftell(archE) - 1;
	rewind(archE);

	ra = rangos(tamano, nHijos);

	inicio = 0;
	for (i = 0; i < nHijos; i++) {
		arregloDatosI[i].hiloId = i;
		strcpy(arregloDatosI[i].entrada, argv[3]);
		strcpy(arregloDatosI[i].salida, argv[4]);
		arregloDatosI[i].nc = ra[i];
		arregloDatosI[i].nHijosH = nHijos;
		arregloDatosI[i].inicio = inicio;
		pthread_create(&hilosI[i], NULL, HiloIntermedio, (void *)&arregloDatosI[i]);
		inicio += ra[i];
	}

	
	fclose(archE);
	fclose(archS);
	pthread_exit(NULL);
}