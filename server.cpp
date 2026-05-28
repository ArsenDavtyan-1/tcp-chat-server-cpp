#include <netinet/in.h>
#include <iostream>
#include <sys/socket.h>
#include <cstdlib>
#include <string>
#include <unistd.h>
#include <arpa/inet.h>
#include "tcp_server.h"


int main()
{
    try{
        TCPServerSocket server;

        server.setSocketOpts();
        server.setSocketAddr();
        server.bindSocket();
    }
    catch(const std::exception& e){
        std::cerr << e.what() << '\n';
        exit(EXIT_FAILURE);
    }
}

// #define PORT 8080

// int main()
// {
//     int server_fd;
//     int client_fd;
//     struct sockaddr_in  server_addr;
//     struct sockaddr_in  client_addr;
//     socklen_t           client_len = sizeof(client_addr);
//     char                server_ip[INET_ADDRSTRLEN];
//     char                client_ip[INET_ADDRSTRLEN];
//     std::string         buffer(1024, '\0');

//     // Variable: opt
//     // Purpose:  For usage in setsockopt function call
//     int opt = 1;

//     try{
//         if((server_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0){
//             throw std::runtime_error("Failed to create server socket");
//         }

//         if(setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt)) < 0){
//             throw std::runtime_error("Failed to set options for server socket");
//         }

//         server_addr.sin_family      = AF_INET;
//         server_addr.sin_port        = htons(PORT);
//         server_addr.sin_addr.s_addr = INADDR_ANY;

//         if(bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0){
//             throw std::runtime_error("Failed to bind server socket with address");
//         }
//         if(listen(server_fd, 5) < 0){
//             throw std::runtime_error("Failed to create server socket listen queue");
//         }
//         if((client_fd = accept(server_fd, (struct sockaddr *)&client_addr, &client_len)) < 0){
//             throw std::runtime_error("Failed to create server socket");
//         }

//         inet_ntop(AF_INET, &server_addr.sin_addr, server_ip, sizeof(server_ip));
//         inet_ntop(AF_INET, &client_addr.sin_addr, client_ip, sizeof(client_ip));

//         printf("Print client ip: %s, port: %d\n", client_ip, ntohs(client_addr.sin_port));
//         printf("Print server ip: %s, port: %d\n", server_ip, ntohs(server_addr.sin_port));

//         if(recv(client_fd, (buffer.data()), buffer.size() - 1, 0) < 0){
//             throw std::runtime_error("Failed to receive client's message");
//         }
//         if(close(server_fd) < 0){
//             throw std::runtime_error("Failed to close server socket in receiver side");
//         }
//         if(close(client_fd) < 0){
//             throw std::runtime_error("Failed to close client socket in receiver side");
//         }
//     } // end of try block
//     catch(const std::exception& e){
//         std::cerr << e.what() << '\n';
//         exit(EXIT_FAILURE);
//     }

//     std::cout << buffer << "\n";

//     return 0;
// }


