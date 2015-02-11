#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


int main(int argc, char *argv[]) {
    int aflag = 0;
    int bflag = 0;
    char* directorio = NULL;
    char* salida;
    int index;
    char cwd[500];
    int nHijos = 0;
    int c;

    opterr = 0;
    while ((c = getopt (argc, argv, "hn:d:")) != -1) {
        switch (c) {
            case 'h':
                printf("UsoDisco [-h] | [-n i] [-d directorio] salida\n");
                exit(0);
            case 'd':
                directorio = optarg;
                break;
            case 'n':
                nHijos = atoi(optarg);
                break;
            case '?':
                if (optopt == 'n')
                    fprintf (stderr, "Option -%c requires an argument.\n", optopt);
                else if (optopt == 'd')
                    fprintf (stderr, "Option -%c requires an argument.\n", optopt);
                else
                    fprintf (stderr, "Unknown option character %x'.\n", optopt);
            default:
                exit(0);
        }
    }
    salida = argv[optind];
    if (directorio == NULL) {

        getcwd(directorio, 500);
        
        printf("%s\n", directorio);

    } 
    printf ("directorio = %s, nHijos = %d salida = %s.\n", directorio, nHijos, salida );

    return 0; 

}