#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>

#define PORT 8080

int main()
{
    int                 client_fd;
    struct sockaddr_in  server_addr;
    const char*         message = "Hello from client";
    
    if((client_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0){
        perror("Failed to create client socket in client.cpp");
        exit(EXIT_FAILURE);
    }

    server_addr.sin_family  = AF_INET;
    server_addr.sin_port    = htons(PORT);
    if(inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr) < 0){
        perror("Failed to connect set server_addr.sin_addr");
        exit(EXIT_FAILURE);
    }
    

    if(connect(client_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0){
        perror("Failed to connect client socket with server socket");
        exit(EXIT_FAILURE);
    }

    if(send(client_fd, message, strlen(message), 0) < 0){
        perror("Failed to send client's message");
        exit(EXIT_FAILURE);
    }

    close(client_fd);
    return 0;
}