#include "algosEncriptacion.h"

char EncrptCesar(char nuevo) {
	
	if (nuevo > 96 && nuevo < 123) {
		if (nuevo < 97 + 26 - 2) { 
			nuevo = nuevo + 2;

		} else {
			nuevo = nuevo - (26-2);
		}
	}
	return nuevo;
}

char DesEnCesar( char nuevo ) {
	if (nuevo > 96 && nuevo < 123) {
		if (nuevo > 96 + 2) { 
			nuevo = nuevo - 2;

		} else {
			nuevo = nuevo + (26-2);
		}
	}
	return nuevo;

}

char EncrptMurcielago(char nuevo) {

	if (nuevo == 'm') {
		nuevo = 48;
	}
	if (nuevo == 'u') {
		nuevo = 49;
	}
	if (nuevo == 'r') {
		nuevo = 50;
	}
	if (nuevo == 'c') {
		nuevo = 51;
	}
	if (nuevo == 'i') {
		nuevo = 52;
	}
	if (nuevo == 'e') {
		nuevo = 53;
	}
	if (nuevo == 'l') {
		nuevo = 54;
	}
	if (nuevo == 'a') {
		nuevo = 55;
	}
	if (nuevo == 'g') {
		nuevo = 56;
	}
	if (nuevo == 'o') {
		nuevo = 57;
	}
	return nuevo;
}

char DesEnMurcielago(char nuevo) {

	if (nuevo == 48) {
		nuevo = 'm';
	}
	if (nuevo == 49) {
		nuevo = 'u';
	}
	if (nuevo == 50) {
		nuevo = 'r';
	}
	if (nuevo == 51) {
		nuevo = 'c';
	}
	if (nuevo == 52) {
		nuevo = 'i';
	}
	if (nuevo == 53) {
		nuevo = 'e';
	}
	if (nuevo == 54) {
		nuevo = 'l';
	}
	if (nuevo == 55) {
		nuevo = 'a';
	}
	if (nuevo == 56) {
		nuevo = 'g';
	}
	if (nuevo == 57) {
		nuevo = 'o';
	}
	return nuevo;
}	

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

