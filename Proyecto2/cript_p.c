
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
	FILE* archAux;

	int i;
	int j;

	long nHijos;
	long* ra;		//Numero de caracteres a procesar por hijo;
	long* ra1;
	long inicio, inicio1;

	int estado;
	pid_t* hijosH;
	pid_t* hijosI;


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
	hijosH = (pid_t *)malloc(sizeof(pid_t)*nHijos);
	hijosI = (pid_t *)malloc(sizeof(pid_t)*nHijos);

	fseek(archE, 0, SEEK_END);
	long tamano = ftell(archE) - 1;

	ra = rangos(tamano, nHijos);

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
					EncBloqueCesar(inicio1, ra1[j], getpid(), archE);
					exit(0);
					
				} else {
					printf("%i -------- orden real\n", pidH );
					hijosH[j] = pidH;
					inicio1 += ra1[j];
				
				}

			}
			inicio1 = inicio;

			for (j=0; j<nHijos; j++) {
				
				char* t = ".txt";
				char aux[20];
				sprintf( aux, "%d" ,getpid() );
				strcat(aux, t);

				archAux = fopen( aux, "a");
				printf("%ld\n", inicio1 );
				printf("%i\n", hijosH[j]);
				waitpid(hijosH[j], &estado, 1);
				inicio1 += ra1[j];





			}
			exit (0);

		} else {
			inicio += ra[i];
			hijosI[i] = pidI;

		}
		
	}
	for (i=0;i<nHijos; i++) {
		printf("%i------------ main\n", hijosI[i]);
		waitpid(hijosI[i], &estado, 1);
	}



	fclose(archS);
	fclose(archE);
	return 0;
}