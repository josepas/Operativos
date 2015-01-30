#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>


char EncrptCesar( char nuevo );

char EncrptMurcielago( char nuevo );

void EncBloqueCesar(int inicio, int nc, pid_t pid, FILE* entrada);

