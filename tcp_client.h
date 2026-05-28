// Wrapper class for client socket
#ifndef TCP_CLIENT_H
#define TCP_CLIENT_H

#include "tcp_socket.h"

class TCPClientSocket : public TCPSocket
{
public:
    void                send();
    void                connect(const sockaddr_in& other_addr);
    void                setMessage(std::string message);
    const std::string&  getMessage() const;

private:
    std::string m_message;
}




#endif // !TCP_CLIENT_H