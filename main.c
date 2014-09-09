    #include <stdio.h>
    #include <string.h>
    #include <pthread.h>
    #include "socket.h"
    #include "manejadorArchivos.h"
    #include "manejadorPool.h"



    int main(int argc, char **argv)
    {

       pool_add ("acme.com") ;
       pool_add ("kli.org") ;
       pool_add ("home.mcom.com") ;
              pool_add ("acme.com") ;
       pool_add ("kli.org") ;
       pool_add ("home.mcom.com") ;
              pool_add ("acme.com") ;
       pool_add ("kli.org") ;
       pool_add ("home.mcom.com") ;
              pool_add ("acme.com") ;
       pool_add ("kli.org") ;
       pool_add ("home.mcom.com") ;

       pool_Inicia ();
       sleep (10);
       //archivos_Inicia ();


        // Espera a que los hilos lectores finalicen
       pool_joinHilosLectores();
       pool_joinHilosEscritores();
       return 0;



    }
