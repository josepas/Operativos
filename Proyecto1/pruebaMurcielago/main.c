#include <stdio.h>
static int const m = 0;
static int const u = 1;
static int const r = 2;
static int const c = 3;
static int const i = 4;
static int const e = 5;
static int const l = 6;
static int const a = 7;
static int const g = 8;
static int const o = 9;



int main(int argc, char const *argv[]) {
	
	char str[50] = "solo te lo dire manana al mediodia en la biblioteca";
	int i;

	for (i=0; i<40; i++) {
		//if (str[i] == ' ') {
		//	continue;
		//}
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
	return 0;
}