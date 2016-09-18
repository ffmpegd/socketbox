#ifndef __LINUX_TCP_SERVER_H__
#define __LINUX_TCP_SERVER_H__
#include "ITcpServer.h"
#include "INetAddress.h"
#include "LinuxTcpSocket.h"

class LinuxTcpServer : public LinuxTcpSocket, public ITcpServer
{
public:
	bool Open(void);
	bool Close(void);

	int Send(const void*, const int);
	int Recv(void*, const int);

	bool Send(ISocketBuffer&);
	bool Recv(ISocketBuffer&);

	bool SendTo(IAddress&, ISocketBuffer&);
	bool RecvFrom(IAddress&, ISocketBuffer&);

	void SetSocketHandler(const SocketHandler&);
	const SocketHandler& GetSocketHandler(void)const;

	bool GetPeerName(IAddress&);
	bool GetSocketName(IAddress&);

	int SocketDomain(void);
	int SocketType(void);
	int SocketProtocol(void);

public:
	bool Bind(const class IString &ip, int port);
	bool Listen(int backlog);
	bool Accept(class ISocket &s);
};

#endif//__LINUX_TCP_SERVER_H__
