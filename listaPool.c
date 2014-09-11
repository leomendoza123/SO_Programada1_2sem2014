    #include <stdio.h>
      #define CATIDAD_DE_POOLS 1000

    #include <string.h>
    #include <pthread.h>
    #include "pool.h"


    pthread_mutex_t mutexPoolLista = PTHREAD_MUTEX_INITIALIZER;
       struct Poolstruct * listaPools [CATIDAD_DE_POOLS];


    int listaPoolTop;


   struct Poolstruct * listaPool_newPool (){
        pthread_mutex_lock( &mutexPoolLista );

        int listaPoolTopActual = listaPoolTop ;
        listaPoolTop++;
        pthread_mutex_unlock( &mutexPoolLista );

        struct Poolstruct *nuevoPool  = calloc(1, sizeof (struct Poolstruct));
        listaPools[listaPoolTopActual]  = nuevoPool;
        nuevoPool->poolCounter =0;
        nuevoPool->poolTop =0;
        nuevoPool->id = listaPoolTopActual;

        return nuevoPool;
   }

   struct Poolstruct *  listaPools_getPoolstruct (int index){

    return listaPools[index];

   }
  struct Poolstruct **listaPools_getlistaPools(){
    return listaPools;

  }

  int listaPools_getlistaPoolTop (){
    return listaPoolTop;
  }

