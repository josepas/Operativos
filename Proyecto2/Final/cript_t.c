#include "hilos.h"

int main(int argc, char const *argv[]) {
	
	FILE* archE;
	FILE* archS;

	char* resultado;
	int chequeo;
 	pthread_t* hilosI;
	struct datosHiloI* arregloDatosI;
	int i, c, TF, TI;
	long nHijos;
	long inicio;
	long* nc;		//Numero de caracteres a procesar por hijo;

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

	nHijos = atoi(argv[2]);

	hilosI = (pthread_t*)malloc(sizeof(pthread_t) * nHijos);
	arregloDatosI = (struct datosHiloI*)malloc(sizeof(struct datosHiloI) * nHijos);

	TI = TomarTiempo();
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

	nc = Rangos(tamano, nHijos);

	inicio = 0;
	for (i = 0; i < nHijos; i++) {
		arregloDatosI[i].resultado = resultado;
		arregloDatosI[i].modo = argv[1][1];
		arregloDatosI[i].nc = nc[i];
		arregloDatosI[i].nHijosH = nHijos;
		arregloDatosI[i].inicio = inicio;
		chequeo = pthread_create(&hilosI[i], NULL, HiloIntermedio, (void *)&arregloDatosI[i]);
		if (chequeo) {
			printf("Error al crear hilo.\n");
			exit(1);
		}
		inicio += nc[i];
	}

	for (i = 0; i < nHijos; i++) {
		pthread_join(hilosI[i], NULL);
	}	
	archS = fopen(argv[4], "w");

	for (i = 0; i < tamano; i++) {
		if (resultado[i] != ' ' && resultado[i] != '\n') {
			fprintf(archS, "%c", resultado[i]);
		}
	}
	fprintf(archS, "\n");
	fclose(archS);
	TF = TomarTiempo();
	printf("El Encriptado/Decriptado con hilos tardo: %i\n", TF-TI);

	free(resultado);
	free(hilosI);
	free(arregloDatosI);
	free(nc);	
	return(0);
}