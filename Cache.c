

// TODO:

// Manejar los cache en un solo struct


    #include <stdio.h>
    #include <string.h>
    #include <pthread.h>
    //Manejo de cache

    #define TAMANOCACHE 1000
    #define MYSTRDUP(str,lit) strcpy(str=malloc(strlen(lit)+1),lit)


    int escrbirArchivo(char * contenido, char *url);

    char *cache [TAMANOCACHE];
    char *cacheNombres [TAMANOCACHE];

    int cacheTop = 0;

    pthread_mutex_t mutexCache = PTHREAD_MUTEX_INITIALIZER;


    int cache_add (char *archivo, char *nombre)

    {
            // Bloque el cache, toma la posicin y lo desbloque
            pthread_mutex_lock( &mutexCache );
                int cacheTopActual = cacheTop;
                cacheTop++;
            pthread_mutex_unlock( &mutexCache );

            // aparta la memoria para elemento en cache
            char * archivotemp = calloc(strlen(archivo), sizeof(char));
            char * nombretemp = calloc(strlen(nombre), sizeof(char));

            // Copia el contenido del archivo
            archivotemp = strcat(archivotemp,archivo );

            //Copia el nombre del archivo
            nombretemp = strcat(nombretemp,nombre );


            // Guarde el contenido en cache
            cache[cacheTopActual] = archivotemp;
            // Guarde el nombre en cacheNombre
            cacheNombres[cacheTopActual] = nombretemp;







    }

        char * cache_get (int index)

    {
            return cache[index];

    }
    char * cacheNombres_get (int index)

    {

            return cacheNombres[index];


    }

     int cache_size ()

    {
        return cacheTop;

    }



