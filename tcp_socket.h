// Wrapper class for tcp socket
#ifndef TCP_SOCKET_H
#define TCP_SOCKET_H

#include <iostream>
#include <stdexcept>
#include <string>
#include "sys/socket.h" // for socket()
#include "unistd.h"     // for socket close()
#include "netinet/in.h" // for sockaddr_in
#include "arpa/inet.h"  // for inet_ntop()

#define PORT 8080

class TCPSocket
{
public:
                                TCPSocket();
    virtual                     ~TCPSocket() noexcept;
    int                         getSocketFd();
    virtual void                setSocketAddr();
    virtual const sockaddr_in&  getSocketAddr();
    void                        bufferResize(size_t new_size);
    void                        receive(int remote_socket_fd);
    void                        printSocket();

protected:
    int         m_socket_fd;
    std::string m_buffer;
    sockaddr_in m_addr;
};


#endif // !TCP_SOCKET_H