#ifndef __LINUX_TCP_SERVER_H__
#define __LINUX_TCP_SERVER_H__
#include "../ITcpServer.h"

class LinuxTcpServer : public ITcpServer
{
private:
	SocketHandler handler;

public:
	bool Open(void);
	bool Close(void);
	bool Send(ISocketBuffer&);
	bool Recv(ISocketBuffer&);
	bool SendTo(IAddress&, ISocketBuffer&);
	bool RecvFrom(IAddress&, ISocketBuffer&);
	void SetSocketHandler(const SocketHandler&);
	SocketHandler& GetSocketHandler(void);
	int SocketDomain(void);
	int SocketType(void);
	int SocketProtocol(void);

	bool Bind(const class IString &ip, int port);
	bool Listen(int backlog);
	bool Accept(class ISocket &s);
};

#endif//__LINUX_TCP_SERVER_H__
