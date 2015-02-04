#include "algosEncriptacion.h"

char EncrptCesar(char nuevo) {
	
	if (nuevo > 96 && nuevo < 123) {
		if (nuevo < 97 + 26 - 2) { 
			nuevo = nuevo + 2;

		} else {
			nuevo = nuevo - (26-2);
		}
	}
	return nuevo;
}

char DesEnCesar( char nuevo ) {
	if (nuevo > 96 && nuevo < 123) {
		if (nuevo > 96 + 2) { 
			nuevo = nuevo - 2;

		} else {
			nuevo = nuevo + (26-2);
		}
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

char DesEnMurcielago(char nuevo) {

	if (nuevo == 48) {
		nuevo = 'm';
	}
	if (nuevo == 49) {
		nuevo = 'u';
	}
	if (nuevo == 50) {
		nuevo = 'r';
	}
	if (nuevo == 51) {
		nuevo = 'c';
	}
	if (nuevo == 52) {
		nuevo = 'i';
	}
	if (nuevo == 53) {
		nuevo = 'e';
	}
	if (nuevo == 54) {
		nuevo = 'l';
	}
	if (nuevo == 55) {
		nuevo = 'a';
	}
	if (nuevo == 56) {
		nuevo = 'g';
	}
	if (nuevo == 57) {
		nuevo = 'o';
	}
	return nuevo;
}	

