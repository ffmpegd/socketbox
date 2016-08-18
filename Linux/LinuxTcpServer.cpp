#include <unistd.h>
#include <sys/socket.h>
#include "LinuxTcpServer.h"

bool LinuxTcpServer::Open(void)
{
	handler.SetHandler( socket(SocketDomain(), SocketType(), SocketProtocol()) );
	return handler.IsValid();
}
bool LinuxTcpServer::Close(void)
{
	if( handler.IsValid() )
	{
		close(handler.GetHandler());
		handler.SetHandler(handler.InvalidSocket());
	}
	return !handler.IsValid();
}
int LinuxTcpServer::SocketDomain(void)
{
	return AF_INET;
}
int LinuxTcpServer::SocketType(void)
{
	return SOCK_STREAM;
}
int LinuxTcpServer::SocketProtocol(void)
{
	return 0;
}
int LinuxTcpServer::Send(const void* p, const int l)
{
	if( false == handler.IsValid() || NULL == p || l < 1 )
	{
		return false;
	}
	return send(handler.GetHandler(), p, l, 0);
}
int LinuxTcpServer::Recv(void *p, const int l)
{
	if( false == handler.IsValid() || NULL == p || l < 1 )
	{
		return false;
	}
	return recv(handler.GetHandler(), p, l, 0);
}
bool LinuxTcpServer::Send(ISocketBuffer& b)
{
	if( false == handler.IsValid() || NULL == b.GetData() || b.GetLength() < 1 )
	{
		return false;	
	}
	b.SetResult( send(handler.GetHandler(), b.GetData(), b.GetLength(), 0) );
	return (b.GetResult() > 0);
}
bool LinuxTcpServer::Recv(ISocketBuffer& b)
{
	if( false == handler.IsValid() || NULL == b.GetData() || b.GetSize() < 1 )
	{
		return false;
	}
	b.SetLength( recv(handler.GetHandler(), b.GetData(), b.GetSize(), 0) );
	return (b.GetLength() > 0);
}
bool LinuxTcpServer::SendTo(IAddress& a, ISocketBuffer& b)
{
	return Send(b);
}
bool LinuxTcpServer::RecvFrom(IAddress& a, ISocketBuffer& b)
{
	return Recv(b);
}
void LinuxTcpServer::SetSocketHandler(const SocketHandler& s)
{
	handler = s;
}
const SocketHandler& LinuxTcpServer::GetSocketHandler(void) const
{
	return handler;
}
bool LinuxTcpServer::GetSocketName(IAddress& a)
{
	if( false == handler.IsValid() )
	{
		return false;
	}
	socklen_t len = a.GetLength();
	return (getsockname(handler.GetHandler(), (struct sockaddr*)a.GetAddress(), &len)==0);
}
bool LinuxTcpServer::GetPeerName(IAddress& a)
{
	if( false == handler.IsValid() )
	{
		return false;
	}
	socklen_t len = a.GetLength();
	return (getpeername(handler.GetHandler(), (struct sockaddr*)a.GetAddress(), &len)==0);
}
bool LinuxTcpServer::Bind(const class IString &ip, int port)
{
	if( false == handler.IsValid() )
	{
		return false;
	}
	INetAddress address(ip, port);
	return (bind(handler.GetHandler(), (const struct sockaddr*)address.GetAddress(), address.GetLength()) == 0);
}
bool LinuxTcpServer::Listen(int backlog)
{
	if( false == handler.IsValid() )
	{
		return false;
	}
	return (listen(handler.GetHandler(), backlog) == 0);
}
bool LinuxTcpServer::Accept(class ISocket &s)
{
	if( false == handler.IsValid() || s.SocketDomain() != SocketDomain() )
	{
		return false;
	}
	INetAddress a;
	int retlen = a.GetLength();
	s.SetSocketHandler( SocketHandler(accept(handler.GetHandler(), (struct sockaddr*)a.GetAddress(), (socklen_t*)&retlen)) );
	return s.GetSocketHandler().IsValid();
}

