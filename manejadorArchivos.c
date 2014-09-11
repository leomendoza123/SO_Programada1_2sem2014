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
        while (1){
            /// Solicita archivo por escribir
            pthread_mutex_lock( &mutexEscritura );
            if (cache_size()>counterCache){

                printf("----- Hilo numero: %ld Elemento %d de %d en CACHE\n", pthread_self(), counterCache, cache_size());
                char * archivo = cache_get(counterCache);
                char * paginaActual  = cacheNombres_get(counterCache);
                counterCache++;


                 /// Guarda el archivo
                escrbirArchivo(archivo, paginaActual);

                }
            else{
                     printf("----- Hilo numero: %ld Cache vacio \n", pthread_self());
                }
            pthread_mutex_unlock( &mutexEscritura );




             sleep (1);
            }



        }


int escrbirArchivo(char * contenido, char *url)
    {
        printf(contenido);
        printf(url);
   }

