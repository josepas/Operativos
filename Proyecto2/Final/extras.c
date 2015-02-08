#include "extras.h"

// Calcula cuanto tiene que trabajar cada hijo. 

long* Rangos(long tamano, long nHijos) {
	
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

// Toma el tiempo en que tarda trabajando.

int TomarTiempo() {
	struct timeval t;     
  	int dt;
  	gettimeofday ( &t, (struct timezone*)0 );
  	dt = (t.tv_sec)*1000000 + t.tv_usec;
 	return dt;
}     