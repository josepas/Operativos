#include "extras.h"

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

long* rangos(long tamano, long nHijos) {
	
	long* r;
	long trabajo = tamano / nHijos;
	long resto = tamano % nHijos;

	r = (long*) malloc ( (long)sizeof(long) * nHijos);

	int i;
	for (i=0; i<nHijos; i++) { 
		r[i] = trabajo;
		if (resto > 0) {
			r[i]++;
			resto--;
		}
	}

	return r;

}

