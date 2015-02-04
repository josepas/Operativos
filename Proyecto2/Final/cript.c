#include "algosEncriptacion.h"

int main(int argc, char const *argv[]) {
	
	FILE* archE;
	FILE* archS;
	int c;
	int TI, TF;

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

	TI = TomarTiempo();
	if (argv[1][1] == 'c') {

		while ( (c = fgetc(archE)) != EOF) {
			if ( c != ' ' && c != '\n') {
				fprintf(archS, "%c",  EncrptMurcielago( EncrptCesar(c) ) );
	    	}

	    }
		
	} else if (argv[1][1] == 'd') {
	    
	    while ( (c = fgetc(archE)) != EOF ) {
	    	if (c != '\n') {
	       		fprintf(archS, "%c", DesEnCesar( DesEnMurcielago(c) ) );
	    	}
	    }
	}
	fprintf(archS, "\n");
	TF = TomarTiempo();
	printf("El Encriptado/Decriptado secuencial tardo: %i\n", TF-TI);

    fclose(archE);
    fclose(archS);

	return 0;
}