#define TAMANOPOOL 100


    #include <stdio.h>
    #include <string.h>
    #include <pthread.h>
    #include "pool.h"


    #define MYSTRDUP(str,lit) strcpy(str=malloc(strlen(lit)+1),lit)




    int pool_add (struct Poolstruct *pool_stc, char * URL)
    {
        int index = pool_stc->poolTop;
        pool_stc->pool[index] = URL;
        pool_stc->poolTop ++;
        return 1;

    }
    char * pool_getIndex (struct Poolstruct *pool_stc, int index)
    {
        char * poolContent;
        poolContent =  pool_stc->pool[index];
        return poolContent;
    }
    int pool_getSize (struct Poolstruct *pool_stc)

    {
        return pool_stc->poolTop;
    }




