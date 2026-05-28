#include "tcp_server.h"

void TCPServerSocket::bindSocket(){
    setSocketAddr();
    if(bind(m_socket_fd, (struct sockaddr*)&m_addr, sizeof(m_addr)) < 0){
        throw std::runtime_error("Failed to bind socket");
    }

    return;
}