#ifndef __TCP_LINUX_CLIENT_H__
#define __TCP_LINUX_CLIENT_H__
#include "INetAddress.h"
#include "ITcpClient.h"
#include "LinuxTcpSocket.h"

class LinuxTcpClient : public LinuxTcpSocket, public ITcpClient
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
	bool Connect(const IString& ip, int port);
};

#endif//__TCP_LINUX_CLIENT_H__
