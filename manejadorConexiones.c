    #define CANTIDAD_HILOS_LECTORES 5
    #define CANTIDAD_ESPACIONS_POOL 100

    #include <stdio.h>
    #include <string.h>
    #include <pthread.h>
    #include "socket.h"
    #include "Cache.h"
    #include "pool.h"
    #include "listaPool.h"


    void *hiloGetWEB(void *);
    void *hiloGetWEB(void *);
    int conexiones_add (char *url);

    // Manejo de hilos de pool
    pthread_t thread_id [CANTIDAD_HILOS_LECTORES];
    pthread_mutex_t mutexPool = PTHREAD_MUTEX_INITIALIZER;
    pthread_mutex_t mutexCounter = PTHREAD_MUTEX_INITIALIZER;


    //Manejo de cache
    int  poolCounter = 0;
    int  poolTop = 0;

    //Manejo del pool
    char * pool[CANTIDAD_ESPACIONS_POOL] ;


    int conexiones_add (char *url){
        pthread_mutex_lock( &mutexPool );


        pool[poolTop] = url;
        poolTop++;


        pthread_mutex_unlock( &mutexPool );
    }


    int conexiones_Inicia ()
    {

        /// Inicializa los hilos lectores

           int i;

           for(i=0; i < CANTIDAD_HILOS_LECTORES; i++)
           {
              pthread_create( &thread_id[i], NULL, hiloGetWEB, NULL );
           }

           return 0;


    }

    int conexiones_joinHilos(){


            int j;
           for(j=0; j < CANTIDAD_HILOS_LECTORES; j++)
           {
              pthread_join( thread_id[j], NULL);
           }

    }

    void *hiloGetWEB(void *dummyPtr)
        {
        struct Poolstruct *PoolstructObj = listaPool_newPool();

        while (1){
            /// GUARDA LA ACTUAL POSICION DEL POOL Y verifica si hay que revisarla
            // TODO quitar los mutex pues ahora los pools funcionan individualmente
            pthread_mutex_lock( &mutexCounter );
            int poolCounterActual= -1;
            if (PoolstructObj->poolTop  >  PoolstructObj->poolCounter){
                poolCounterActual= PoolstructObj->poolCounter;
                PoolstructObj->poolCounter++;
                printf("(C)~~~~~Hilo: %ld Elemento %d de %d  (%s )\n", PoolstructObj->id, poolCounterActual, PoolstructObj->poolTop, PoolstructObj->pool[poolCounterActual]);

            }
            else{
                printf("(C)~~~~~Hilo: %ld Pool sin pendientes \n", PoolstructObj->id);
            }
            pthread_mutex_unlock( &mutexCounter );




            /// PROCESA LA POSICION DEL POOL SOLICITADA Y GUARDA EN CACHE
            if (poolCounterActual!=-1){
                               char * html;
                               html = socket_getHtml (PoolstructObj->pool[poolCounterActual], "/");
                               cache_add (html, PoolstructObj->pool[poolCounterActual]);
                               memset(html, 0, sizeof(char ) * strlen (html));
                               printf("(C)~~~~~Hilo: %ld Finaliza \n", PoolstructObj->id, PoolstructObj->pool[poolCounterActual]);

                               //free (html);
             }

            /// DUERME EL HILO
             sleep (1);

            }
        }


