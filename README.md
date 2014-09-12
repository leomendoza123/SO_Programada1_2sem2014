>>>>> Descripcion 
Este proyecto, se conecta a uno o muchos URLS y desarga el html.
Usa K hilos lectores, cada uno con un pool (lista de urls)
Usa K escritores a disco duro
Estos hilos se comunican por medio de un CACHE
Los URLs se agregan a los pools de los hilos lectores por medio de un balanceador de carga 


>>>>> Correr el codigo 

El codigo viene con los archivos de proyecto de Code::Blocks por lo que es más facil correr el codigo con este programa. 


>>>>>DEFINICIÓN DE ESTRUCTURAS DE DATOS

>>Sockets.c
    
Este código maneja la conexión al los servidores de las páginas web. Primero solicita el IP, y con este código. Para hacer uso de este simplemente se llama por medio de socket_getHtml(char *argv, char *PAGE). Este va a devolver la dirección en memoria donde se encuentra un arreglo de characters con el contenido del html de la pagina web. 
Esta forma de conección reporta problemas cuando se le llama constantemente y no funcionan bien con los sitios web modernos y no funciona correctamente con la descarga de imágenes. 

>>Cache.c

Esta estructura maneja la lista del cache. Esta hace el uso de mutex (semáforos) para poder compartir el caché entre los diferentes hilos. 

int cache_add (char *archivo, char *nombre)
char * cache_get (int index)
    
>>Pool.c

Un simple manejo de un structE este struct contiene: 
Un arreglo de arreglo de char (el pool) 
PoolTop un int con el top de de el arreglo 
PoolCounter la posición actual de pool 



>>ListaPools.c

Manejo de una lista de pools. Cada hilo de conexión es poseedor de uno de estos pools. Esta lista permite que el balanceador de carga pueda revisar los pools de cada hilo. 

>>BalanceadorCarga.c

Se encarga de recibir los nuevos urls y agregarlos a un pool. Este selecciona el pool optimo escogiendo cual es el que tienen menos urls pendientes. 

>>ManejadorArchivos

Este maneja la creación el el comportamiento de K hilos para escribir los archivos. Cada uno de estos hilos están constantemente revisando el cache y en caso de que exista algún elemento pendiente por escribir este realizará la escritura. 

>>ManejadorConexion

Maneja la creación de diferentes hilos y los liga con un pool propio. Estos hilos están constantemente revisando el pool, cuando existe un elemento pendiente estos crean un socket y descarga el contenido del URL, este contenido lo guardará en el cache. 





>>>>>Referecias

Uso de punteros
http://stackoverflow.com/questions/2094666/pointers-in-c-when-to-use-the-ampersand-and-the-asterisk
Tcp  http client
http://coding.debuntu.org/c-linux-socket-programming-tcp-simple-http-client
print
http://www.tutorialspoint.com/c_standard_library/c_function_fprintf.htm
hilos
http://www.yolinux.com/TUTORIALS/LinuxTutorialPosixThreads.html
Calloc y Malloc
http://www.diffen.com/difference/Calloc_vs_Malloc
Uso de structs como argumentos, entre archivos
http://stackoverflow.com/questions/6316987/should-struct-definitions-go-in-h-or-c-file

>>>>>> Logrado: 

    El manejo de escritura de archivos
    El manejo de hilos (de connexion)
        con un pool diferente cada uno
        con balanceador de carga, entre pools
        escribiendo resultados en cache
    El manejo de hilos (de escritura)
        todos los hilos leen del cache
    El manejo del cache
        todos los hilos de escritura y de lectura se conectan por medio del cache
    El manejo de socket de conexion
        *** Errores con ciertas paginas
        *** No se hace el parceo de pagina
            Solo se puede bajar la pagina principal (la primera)
            Solo se pueden ver sitios web viejos, facebook y google por ejemplo necesita otro tipo de socket



>>>>>> TODO

Revisar el los sockets



 
