#include "pilaEnteros.h"

int main(int argc, char const *argv[])
{
	Pila* p;
	p = CrearPilaEnt();
	EmpilarEnt(p, 1);
	DesempilarEnt(p);
	ImprimirPilaEnt(p);
	EmpilarEnt(p, 2);
	EmpilarEnt(p, 3);
	EmpilarEnt(p, 4);
	EmpilarEnt(p, 5);
	ImprimirPilaEnt(p);
	DesempilarEnt(p);
	DesempilarEnt(p);
	ImprimirPilaEnt(p);
	EmpilarEnt(p, 69);
	ImprimirPilaEnt(p);

	return 0;
}