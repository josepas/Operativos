#include "hilos.h"

void* HiloHoja(void* argumentoHilo) {

	struct datosHiloH* datos;
	datos = (struct datosHiloH*)argumentoHilo;

	int i;
	for (i = datos->inicio; i < datos->inicio + datos->nc; i++) {
		datos->resultado[i] =  EncrptCesar(datos->resultado[i]);
	}

	pthread_exit(NULL);
}


void* HiloIntermedio(void* argumentoHilo) {
	
	int i;
	long* ra;
		
	pthread_t* hilosH;

	long inicio;

	struct datosHiloI* datos;

	struct datosHiloH* arregloDatosH;

	datos = (struct datosHiloI*)argumentoHilo;

	ra = rangos(datos->nc, datos->nHijosH);

	hilosH = (pthread_t*)malloc(sizeof(pthread_t) * datos->nHijosH);
	arregloDatosH = (struct datosHiloH*)malloc(sizeof(struct datosHiloH) * datos->nHijosH);

	inicio = datos->inicio;
	for (i = 0; i < datos->nHijosH; i++) {

		arregloDatosH[i].resultado = datos->resultado;
		arregloDatosH[i].nc = ra[i];
		arregloDatosH[i].inicio = inicio;
		pthread_create(&hilosH[i], NULL, HiloHoja, (void *)&arregloDatosH[i]);
		inicio += ra[i];
		
	}

	for (i = 0; i < datos->nHijosH; i++) {
		pthread_join(hilosH[i], NULL);
	}	

	for (i = 0; i < datos->nc; i++) {
		datos->resultado[i] =  EncrptMurcielago(datos->resultado[i]);
		
	}


	pthread_exit(NULL);
}