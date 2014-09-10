    #include <stdio.h>
    #include <string.h>
    #include <pthread.h>
    #include "socket.h"
    #include "manejadorArchivos.h"
    #include "manejadorConexiones.h"



    int main(int argc, char **argv)
    {
       conexiones_add ("acme.com") ;
       conexiones_add ("kli.org") ;
       conexiones_add ("home.mcom.com") ;


       conexiones_Inicia ();
       sleep (10);
       //archivos_Inicia ();


        // Espera a que los hilos lectores finalicen
       conexiones_joinHilos();
       archivos_joinHilos();
       return 0;



    }
