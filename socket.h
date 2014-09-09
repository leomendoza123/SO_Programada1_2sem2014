
#ifndef socket_H_   /* Include guard */
#define socket_H_
    char * socket_getHtml(char *argv, char *PAGE);
    int create_tcp_socket();
    char *get_ip(char *host);
    char *build_get_query(char *host, char *page);
    void usage();
#endif
