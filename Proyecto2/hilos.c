#include "hilos.h"

void* HiloHoja(void* argumentoHilo) {


	FILE* archAux;
	struct datosHiloH* datos;
	fpos_t posPrevia;
  	
  	char c1; 

	datos = (struct datosHiloH*)argumentoHilo;

	archAux = fopen(datos->entrada, "r+");

	fseek(archAux, datos->inicio, SEEK_SET);
	
	int i;
	for (i = 0; i < datos->nc; i++) {

		fgetpos (archAux, &posPrevia);
  		c1 = EncrptCesar(fgetc(archAux));	
  		fsetpos (archAux, &posPrevia);
		fputc(c1, archAux);
	}
	fclose(archAux);
	pthread_exit(NULL);
}


void* HiloIntermedio(void* argumentoHilo) {
	
	int i;
	long* ra;
		
	pthread_t* hilosH;

	fpos_t posPrevia;

	FILE* archAux, *archS;

	long inicio;

	char c1;

	struct datosHiloI* datos;

	struct datosHiloH* arregloDatosH;

	datos = (struct datosHiloI*)argumentoHilo;

	ra = rangos(datos->nc, datos->nHijosH);

	hilosH = (pthread_t*)malloc(sizeof(pthread_t) * datos->nHijosH);
	arregloDatosH = (struct datosHiloH*)malloc(sizeof(struct datosHiloH) * datos->nHijosH);

	inicio = datos->inicio;
	for (i = 0; i < datos->nHijosH; i++) {

		arregloDatosH[i].hiloId = i;
		strcpy(arregloDatosH[i].entrada, datos->entrada);
		arregloDatosH[i].nc = ra[i];
		arregloDatosH[i].inicio = inicio;
		pthread_create(&hilosH[i], NULL, HiloHoja, (void *)&arregloDatosH[i]);
		inicio += ra[i];
		
	}

	for (i = 0; i < datos->nHijosH; i++) {
		pthread_join(hilosH[i], NULL);
	}	

	
	archAux = fopen(datos->entrada, "r+");
	fseek(archAux, datos->inicio, SEEK_SET);

	for (i = 0; i < datos->nc; i++) {
+
		fgetpos (archAux, &posPrevia);
  		c1 = EncrptMurcielago(fgetc(archAux));	
  		fsetpos (archAux, &posPrevia);
		fputc(c1, archAux);
	}

	pthread_exit(NULL);
}