#include "tcp_server.h"

void TCPServerSocket::bindSocket(){
    if(bind(m_socket_fd, (struct sockaddr*)&m_addr, sizeof(m_addr)) < 0){
        throw std::runtime_error("Failed to bind socket");
    }

    return;
}


void TCPServerSocket::setSocketOpts(){
    if(setsockopt(m_socket_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt)) < 0){
        throw std::runtime_error("Failed to set socket options");
    }

    return;
}


void TCPServerSocket::listen(size_t size){
    if(::listen(m_socket_fd, size) < 0){
        throw std::runtime_error("Failed to create server listen queue");
    }

    return;
}


void TCPServerSocket::accept(){
    sockaddr_in client_addr;
    socklen_t   client_len = sizeof(client_addr);
    int         client_fd  = ::accept(m_socket_fd, (struct sockaddr*)&client_addr, &client_len);
    
    if(client_fd < 0){
        throw std::runtime_error("Failed to accept client");
    }

    clients[client_fd] = client_addr;

    return;
}