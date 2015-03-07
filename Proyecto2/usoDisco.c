#include "colaTrabajos.h"


int main(int argc, char *argv[]) {

    char* directorio = NULL;
    char* salida;

    pid_t pid;
    int* trabajadores;
    pid_t* pidHijos;

    int nHijos = 1;
    int c, i, j;

    int estado;
    int ocupados = -1;



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
    if (directorio == NULL) {
        directorio = ".";
    } else {
        chdir(directorio);
    }

    if (salida == NULL) {
        printf("Archivo de salida no especificado\n");
        exit(1);
    }

    trabajadores = (int*)malloc(sizeof(int) * nHijos);
    pidHijos = (pid_t*)malloc(sizeof(pid_t) * nHijos);


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
            
            char buffer2[1024];
            close(alPadre[0]);
            close(aHijos[i][1]);

            int sumaHijo = 0;
            int linkH = 0;
            char resultado[1024];
            char listaTrabajos[2048];
            DIR* dH;
            struct dirent *dirH;
            struct stat atributosH;
            char directorioH[512];



            while (1) {

                read(aHijos[i][0], buffer2, sizeof(buffer2));
                buffer2[strcspn(buffer2, "\n")] = 0;

                linkH = 0;
                resultado[0] = 0;
                directorioH[0] = 0;
                sumaHijo = 0;
                dH = opendir(buffer2);
                listaTrabajos[0] = 0;


                while ((dirH = readdir(dH)) != NULL) {

                    if (dirH->d_name[0] == '.') {
                        continue;
                    }

                    sprintf(directorioH, "%s/%s", buffer2, dirH->d_name);
                    lstat(directorioH, &atributosH);

                    if (S_ISDIR(atributosH.st_mode)) {
                        strcat(listaTrabajos, directorioH);
                        strcat(listaTrabajos, " ");

                    }
                    if (S_ISLNK(atributosH.st_mode)) {
                        linkH++;
                    }
                    if (S_ISREG(atributosH.st_mode)) {
                        sumaHijo += (int)atributosH.st_blocks;
                    }

                    //free(directorioH);
                    
                }

                closedir(dH);

                printf("%d\t%s\n", sumaHijo, buffer2);
                sprintf(resultado, "%d %d %s\n", i, linkH, listaTrabajos);
                
                write(alPadre[1], resultado, 1024);
                //free(trabajadores);
                //free(pidHijos);
                //free(resultado);


            }
            exit(0);

        } else {
            trabajadores[i] = 0;
            pidHijos[i] = pid;
            close(aHijos[i][0]);
            
        }
    }

    
    close(alPadre[1]);
    DIR *d;
    ColaT* trabajos = NULL;
    struct dirent *dir;
    struct stat atributos;
    int suma = 0;
    char* rutaActual;

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

    closedir(d);

    printf("%d\t%s\n", suma, directorio);

    
    FILE** salidaPadre;
    salidaPadre = (FILE**)malloc(sizeof(FILE*) * nHijos);
    for (i = 0; i < nHijos; i++) {

        salidaPadre[i] = fdopen(aHijos[i][1], "w");
    }


    while ( esVaciaColaT(trabajos) == 0 || (ocupados > 0) ) {
        
        // escritura del padre
        j = 0;
        while (j < nHijos) {
            rutaActual = TopeColaT(trabajos);
            if (trabajadores[j] == 0 && rutaActual != NULL)  {
                DesencolarT(trabajos);
                fprintf(salidaPadre[j], "%s\n", rutaActual);
                fflush(salidaPadre[j]);
                trabajadores[j] = 1;
            }
            j++;

        } 


        // lectura deesde el padre
        char* aux;
        char buffer[1024];
        read(alPadre[0], buffer, sizeof(buffer));
        buffer[strcspn(buffer, "\n")] = 0;

        aux = strtok (buffer," ");
        trabajadores[atoi(aux)] = 0;
        aux = strtok (NULL," ");
        links += atoi(aux);
        while (aux != NULL) {
            aux = strtok (NULL," ");
            if ( aux != NULL ) {
                EncolarT(trabajos, aux);
            }


        }
        ocupados = 0;
        for  (i = 0; i < nHijos; i++) {
            ocupados += trabajadores[i];
        }


    }

    for (i = 0; i < nHijos; i++) {
        kill(pidHijos[i], SIGTERM);
        wait(&estado);
    }

    printf("\n");
    printf("Total de enlaces logicos: %d\n", links);

    for (i = 0; i < nHijos; i++) {
        fclose(salidaPadre[i]);
        free(aHijos[i]);

    }

    free(trabajadores);
    free(pidHijos);
    free(aHijos);
    free(salidaPadre);
    free(trabajos);
    return 0;

}