    #define CANTIDAD_HILOS_ESCRITORES 5
    #define CANTIDAD_ESPACIONS_POOL 100

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
    int counterCache;


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


                printf("----- Hilo numero: %ld \n", pthread_self());
                printf("----- toma elemento %d de %d en CACHE\n", counterCache, cache_size());
                char * archivo = cache_get(counterCache);
                char * pagina =
                counterCache++;
                pthread_mutex_unlock( &mutexEscritura );

                 /// Guarda el archivo
              //  escrbirArchivo(archivo, );



                }
            else{
                   printf("----- Nada por escribir \n");
                }




             sleep (1);
            }



        }


int escrbirArchivo(char * contenido, char *url)
    {
                               printf(">>>> Escribe en disco duro \n");

/*
          FILE * pFile;
          pFile = fopen ("myfile.bin", "wb");
          fwrite (buffer , sizeof(char), sizeof(contenido), pFile);
          fclose (pFile);
          return 0;
*/

   }

