#include "algosEncriptacion.h"

void ProcesoHoja(int inicio, int nc, pid_t pid, char* entrada, char modo);

void ProcesoIntermedio(pid_t* hijosH, int nHijos, char modo);

void ConcatResultado(pid_t* hijosI, int nHijos, FILE* archS);