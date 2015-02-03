#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>


long* rangos(long tamano, long nHijos);

void ConcatResultado(pid_t* hijosI, int nHijos, FILE* archS);