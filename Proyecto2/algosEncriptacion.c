#include "algosEncriptacion.h"

char EncrptCesar(char nuevo) {
	
	if (nuevo < 97 + 26 - 2) { 
		nuevo = nuevo + 2;

	} else {
		nuevo = nuevo - (26-2);
	}
	return nuevo;
}

char EncrptMurcielago(char nuevo) {

	if (nuevo == 'm') {
		nuevo = 48;
	}
	if (nuevo == 'u') {
		nuevo = 49;
	}
	if (nuevo == 'r') {
		nuevo = 50;
	}
	if (nuevo == 'c') {
		nuevo = 51;
	}
	if (nuevo == 'i') {
		nuevo = 52;
	}
	if (nuevo == 'e') {
		nuevo = 53;
	}
	if (nuevo == 'l') {
		nuevo = 54;
	}
	if (nuevo == 'a') {
		nuevo = 55;
	}
	if (nuevo == 'g') {
		nuevo = 56;
	}
	if (nuevo == 'o') {
		nuevo = 57;
	}
	return nuevo;
}