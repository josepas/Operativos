#include "algosEncriptacion.h"

/*	
 *	Se hace el cifrado de un texto de forma secuencial. 
 *	Para cifrar se hará uso de los códigos césar y murciélago. 
 */ 

int main(int argc, char const *argv[]) {
	
	FILE* archE;	
	FILE* archS;	
	int c;
	int TI, TF;

	// Mensaje de error de si el comando esta hecho incorrectamente. 

	if (argc != 4) {
		printf("llamada hecha incorrectamente.\n");
		printf("cript [-c/-d] <archivoEntrada> <archivoSalida> \n");
		return 0;
	}

	// Lee el archivo con el mensaje a encriptar/desencriptar.
	// Si tal archivo no existe, se muestra un mensaje de error.  

	archE = fopen(argv[2], "r");
	if (archE == 0) {
		printf("El archivo %s no existe\n", argv[2]);
		return 0;
	}

	archS = fopen(argv[3], "w");

	// Si el flag en la línea de comando es -c entonces se encripta
	// Si el flag en la línea de comando es -d entonces se desencripta
	// Se escribe en el el archivo de salida especificado.

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

	// Además de imprimir el mensaje encriptado/desencriptado se imprime el 
	// tiempo que tomó el mismo. 

	fprintf(archS, "\n");
	TF = TomarTiempo();
	printf("El Encriptado/Decriptado secuencial tardo: %i\n", TF-TI);

    fclose(archE);
    fclose(archS);

	return 0;
}