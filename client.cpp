#include <iostream>
#include <cstdlib>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string>
#include <unistd.h>

#define PORT 8080

int main()
{
    int                 client_fd;
    struct sockaddr_in  server_addr;
    std::string         message = "Hello from client";
    
    try{
        if((client_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0){
            throw std::runtime_error("Failed to create client socket");
        }
    
        server_addr.sin_family  = AF_INET;
        server_addr.sin_port    = htons(PORT);

        if(inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr) < 0){
            throw std::runtime_error("Failed to connect set server_addr.sin_addr");
        }
    
        if(connect(client_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0){
            throw std::runtime_error("Failed to connect client socket with server socket");
        }
        if(send(client_fd, message.c_str(), message.size(), 0) < 0){
            throw std::runtime_error("Failed to send client's message");
        }
        if(close(client_fd) < 0){
            throw std::runtime_error("Failed to close client socket on sender side");
        }

    } // end of try block
    catch(const std::exception& e){
        std::cerr << e.what() << '\n';
        exit(EXIT_FAILURE);
    }

    return 0;
}