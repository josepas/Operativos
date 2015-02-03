#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "extras.h"

char EncrptCesar( char nuevo );

char DesEnCesar( char nuevo ); 

char EncrptMurcielago( char nuevo );

char DesEnMurcielago( char nuevo ); 

void ProcesoHoja(int inicio, int nc, pid_t pid, char* entrada, char modo);

void ProcesoIntermedio(pid_t* hijosH, int nHijos, char modo);

