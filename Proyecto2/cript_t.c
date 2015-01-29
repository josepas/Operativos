#include "algosEncriptacion.h"
#include "algosDesencriptacion.h"

int main(int argc, char const *argv[]) {

	FILE* archE;
	FILE* archS;
	int NHijos;

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

	NHijos = argv[2];

	fseek(archE, 0, SEEK_END);
	long tamano = ftell(archE);
	printf("%ld\n", tamano);

	return 0;
}