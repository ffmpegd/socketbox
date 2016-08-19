#include <unistd.h>
#include <sys/socket.h>
#include "LinuxTcpServer.h"

bool LinuxTcpServer::Open(void)
{
	return LinuxTcpSocket::Open();
}
bool LinuxTcpServer::Close(void)
{
	return LinuxTcpSocket::Close();
}
int LinuxTcpServer::SocketDomain(void)
{
	return LinuxTcpSocket::SocketDomain();
}
int LinuxTcpServer::SocketType(void)
{
	return LinuxTcpSocket::SocketType();
}
int LinuxTcpServer::SocketProtocol(void)
{
	return LinuxTcpSocket::SocketProtocol();
}
int LinuxTcpServer::Send(const void* p, const int l)
{
	return LinuxTcpSocket::Send(p, l);
}
int LinuxTcpServer::Recv(void *p, const int l)
{
	return LinuxTcpSocket::Recv(p, l);
}
bool LinuxTcpServer::Send(ISocketBuffer& b)
{
	return LinuxTcpSocket::Send(b);
}
bool LinuxTcpServer::Recv(ISocketBuffer& b)
{
	return LinuxTcpSocket::Recv(b);
}
bool LinuxTcpServer::SendTo(IAddress& a, ISocketBuffer& b)
{
	return LinuxTcpSocket::SendTo(a, b);
}
bool LinuxTcpServer::RecvFrom(IAddress& a, ISocketBuffer& b)
{
	return LinuxTcpSocket::RecvFrom(a, b);
}
void LinuxTcpServer::SetSocketHandler(const SocketHandler& s)
{
	return LinuxTcpSocket::SetSocketHandler(s);
}
const SocketHandler& LinuxTcpServer::GetSocketHandler(void) const
{
	return LinuxTcpSocket::GetSocketHandler();
}
bool LinuxTcpServer::GetSocketName(IAddress& a)
{
	return LinuxTcpSocket::GetSocketName(a);
}
bool LinuxTcpServer::GetPeerName(IAddress& a)
{
	return LinuxTcpSocket::GetPeerName(a);
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

