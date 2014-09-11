#define TAMANOPOOL 100


    #include <stdio.h>
    #include <string.h>
    #include <pthread.h>


    #define MYSTRDUP(str,lit) strcpy(str=malloc(strlen(lit)+1),lit)


    struct Poolstruct {
        char *pool [TAMANOPOOL];
        int poolTop;
    } ;

    int pool_add (struct Poolstruct pool_stc, char * URL)
    {
        int index = pool_stc.poolTop;
        pool_stc.pool[index] = URL;
        pool_stc.poolTop ++;

    }
    char * pool_get (struct Poolstruct pool_stc, int index)
    {
        char * poolContent;
        poolContent =  pool_stc.pool[index];
        return poolContent;
    }
    int pool_size (struct Poolstruct pool_stc)

    {
        return pool_stc.poolTop;

    }



