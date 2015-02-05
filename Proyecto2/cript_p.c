#include "procesos.h"

/*	
 *	Se hace el cifrado de un texto usando procesos. 
 *	Para cifrar se hará uso de los códigos césar y murciélago. 
 */ 

int main(int argc, char const *argv[]) {

	FILE* archE;
	FILE* archS;
	char entrada[25];

	int   i, j;
	int   TI, TF;
	long  nHijos;
	long* ncI;				// Numero de caracteres a procesar por hijoI;
	long* ncH;				// Numero de caracteres a procesar por hijoH;
	long  inicio, inicio1;

	pid_t* hijosH;
	pid_t* hijosI;

	pid_t pidI, pidH;

	// Mensaje de error si el comando esta hecho incorrectamente. 

	if (argc != 5) {
		printf("llamada hecha incorrectamente.\n");
		printf("cript_p [-c/-d] <NumeroHijos> <archivoEntrada> <archivoSalida> \n");
		return 0;
	}

	// Mensaje de error si el archivo a leer no existe. 	

	archE = fopen(argv[3], "r");
	if (archE == 0) {
		printf("El archivo %s no existe\n", argv[3]);
		exit(1);
	}
	
	TI = TomarTiempo();
	
	fseek(archE, 0, SEEK_END);
	long tamano = ftell(archE) - 1;
	fclose(archE);

	nHijos = atoi(argv[2]);
	hijosH = (pid_t *)malloc(sizeof(pid_t)*nHijos);
	hijosI = (pid_t *)malloc(sizeof(pid_t)*nHijos);
	
	strcpy(entrada, argv[3]);
	
	ncI = Rangos(tamano, nHijos);
	inicio = 0;
	inicio1 = 0;
	for (i=0; i<nHijos; i++) {
		pidI = fork();
		if (pidI < 0) {
			perror("Fallo el Fork de Hijo Hoja");
			exit(1);
		}
		if (pidI == 0) {
			
			ncH = Rangos(ncI[i], nHijos);
			inicio1 = inicio;
			for (j=0; j<nHijos; j++) {
				pidH = fork();
				if (pidH < 0) {
					perror("Fallo un Fork de Hijo Hoja");
      				exit(1);
				}
				if (pidH == 0) {

					ProcesoHoja(inicio1, ncH[j], getpid(), entrada, argv[1][1]);
					free(hijosH);
					free(hijosI);
					free(ncI);
					free(ncH);

					exit(0);
					
				} else {
					hijosH[j] = pidH;
					inicio1 += ncH[j];
				}
			}
			
			ProcesoIntermedio(hijosH, nHijos, argv[1][1]);
			free(hijosH);
			free(hijosI);
			free(ncI);
			free(ncH);

			exit (0);

		} else {
			
			inicio += ncI[i];
			hijosI[i] = pidI;
		}
	}
	archS = fopen(argv[4], "w");
	ConcatResultado(hijosI, nHijos, archS);
	TF = TomarTiempo();
	printf("El Encriptado/Decriptado con procesos tardo: %i\n", TF-TI);

	free(ncI);
	free(hijosH);
	free(hijosI);
	fclose(archS);
	return 0;
}