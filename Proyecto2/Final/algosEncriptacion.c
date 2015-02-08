#include "algosEncriptacion.h"

/* Recibe un caracter y devuelve el caracter que le sigue en 2 posiciones 
 * del abecedario. 
 */

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

/* Recibe un caracter y devuelve el caracter que esta 2 posiciones antes
 * en el abecedario. 
 */

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

/* Recibe un caracter y si es una letra de la palabra murcielago devuelve 
 * un número predeterminado. m=0, u=1,r=2, c=3, i=4, e=5,l=6, a=7, g=8, o=9.
 */

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

/* Recibe un caracter y si es un número del 0-9 devuelve un caracter de la palabra muricielago 
 * en coherencia a lo predeterminado en Encryptmurcielago. 
 */

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

