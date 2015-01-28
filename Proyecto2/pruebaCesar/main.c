#include <stdio.h>
#include <string.h>

void EncrptCesar( int nc, char* str[] ) {
	int i;

	printf("%i\n", str[]);
	for (i=0; i<nc; i++) {
		if (str[i] == ' ') {
			continue;
		}
		printf("%c\n", str[i] + 2);
	}

}

void EncrptMurcielago( int nc, char* str[] ) {
	int i;

	for (i=0; i<nc; i++) {
		if (str[i] == ' ') {
			continue;
		}
		if (str[i] == 'm' || str[i] == 'M') {
			str[i] = 48;
		}
		if (str[i] == 'u' || str[i] == 'U') {
			str[i] = 49;
		}
		if (str[i] == 'r' || str[i] == 'R') {
			str[i] = 50;
		}
		if (str[i] == 'c' || str[i] == 'C') {
			str[i] = 51;
		}
		if (str[i] == 'i' || str[i] == 'I') {
			str[i] = 52;
		}
		if (str[i] == 'e' || str[i] == 'E') {
			str[i] = 53;
		}
		if (str[i] == 'l' || str[i] == 'L') {
			str[i] = 54;
		}
		if (str[i] == 'a' || str[i] == 'A') {
			str[i] = 55;
		}
		if (str[i] == 'g' || str[i] == 'G') {
			str[i] = 56;
		}
		if (str[i] == 'o' || str[i] == 'O') {
			str[i] = 57;
		}
		printf("%c", str[i]);
	}
	printf("\n");
}