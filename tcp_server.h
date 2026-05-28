// Wrapper class for server socket
#ifndef TCP_SERVER_H
#define TCP_SERVER_H


#include "tcp_socket.h"

class TCPServerSocket : public TCPSocket
{
public:
    void bindSocket();
};


#endif //!TCP_SERVER_H