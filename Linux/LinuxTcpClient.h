#ifndef __TCP_LINUX_CLIENT_H__
#define __TCP_LINUX_CLIENT_H__
#include "ITcpClient.h"
#include "INetAddress.h"

class LinuxTcpClient : public ITcpClient
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
	const SocketHandler& GetSocketHandler(void)const;
	int SocketDomain(void);
	int SocketType(void);
	int SocketProtocol(void);

	bool Connect(const IString& ip, int port);
};

#endif//__TCP_LINUX_CLIENT_H__
