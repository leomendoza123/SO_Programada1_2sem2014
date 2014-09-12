    #include <stdio.h>
    #include <string.h>
    #include <pthread.h>
    #include "socket.h"
    #include "manejadorArchivos.h"
    #include "manejadorConexiones.h"
    #include "balanceadorCarga.h"



    int main(int argc, char** argv)
    {


        char *url;
        char *host;

        if(argc == 1 && argv[1])
        {
            url = argv[1];
            balanceador_AgregaURL(url);
        }

       sleep (1);


        balanceador_AgregaURL("acme.com");
        balanceador_AgregaURL("kli.org");
       balanceador_AgregaURL("home.mcom.com");
        balanceador_AgregaURL("acme.com");

        sleep (5);

        archivos_Inicia ();


        sleep (5);
        balanceador_AgregaURL("arngren.net");
        balanceador_AgregaURL("dpgraph.com");
        balanceador_AgregaURL("pacificgrandprix.com");
        balanceador_AgregaURL("park.org");

         sleep (5);

        balanceador_AgregaURL("agroweb.com");
        balanceador_AgregaURL("dpgraph.com");
        balanceador_AgregaURL("westnet.com");





       conexiones_joinHilos();
       archivos_joinHilos();
       return 0;



    }
