#include "colaTrabajos.h"


int main(int argc, char *argv[]) {

    char* directorio = NULL;
    char* salida;

    pid_t pid;
    pid_t* trabajadores;

    char buff[500];
    int nHijos = 1;
    int c, i, j;


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
    int links = 0;

    // Matriz de pipes
    aHijos = (int **) malloc(sizeof(int *) * nHijos);
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
            //FILE* salidaHijo;
            FILE* entradaHijo;
            char buffer2[1024];
            close(alPadre [0]);
            for (j = 0; j<i; j++) {
                close(aHijos[j][0]);
                close(aHijos[j][1]);
            }
            close(aHijos[i][1]);

            entradaHijo = fdopen(aHijos[i][0], "r");
            while ( !feof (entradaHijo) &&  fgets (buffer2, sizeof (buffer2), entradaHijo) != NULL) {
                buffer2[strcspn(buffer2, "\n")] = 0;
                printf("Escribi desde un hijo ---> %s\n", buffer2);

            }
            
            DIR* dH;
            struct dirent *dirH;
            struct stat atributosH;
            char* directorioH;
            int sumaHijo = 0;


            asprintf(&directorioH, "%s/%s", directorio, buffer2);
            printf("%s----\n", directorioH);
            dH = opendir(directorioH);

            while ((dirH = readdir(dH)) != NULL) {
                if (dirH->d_name[0] == '.') {
                    continue;
                }
                printf("%s\n", dirH->d_name);
                lstat(dirH->d_name, &atributosH);

                if (S_ISDIR(atributosH.st_mode)) {
                    printf("DIRRRR\n");
                }
                if (S_ISLNK(atributosH.st_mode)) {
                }
                if (S_ISREG(atributosH.st_mode)) {

                    sumaHijo += (int)atributosH.st_blocks;
                    
                }
                
            }
            printf("%s %d\n", directorioH, sumaHijo);




            



            //salidaHijo = fdopen(alPadre[1], "w");
            //fprintf(salidaHijo, "hola como estas %i\n", i);

            


            printf("TERMINARE SOY TU HIJO\n");

            exit(0);

        } else {
            trabajadores[i] = 0;
        }
    }

    close(alPadre[1]);


    

    DIR *d;
    ColaT* trabajos;
    struct dirent *dir;
    struct stat atributos;
    int suma = 0;
    int estado;

    trabajos = CrearColaT();
    d = opendir(directorio);

    while ((dir = readdir(d)) != NULL) {

        if (dir->d_name[0] == '.') {
            continue;
        }
        lstat(dir->d_name, &atributos);

        if (S_ISDIR(atributos.st_mode)) {
            EncolarT(trabajos, dir->d_name);
        }
        if (S_ISLNK(atributos.st_mode)) {
            links++;
        }
        if (S_ISREG(atributos.st_mode)) {
            suma += (int)atributos.st_blocks;

        }
    }


    printf("%s %d\n", directorio, suma);

    //FILE* entradaPadre = fdopen(alPadre[0], "r");
    
    FILE** salidaPadre;
    salidaPadre = (FILE**)malloc(sizeof(FILE*) * nHijos);
    for (i = 0; i < nHijos; i++) {
        salidaPadre[i] = fdopen(aHijos[i][1], "w");
    }


    //char buffer[1024];
    while ( esVaciaColaT(trabajos) == 0 ) {
        
        j = 0;
        while (j < nHijos) {
            if (trabajadores[j] == 0) {
                fprintf(salidaPadre[j], "%s\n", DesencolarT(trabajos));
                trabajadores[j] = 1;
            }
            j++;
        } 
        
        //while ( !feof (entradaPadre) &&  fgets (buffer, sizeof (buffer), entradaPadre) != NULL) {
        //    printf("%s\n", buffer);
        //}



    }



    return 0; 

}