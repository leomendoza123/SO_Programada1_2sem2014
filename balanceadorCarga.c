#include <stdio.h>
#include <string.h>
#include "listaPool.h"
 #include "pool.h"
int PoolstructMasVacia ();

int balanceador_AgregaURL (char *URL){

    int PoolstructOptimo = PoolstructMasVacia ();
    struct Poolstruct *ps;
    ps  =   listaPools_getPoolstruct(PoolstructOptimo);
    pool_add(ps, URL);
    printf("(B)***** %s en el pool del hilo %d \n", URL, PoolstructOptimo);
    int x = 3;

}

int PoolstructMasVacia (){
    struct Poolstruct **ListaPS = listaPools_getlistaPools ();
    int totalListas = listaPools_getlistaPoolTop ();
    int x;
    int MasVacia = 0;
    int MenorCantidadPendiente = -1;

    for (x=0; x<totalListas; x++){
        struct Poolstruct *PS = ListaPS[x];
        if (PS->poolTop == 0){ /// En caso de que un POOL no tenga nada
            return x;
        }
        else if (MenorCantidadPendiente ==-1){ /// En caso de que sea el primer POOL que revisa
            MenorCantidadPendiente = PS->poolTop - PS->poolCounter;
            MasVacia = x;

        }
        else if (MenorCantidadPendiente > PS->poolTop - PS->poolCounter){ /// El que tenga menos URLs pendientes
            MasVacia = x;
            MenorCantidadPendiente = PS->poolTop - PS->poolCounter;


        }
        }
        if (MasVacia == -1) {
            return 0;
        }
        else return MasVacia;

}
