#ifndef POOL_H_INCLUDED
#define POOL_H_INCLUDED
#define TAMANOPOOL 100

   struct Poolstruct {
        char *pool [TAMANOPOOL];
        int poolTop ;
        int poolCounter ;
        int id;
    } ;


     int pool_add (struct Poolstruct *pool_stc, char * URL) ;
    char * pool_getIndex (struct Poolstruct *pool_stc, int index);
    int pool_getSize (struct Poolstruct *pool_stc);

#endif // POOL_H_INCLUDED
