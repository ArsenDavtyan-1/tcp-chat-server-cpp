// Wrapper class for server socket
#ifndef TCP_SERVER_H
#define TCP_SERVER_H

#include <map>
#include "tcp_socket.h"

class TCPServerSocket : public TCPSocket
{
public:
    TCPServerSocket() : TCPSocket(), opt(1) {}
    void bindSocket();
    void setSocketOpts();
    void listen(size_t size);
    void accept();
    void connect();

private:
    int opt;
    std::map<int, sockaddr_in> clients;
};


#endif //!TCP_SERVER_H