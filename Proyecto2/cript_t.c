#include "hilos.h"

int main(int argc, char const *argv[]) {
	
	FILE* archE;
	FILE* archS;

	char* resultado;
	
	pthread_t* hilosI;
	struct datosHiloI* arregloDatosI;
	int i;
	int c;
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

	resultado = (char *)malloc(tamano);
	i = 0;
	while ( (c = fgetc(archE)) != EOF ) {
		if (c != '\n') {
			resultado[i] = c;
		}
		i++;
	}

	fclose(archE);
	ra = rangos(tamano, nHijos);

	inicio = 0;
	for (i = 0; i < nHijos; i++) {
		arregloDatosI[i].hiloId = i;
		arregloDatosI[i].resultado = resultado;
		arregloDatosI[i].nc = ra[i];
		arregloDatosI[i].nHijosH = nHijos;
		arregloDatosI[i].inicio = inicio;
		pthread_create(&hilosI[i], NULL, HiloIntermedio, (void *)&arregloDatosI[i]);
		inicio += ra[i];
	}

	for (i = 0; i < nHijos; i++) {
		pthread_join(hilosI[i], NULL);
	}	


	for (i = 0; i < tamano; i++) {
		printf("%c", resultado[i]);
	}
	printf("\n");

	pthread_exit(NULL);
}