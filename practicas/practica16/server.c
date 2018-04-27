#include <stdio.h>
#include <sys/socket.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>


// instrucciones: correr el programa compilado. despues en otra terminal usar telnet localhost 5000

int main(){ 
    struct sockaddr_in serverAddres;
    int serverSocket;
    int clientSocket;
    char clientMsg[1000];
    char *hello = "hello world";


    serverSocket = socket(PF_INET, SOCK_STREAM, 0);
    
    memset(&serverAddres, '0', sizeof(serverAddres));
    serverAddres.sin_family = AF_INET;
    serverAddres.sin_addr.s_addr = htonl(INADDR_ANY);
    serverAddres.sin_port = htons(5000);
    bind(serverSocket, (struct sockaddr *)&serverAddres, sizeof(serverAddres));
    listen(serverSocket, 10);
    while(1){
        clientSocket = accept(serverSocket, (struct sockaddr*)NULL,NULL);
        write(clientSocket, hello, strlen(hello));
        read(clientSocket, clientMsg, 1000);
        printf("El cliente dice %s\n", clientMsg);
        close(clientSocket);
    }
    return 0;
}