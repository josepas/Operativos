#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
	
	FILE *archE;	
	int destino, ini, fin; 		//buffers

	if (argc != 2) {
		printf("%s\n", "La llamada debe hacerse con un y solo un parametro");
		exit(0);
	}
	// flag
	printf("%s\n", argv[1]);

	archE = fopen(argv[1], "r");

	if (archE == 0) {
		printf("El archivo %s no existe\n", argv[1]);
		exit(0);
	}


	while ( fscanf(archE, "%d", &destino)  != EOF ) {
		// f
		printf("%d\n", destino);
		while (ini != 0) {
			fscanf(archE, "%d %d", &ini, &fin);
			// f
			printf("%d %d\n", ini, fin);
		}
		ini = 1;
	}


	fclose(archE);
	return 0;
}