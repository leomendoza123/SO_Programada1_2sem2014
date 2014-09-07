    #include <stdio.h>
    #include <string.h>
    #include "socket.h"
    int main(int argc, char **argv)
    {
        fprintf(stderr, "host: %s\n", argv[1]);
        GetHtml (argv[1]);
    }
