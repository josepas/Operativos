#include "hilos.h"

// Realiza el primer algoritmo de encriptacion/desencriptacion usando la estrategia 
// de hilos dependiendo del flag -c/-d.

void* HiloHoja(void* argumentoHilo) {

	int i;
	struct datosHiloH* datos;
	datos = (struct datosHiloH*)argumentoHilo;

	for (i = datos->inicio; i < datos->inicio + datos->nc; i++) {
		if ( datos->modo == 'c' ) {
			datos->resultado[i] =  EncrptCesar(datos->resultado[i]);
		} else if ( datos->modo == 'd') {
			datos->resultado[i] =  DesEnMurcielago(datos->resultado[i]);
		}
	}
	return(0);
}

// Crea hijos y luego concatena los resultados.

void* HiloIntermedio(void* argumentoHilo) {
	
	int i;
	int chequeo;
	long* ra;
	pthread_t* hilosH;
	long inicio;
	struct datosHiloI* datos;
	struct datosHiloH* arregloDatosH;

	datos = (struct datosHiloI*)argumentoHilo;

	ra = Rangos(datos->nc, datos->nHijosH);

	hilosH = (pthread_t*)malloc(sizeof(pthread_t) * datos->nHijosH);
	arregloDatosH = (struct datosHiloH*)malloc(sizeof(struct datosHiloH) * datos->nHijosH);

	inicio = datos->inicio;
	for (i = 0; i < datos->nHijosH; i++) {
		arregloDatosH[i].resultado = datos->resultado;
		arregloDatosH[i].nc = ra[i];
		arregloDatosH[i].modo = datos->modo;
		arregloDatosH[i].inicio = inicio;
		chequeo = pthread_create(&hilosH[i], NULL, HiloHoja, (void *)&arregloDatosH[i]);
		if (chequeo) {
			printf("Error al crear hilo.\n");
			exit(1);
		}
		inicio += ra[i];
	}

	for (i = 0; i < datos->nHijosH; i++) {
		pthread_join(hilosH[i], NULL);
	}	

	for (i = datos->inicio; i < datos->inicio + datos->nc; i++) {
		if ( datos->modo == 'c' ) {
			datos->resultado[i] = EncrptMurcielago(datos->resultado[i]);
		} else if ( datos->modo == 'd' ) {
			datos->resultado[i] = DesEnCesar(datos->resultado[i]);
		}
	}

	free(arregloDatosH);
	free(hilosH);
	free(ra);
	return(0);
}
