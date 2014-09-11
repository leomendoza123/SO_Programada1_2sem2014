    #include <stdio.h>
    #include <string.h>
    #include <pthread.h>
    #include "socket.h"
    #include "manejadorArchivos.h"
    #include "manejadorConexiones.h"
    #include "balanceadorCarga.h"



    int main(int argc, char **argv)
    {
       conexiones_Inicia ();
       //archivos_Inicia ();
       sleep (1);
       balanceador_AgregaURL("acme.com");
        balanceador_AgregaURL("kli.org");
       balanceador_AgregaURL("home.mcom.com");
              balanceador_AgregaURL("acme.com");
        balanceador_AgregaURL("kli.org");
       balanceador_AgregaURL("home.mcom.com");
              balanceador_AgregaURL("acme.com");
        balanceador_AgregaURL("kli.org");
       balanceador_AgregaURL("home.mcom.com");
              balanceador_AgregaURL("acme.com");
        balanceador_AgregaURL("kli.org");
       balanceador_AgregaURL("home.mcom.com");
              balanceador_AgregaURL("acme.com");
        balanceador_AgregaURL("kli.org");
       balanceador_AgregaURL("home.mcom.com");
              balanceador_AgregaURL("acme.com");
        balanceador_AgregaURL("kli.org");
       balanceador_AgregaURL("home.mcom.com");
              balanceador_AgregaURL("acme.com");
        balanceador_AgregaURL("kli.org");
       balanceador_AgregaURL("home.mcom.com");



        // Espera a que los hilos lectores finalicen
       conexiones_joinHilos();

       //archivos_joinHilos();
       return 0;



    }
