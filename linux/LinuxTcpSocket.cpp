#include <unistd.h>
#include <sys/socket.h>
#include "LinuxTcpSocket.h"


bool LinuxTcpSocket::Open(void)
{
	handler.SetHandler( socket(SocketDomain(), SocketType(), SocketProtocol()) );
	return handler.IsValid();
}
bool LinuxTcpSocket::Close(void)
{
	if( handler.IsValid() )
	{
		close(handler.GetHandler());
		handler.SetHandler(handler.InvalidSocket());
	}
	return !handler.IsValid();
}
int LinuxTcpSocket::SocketDomain(void)
{
	return AF_INET;
}
int LinuxTcpSocket::SocketType(void)
{
	return SOCK_STREAM;
}
int LinuxTcpSocket::SocketProtocol(void)
{
	return 0;
}
int LinuxTcpSocket::Send(const void* p, const int l)
{
	if( false == handler.IsValid() || NULL == p || l < 1 )
	{
		return false;
	}
	return send(handler.GetHandler(), p, l, 0);
}
int LinuxTcpSocket::Recv(void *p, const int l)
{
	if( false == handler.IsValid() || NULL == p || l < 1 )
	{
		return false;
	}
	return recv(handler.GetHandler(), p, l, 0);
}
bool LinuxTcpSocket::Send(ISocketBuffer& b)
{
	if( false == handler.IsValid() || NULL == b.GetData() || b.GetLength() < 1 )
	{
		return false;	
	}
	b.SetResult( send(handler.GetHandler(), b.GetData(), b.GetLength(), 0) );
	return (b.GetResult() > 0);
}
bool LinuxTcpSocket::Recv(ISocketBuffer& b)
{
	if( false == handler.IsValid() || NULL == b.GetData() || b.GetSize() < 1 )
	{
		return false;
	}
	b.SetLength( recv(handler.GetHandler(), b.GetData(), b.GetSize(), 0) );
	return (b.GetLength() > 0);
}
bool LinuxTcpSocket::SendTo(IAddress& a, ISocketBuffer& b)
{
	return Send(b);
}
bool LinuxTcpSocket::RecvFrom(IAddress& a, ISocketBuffer& b)
{
	return Recv(b);
}
void LinuxTcpSocket::SetSocketHandler(const SocketHandler& s)
{
	handler = s;
}
const SocketHandler& LinuxTcpSocket::GetSocketHandler(void) const
{
	return handler;
}
bool LinuxTcpSocket::GetSocketName(IAddress& a)
{
	if( false == handler.IsValid() )
	{
		return false;
	}
	socklen_t len = a.GetLength();
	return (getsockname(handler.GetHandler(), (struct sockaddr*)a.GetAddress(), &len)==0);
}
bool LinuxTcpSocket::GetPeerName(IAddress& a)
{
	if( false == handler.IsValid() )
	{
		return false;
	}
	socklen_t len = a.GetLength();
	return (getpeername(handler.GetHandler(), (struct sockaddr*)a.GetAddress(), &len)==0);
}

