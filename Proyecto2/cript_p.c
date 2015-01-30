
#include "algosEncriptacion.h"
#include "algosDesencriptacion.h"

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


int main(int argc, char const *argv[]) {

	FILE* archE;
	FILE* archS;
	long nHijos;
	long* ra;		//Numero de caracteres a procesar por hijo;
	long* ra1;
	long inicio, inicio1;


	pid_t pidI, pidH;

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

	nHijos = atoi(argv[2]);

	fseek(archE, 0, SEEK_END);
	long tamano = ftell(archE) - 1;

	ra = rangos(tamano, nHijos);

	

	int i;
	int j;
	inicio = 0;
	inicio1 = 0;
	for (i=0; i<nHijos; i++) {
		pidI = fork();
		if (pidI == 0) {
			
			ra1 = rangos(ra[i], nHijos);
			inicio1 = inicio;
			for (j=0; j<nHijos; j++) {
				pidH = fork();
				if (pidH == 0) {
					fseek(archE, inicio1, SEEK_SET);
					EncBloqueCesar(inicio1, ra1[j], getpid(), archE);
					exit(0);
					
				} else {
					printf("%ld\n", inicio1);
					inicio1 += ra1[j];
				}

				
			}
			exit (0);
		} else {
	
			inicio += ra[i];
		}
		
	}

	/*
	for (i = 0; i < nHijos; ++i) {
		
		for (j = 0; j < nHijos; ++j) {
			printf("%i\n", hijosH[i][j]);
			wait(&estado);
		}
	}
	*/



	







	fclose(archS);
	fclose(archE);
	return 0;
}