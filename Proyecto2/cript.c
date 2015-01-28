#include "algosEncriptacion.h"
#include "algosDesencriptacion.h"

int main(int argc, char const *argv[]) {
	
	FILE* archE;
	FILE* archS;
	int c;

	if (argc != 4) {
		printf("llamada hecha incorrectamente.\n");
		printf("cript [-c/-d] <archivoEntrada> <archivoSalida> \n");
		return 0;
	}

	archE = fopen(argv[2], "r");
	if (archE == 0) {
		printf("El archivo %s no existe\n", argv[2]);
		return 0;
	}

	archS = fopen(argv[3], "w");

	if (argv[1][1] == 'c') {

		while ( (c = fgetc(archE)) != EOF) {
			if ( c != ' ' && c != '\n') {
				fprintf(archS, "%c",  EncrptMurcielago( EncrptCesar(c) ) );
	    	}
	    }
	
	} else if (argv[1][1] == 'd') {
	    
	    while ( (c = fgetc(archE)) != EOF ) {
	       	fprintf(archS, "%c", DesEnCesar( DesEnMurcielago(c) ) );
	    }
	}
		
    fclose(archE);
    fclose(archS);

	return 0;
}