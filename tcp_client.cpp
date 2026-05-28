#include "tcp_client.h"


void TCPClientSocket::connect(const sockaddr_in& other_addr){
    if(::connect(m_socket_fd, (struct sockaddr*)&other_addr, sizeof(other_addr))){
        throw std::runtime_error("Failed to connect socket");
    }

    return;
}

void TCPClientSocket::send(){
    if(::send(m_socket_fd, m_message.data(), m_message.size() - 1, 0) < 0){
        throw std::runtime_error("Failed to send message");
    }

    return;
}

void TCPClientSocket::setMessage(std::string message){
    m_message = message;

    return;
}

const std::string& TCPClientSocket::getMessage() const{
    return m_message;
}