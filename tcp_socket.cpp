#include "tcp_socket.h"

TCPSocket::TCPSocket(){
    m_socket_fd = socket(AF_INET, SOCK_STREAM, 0);

    if(m_socket_fd < 0){
        throw std::runtime_error("Failed to create socket");
    }

    return;
}

TCPSocket::~TCPSocket() noexcept{
    close(m_socket_fd);
    m_socket_fd = -1;
}

int TCPSocket::getSocketFd(){
    return m_socket_fd;
}

void TCPSocket::setSocketAddr(){
    m_addr.sin_family       = AF_INET;
    m_addr.sin_port         = htons(PORT);
    m_addr.sin_addr.s_addr  = INADDR_ANY;
}

const sockaddr_in& TCPSocket::getSocketAddr(){
    return m_addr;
}

void TCPSocket::bufferResize(size_t new_size){
    m_buffer.resize(new_size, '\0');
}

void TCPSocket::receive(int remote_socket_fd){
    if(recv(remote_socket_fd, m_buffer.data(), m_buffer.size() - 1, 0) < 0){
        throw std::runtime_error("Failed to receive data");
    }
}

void TCPSocket::printSocket(){
    char socket_ip[INET_ADDRSTRLEN];

    inet_ntop(AF_INET, &m_addr.sin_addr, socket_ip, sizeof(socket_ip));

    std::cout << "Socket ip: " << socket_ip << "\nSocket port: " << ntohs(m_addr.sin_port) << "\n";

    return;
}