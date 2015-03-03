#include "colaTrabajos.h"

int main(int argc, char *argv[]) {

    char* directorio = NULL;
    char* salida;

    pid_t pid;
    pid_t* trabajadores;

    char buff[500];
    int nHijos = 1;
    int c, i;


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

    trabajadores = (pid_t*)malloc(sizeof(pid_t) * nHijos);

    int alPadre[2];
    int** aHijos;

    // Matriz de pipes
    aHijos = (int **) malloc(sizeof(int *)*nHijos);
    for (i = 0; i < nHijos; i++) {
        aHijos[i] = (int *) malloc(sizeof(int)*2);
    }

    pipe(alPadre);






    // Se crea el pool de procesos
    for (i = 0; i < nHijos; i++) {

        pipe(aHijos[i]);
        pid = fork();


        if (pid == 0) {
            
            int j;
            FILE* salida;
            close(alPadre [0]);
            for (j = 0; j<i; j++) {
                close(aHijos[j][0]);
                close(aHijos[j][1]);
            }
            close(aHijos[i][1]);





            salida = fdopen(alPadre[1], "w");
            fprintf(salida, "hola como estas %i\n", i);




            exit(0);

        } else {
            trabajadores[i] = pid;
        }
    }

    close(alPadre[1]);
    char buffer[1024];
    FILE* entrada = fdopen(alPadre[0], "r");
    while ( !feof (entrada) &&  fgets (buffer, sizeof (buffer), entrada) != NULL ) {
        printf("%s\n", buffer);
    }

    ColaT* trabajos;

    trabajos = CrearColaT();

    EncolarT(trabajos, "hola1");
    EncolarT(trabajos, "hola2");
    EncolarT(trabajos, "hola3");
    EncolarT(trabajos, "hola4");
    EncolarT(trabajos, "hola5");

    printf("%s\n", DesencolarT(trabajos));
    printf("%s\n", DesencolarT(trabajos));
    printf("%s\n", DesencolarT(trabajos));
    printf("%s\n", DesencolarT(trabajos));
    printf("%s\n", DesencolarT(trabajos));
    


    return 0; 

}