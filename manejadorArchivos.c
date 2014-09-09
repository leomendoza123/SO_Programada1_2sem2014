    #define CANTIDAD_HILOS_ESCRITORES 1
    #define CANTIDAD_ESPACIONS_POOL 100

    #include <stdio.h>
    #include <string.h>
    #include <pthread.h>
    #include "socket.h"
    #include "manejadorArchivos.h"
    #include "manejadorCache.h"


    int archivos_Inicia();
    int escrbirArchivo(char * contenido, char *url);
    void *hiloWriteWEB(void *dummyPtr);

    // Manejo de hilos de escritura
    pthread_t thread_id [CANTIDAD_HILOS_ESCRITORES];
    pthread_mutex_t mutexEscritura = PTHREAD_MUTEX_INITIALIZER;
    int counterEscritura;


    int archivos_Inicia ()
    {

           int i;

           for(i=0; i < CANTIDAD_HILOS_ESCRITORES; i++)
           {
              pthread_create( &thread_id[i], NULL, hiloWriteWEB, NULL );
           }

           return 0;


    }

    int pool_joinHilosEscritores(){


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
            if (cache_size()>counterEscritura){

                char * archivo = cache_get(counterEscritura);


                    printf("----- Hilo numero: %ld \n", pthread_self());
                    printf("----- toma elemento %d de pool, de poolTop %d\n", counterEscritura, cache_size());

                pthread_mutex_lock( &mutexEscritura );

                counterEscritura++;

                pthread_mutex_unlock( &mutexEscritura );


                 /// Guarda el archivo
                printf(archivo);



                }
            else{
                   printf("----- Nada por escribir \n");
                }




             sleep (2);
            }



        }


int escrbirArchivo(char * contenido, char *url)
    {




   }

