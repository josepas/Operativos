#include "procesos.h"

// Realiza el primer algoritmo de encriptacion/desencriptacion usando la estrategia 
// de procesos dependiendo del flag -c/-d.

void ProcesoHoja(int inicio, int nc, pid_t pid, char* entrada, char modo) {
	FILE* salida;
	FILE* auxEntrada;
	char aux[20];

	sprintf(aux, "%d.txt" ,pid);

	auxEntrada = fopen(entrada, "r");
	salida = fopen(aux, "w");

	fseek(auxEntrada, inicio, SEEK_SET);

	int i;
	for (i=0; i < nc; ++i) {
		if ( modo == 'c' ) {
			fprintf(salida, "%c", EncrptCesar(fgetc(auxEntrada)));
		} else if (modo == 'd') {
			fprintf(salida, "%c", DesEnMurcielago(fgetc(auxEntrada)));
		}
	}
	fprintf(salida, "\n");
	fclose(auxEntrada);
	fclose(salida);
}

// Crea hijos y luego concatena los resultados.

void ProcesoIntermedio(pid_t* hijosH, int nHijos, char modo) {
	FILE* archAuxE;
	FILE* archAuxS;
	char aux[20];
	char aux1[20];
	int c;
	int estado;

	sprintf(aux, "%d.txt" ,getpid() );
	archAuxS = fopen( aux, "w");

	int j;
	for (j=0; j<nHijos; j++) {
		
		waitpid(hijosH[j], &estado, 0);					
		sprintf(aux1, "%d.txt", hijosH[j]);

		archAuxE = fopen( aux1, "r");
	
		while ( (c = fgetc(archAuxE)) != EOF ) {
			if (c != '\n') {
				if (modo == 'c') {
   					fprintf(archAuxS, "%c", EncrptMurcielago(c));
   				} else if (modo == 'd') {
   					fprintf(archAuxS, "%c", DesEnCesar(c));
   				}
			}
		}
		fclose(archAuxE);
		remove(aux1);
	}
	fprintf(archAuxS, "\n");
	fclose(archAuxS);
}

// Concatena los resultados de los hijos intermedios. 

void ConcatResultado(pid_t* hijosI, int nHijos, FILE* archS) {
	
 	FILE* archAuxE;
	int estado;
	int i,c;
	char aux[20];
 	
	for (i=0;i<nHijos; i++) {

		waitpid(hijosI[i], &estado, 0);
		sprintf(aux, "%d.txt", hijosI[i]);

		archAuxE = fopen(aux, "r");
		while ( (c = fgetc(archAuxE)) != EOF ) {
			if (c != '\n' && c != ' ') {
   				fprintf(archS, "%c", c);
			}
		}
		fclose(archAuxE);
		remove(aux);
	}
	fprintf(archS, "\n");
}

