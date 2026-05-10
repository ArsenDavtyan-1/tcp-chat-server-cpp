#include <netinet/in.h>
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080

int main()
{
    int server_fd;
    int client_fd;
    struct sockaddr_in server_addr;
    struct sockaddr_in client_addr;
    socklen_t          client_len = sizeof(client_addr);
    char               client_ip[INET_ADDRSTRLEN];
    char               buffer[1024] = {0};

    if((server_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0){
        perror("Failed to create server socket");
        exit(EXIT_FAILURE);
    }


    server_addr.sin_family      = AF_INET;
    server_addr.sin_port        = htons(PORT);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    if(bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0){
        perror("Failed to bind server socket with address");
        exit(EXIT_FAILURE);
    }
    if(listen(server_fd, 5) < 0){
        perror("Failed to create server socket listen queue");
        exit(EXIT_FAILURE);
    }
    if((client_fd = accept(server_fd, (struct sockaddr *)&client_addr, &client_len)) < 0){
        perror("Failed to create server socket");
        exit(EXIT_FAILURE);
    }
    inet_ntop(AF_INET, &client_addr.sin_addr, client_ip, sizeof(client_ip));
    printf("Print clinet ip: %s, port: %d\n", client_ip, ntohs(client_addr.sin_port));

    if(recv(client_fd, buffer, sizeof(buffer), 0) < 0){
        perror("Failed to recv client's message");
        exit(EXIT_FAILURE);
    }

    printf("%s\n", buffer);

    close(server_fd);
    close(client_fd);

    return 0;
}


