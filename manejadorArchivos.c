    #define CANTIDAD_HILOS_ESCRITORES 2

    #include <stdio.h>
    #include <string.h>
    #include <pthread.h>
    #include "socket.h"
    #include "manejadorArchivos.h"
    #include "Cache.h"


    int archivos_Inicia();
    int escrbirArchivo(char * contenido, char *url);
    void *hiloWriteWEB(void *dummyPtr);
    int numeroHilos = 0;

    // Manejo de hilos de escritura
    pthread_t thread_id [CANTIDAD_HILOS_ESCRITORES];
    pthread_mutex_t mutexEscritura = PTHREAD_MUTEX_INITIALIZER;
    int counterCache = 0;


    int archivos_Inicia ()
    {

           int i;

           for(i=0; i < CANTIDAD_HILOS_ESCRITORES; i++)
           {
              pthread_create( &thread_id[i], NULL, hiloWriteWEB, NULL );
           }

           return 0;


    }

    int archivos_joinHilos(){


            int j;
           for(j=0; j < CANTIDAD_HILOS_ESCRITORES; j++)
           {
              pthread_join( thread_id[j], NULL);
           }

    }

    void *hiloWriteWEB(void *dummyPtr)
        {
        int idhilo = numeroHilos++;
        while (1){
            /// Solicita archivo por escribir
            pthread_mutex_lock( &mutexEscritura );
            if (cache_size()>counterCache){

                char * archivo = cache_get(counterCache);
                char * paginaActual  = cacheNombres_get(counterCache);
                printf("(A)----- Hilo numero: %ld Elemento %d de %d (%s) \n", idhilo, counterCache, cache_size(), paginaActual);

                counterCache++;


                 /// Guarda el archivo
                escrbirArchivo(archivo, paginaActual);
                printf("(A)----- Hilo numero: %ld finaliza (%s)\n", idhilo, paginaActual);



                }
            else{
                     printf("(A)----- Hilo numero: %ld Cache vacio \n", idhilo);
                }
            pthread_mutex_unlock( &mutexEscritura );




             sleep (1);
            }



        }


int escrbirArchivo(char * contenido, char *url)
    {

        FILE *archivo;

        if((archivo = fopen(url,"a"))==NULL)
        {
            printf("No se puede escrbir el archivo \n");
            exit(1);
        }
        fprintf(archivo,contenido);
        fclose(archivo);
        return 1;

   }

