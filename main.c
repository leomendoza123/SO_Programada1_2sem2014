    #include <stdio.h>
    #include <string.h>
    #include "socket.h"
    #include "manejadorArchivos.h"

    #define TamañoCache 1000;

    int main(int argc, char **argv)
    {
        char * html = GetHtml ("www.google.com", "/");
        fprintf(stdout, html);





    }
