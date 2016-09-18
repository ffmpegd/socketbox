#ifndef __LINUX_TCP_SOCKET_H__
#define __LINUX_TCP_SOCKET_H__
#include "INetAddress.h"
#include "SocketHandler.h"
#include "ISocketBuffer.h"

class LinuxTcpSocket
{
protected:
	SocketHandler handler;

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
};

#endif//__LINUX_TCP_SOCKET_H__
