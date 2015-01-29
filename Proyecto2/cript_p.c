#include <unistd.h>
#include "algosEncriptacion.h"

#include "algosDesencriptacion.h"

int main(int argc, char const *argv[]) {

	FILE* archE;
	FILE* archS;
	long NHijos;

	if (argc != 5) {
		printf("llamada hecha incorrectamente.\n");
		printf("cript_p [-c/-d] <NumeroHijos> <archivoEntrada> <archivoSalida> \n");
		return 0;
	}

	archE = fopen(argv[3], "r");
	if (archE == 0) {
		printf("El archivo %s no existe\n", argv[3]);
		return 0;
	}

	archS = fopen(argv[4], "w");

	NHijos = atoi(argv[2]);

	fseek(archE, 0, SEEK_END);
	long tamano = ftell(archE) - 1;
	printf("%ld\n", tamano);
	printf("%ld\n", NHijos );
	printf("%ld\n", tamano/NHijos );




	fclose(archS);
	fclose(archE);
	return 0;
}