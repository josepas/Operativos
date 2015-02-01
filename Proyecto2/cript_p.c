#include "algosEncriptacion.h"
#include "algosDesencriptacion.h"
#include "extras.h"

int main(int argc, char const *argv[]) {

	FILE* archE;
	FILE* archS;
	FILE* archAuxE;
	FILE* archAuxS;	
	
	int i, j, c;

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

					free(hijosH);
					free(hijosI);

					free(ra);
					free(ra1);

					fclose(archE);
					fclose(archS);

					exit(0);
					
				} else {
					hijosH[j] = pidH;
					inicio1 += ra1[j];
				
				}

			}
			
			char aux[20];
			char aux1[20];
			
			sprintf(aux, "%d.txt" ,getpid() );
			
			archAuxS = fopen( aux, "a");

			for (j=0; j<nHijos; j++) {
				
				waitpid(hijosH[j], &estado, 0);					
				sprintf(aux1, "%d.txt", hijosH[j]);
								
				archAuxE = fopen( aux1, "r");
			
				while ( (c = fgetc(archAuxE)) != EOF ) {
	    			if (c != '\n') {
	       				fprintf(archAuxS, "%c", EncrptMurcielago(c));
	    			}
	    		}
	    	}

			fclose(archAuxE);
			fclose(archAuxS);

			free(hijosH);
			free(hijosI);

			free(ra);
			free(ra1);

			exit (0);

		} else {
			inicio += ra[i];
			hijosI[i] = pidI;

		}
		
	}
	for (i=0;i<nHijos; i++) {
		char aux2[20];
		waitpid(hijosI[i], &estado, 0);
		sprintf(aux2, "%d.txt", hijosI[i]);

		archAuxE = fopen(aux2, "r");
		
		while ( (c = fgetc(archAuxE)) != EOF ) {
			if (c != '\n') {
   				fprintf(archS, "%c", c);
			}
		}
		fclose(archAuxE);

	}

	free(ra);

	free(hijosH);
	free(hijosI);

	fclose(archS);
	fclose(archE);
	return 0;
}