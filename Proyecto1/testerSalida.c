#include <stdio.h>

int main(int argc, char const *argv[]) {
	
	FILE* arch1;
	FILE* arch2;
	int i, c1, c2;

	arch1 = fopen(argv[1], "r");
	arch2 = fopen(argv[2], "r");

	fseek(arch1, 0, SEEK_END);
	long tamano1 = ftell(arch1) - 1;

	fseek(arch2, 0, SEEK_END);
	long tamano2 = ftell(arch2) - 1;

	fseek(arch1, 0, SEEK_SET);
	fseek(arch2, 0, SEEK_SET);

	printf("tamanos: %ld %ld \n", tamano1, tamano2);

	i=0;
	while ( i < ((tamano1 + tamano2) / 2) + 5 ) {
		c1 = fgetc(arch1);
		c2 = fgetc(arch2);

		if ( c1 != c2 ) {
			
			printf("caracter numero %i es distinto   %c--%c \n", i, c1, c2);
			
	   	}
	   	i++;
	}
	
    fclose(arch1);
    fclose(arch2);

	return 0;
}