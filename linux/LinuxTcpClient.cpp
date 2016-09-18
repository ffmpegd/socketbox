#include <unistd.h>
#include <sys/socket.h>
#include "LinuxTcpClient.h"


bool LinuxTcpClient::Open(void)
{
	return LinuxTcpSocket::Open();
}
bool LinuxTcpClient::Close(void)
{
	return LinuxTcpSocket::Close();
}
int LinuxTcpClient::SocketDomain(void)
{
	return LinuxTcpSocket::SocketDomain();
}
int LinuxTcpClient::SocketType(void)
{
	return LinuxTcpSocket::SocketType();
}
int LinuxTcpClient::SocketProtocol(void)
{
	return LinuxTcpSocket::SocketProtocol();
}
int LinuxTcpClient::Send(const void* p, const int l)
{
	return LinuxTcpSocket::Send(p, l);
}
int LinuxTcpClient::Recv(void *p, const int l)
{
	return LinuxTcpSocket::Recv(p, l);
}
bool LinuxTcpClient::Send(ISocketBuffer& b)
{
	return LinuxTcpSocket::Send(b);
}
bool LinuxTcpClient::Recv(ISocketBuffer& b)
{
	return LinuxTcpSocket::Recv(b);
}
bool LinuxTcpClient::SendTo(IAddress& a, ISocketBuffer& b)
{
	return LinuxTcpSocket::SendTo(a, b);
}
bool LinuxTcpClient::RecvFrom(IAddress& a, ISocketBuffer& b)
{
	return LinuxTcpSocket::RecvFrom(a, b);
}
void LinuxTcpClient::SetSocketHandler(const SocketHandler& s)
{
	return LinuxTcpSocket::SetSocketHandler(s);
}
const SocketHandler& LinuxTcpClient::GetSocketHandler(void) const
{
	return LinuxTcpSocket::GetSocketHandler();
}
bool LinuxTcpClient::GetSocketName(IAddress& a)
{
	return LinuxTcpSocket::GetSocketName(a);
}
bool LinuxTcpClient::GetPeerName(IAddress& a)
{
	return LinuxTcpSocket::GetPeerName(a);
}

bool LinuxTcpClient::Connect(const IString& ip, int port)
{
	if( false == handler.IsValid() )
	{
		return false;
	}
	INetAddress address(ip, port);
	return (connect(handler.GetHandler(), (const struct sockaddr*)address.GetAddress(), address.GetLength()) == 0);
}
