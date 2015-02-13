#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>


int main(int argc, char *argv[]) {

    char* directorio = NULL;
    char* salida;
    int index;
    char buff[500];
    int nHijos = 0;
    int c;

    opterr = 0;
    while ((c = getopt (argc, argv, "hn:d:")) != -1) {
        switch (c) {
            case 'h':
                printf("UsoDisco [-h] | [-n i] [-d directorio] salida\n");
                printf("\n");
                printf("-h  Muestra esta informacion de uso.\n");
                printf("-n  Numero de procesos a usar.\n");
                printf("-d  Directorio al que se aplica el programa.\n");
                exit(0);
            case 'd':
                directorio = optarg;
                break;
            case 'n':
                nHijos = atoi(optarg);
                break;
            case '?':
                if (optopt == 'n')
                    fprintf (stderr, "Opcion -%c requiere un argumento.\n", optopt);
                else if (optopt == 'd')
                    fprintf (stderr, "Opcion -%c requiere un argumento.\n", optopt);
                else
                    fprintf (stderr, "Opcion desconocida -%c.\n", optopt);
            default:
                exit(1);
        }
    }
    salida = argv[optind];
    if (directorio == NULL)
        directorio = getcwd(buff, sizeof(buff));
    if (salida == NULL) {
        printf("Archivo de salida no especificado\n");
        exit(1);
    }

    printf ("directorio = %s, nHijos = %d salida = %s.\n", directorio, nHijos, salida );

    return 0; 

}