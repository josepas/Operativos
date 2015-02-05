#include "algosDesencriptacion.h"

/* Recibe un caracter y devuelve el caracter que le sigue en 2 posiciones 
 * del abecedario. 
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

/* Recibe un caracter y devuelve el caracter que le sigue en 2 posiciones 
 * del abecedario. 
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