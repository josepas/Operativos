#include "extras.h"

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