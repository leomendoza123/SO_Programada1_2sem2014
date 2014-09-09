
    #include <stdio.h>
    #include <string.h>
    #include <pthread.h>
    //Manejo de cache

    #define TAMANOCACHE 1000
    #define MYSTRDUP(str,lit) strcpy(str=malloc(strlen(lit)+1),lit)


    int escrbirArchivo(char * contenido, char *url);

    char *cache [TAMANOCACHE];
    int cacheTop = 0;

    pthread_mutex_t mutexCache = PTHREAD_MUTEX_INITIALIZER;


    int cache_add (char *archivo, char *nombre)

    {

            char * temp = calloc(strlen(archivo), sizeof(char));
            temp = strcat(temp,archivo );

            pthread_mutex_lock( &mutexCache );
            cache[cacheTop] = temp;
            cacheTop++;
            pthread_mutex_unlock( &mutexCache );




    }

        char * cache_get (int index)

    {

            return cache[index];


    }

     int cache_size ()

    {
        return cacheTop;

    }



