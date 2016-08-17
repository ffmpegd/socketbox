#include <unistd.h>
#include <sys/socket.h>
#include "LinuxTcpClient.h"

bool LinuxTcpClient::Open(void)
{
	handler.SetHandler( socket(SocketDomain(), SocketType(), SocketProtocol()) );
	return handler.IsValid();
}
bool LinuxTcpClient::Close(void)
{
	if( handler.IsValid() )
	{
		close(handler.GetHandler());
		handler.SetHandler(handler.InvalidSocket());
	}
	return !handler.IsValid();
}
int LinuxTcpClient::SocketDomain(void)
{
	return AF_INET;
}
int LinuxTcpClient::SocketType(void)
{
	return SOCK_STREAM;
}
int LinuxTcpClient::SocketProtocol(void)
{
	return 0;
}
bool LinuxTcpClient::Send(ISocketBuffer& b)
{
	if( false == handler.IsValid() || NULL == b.GetData() || b.GetLength() < 1 )
	{
		return false;	
	}
	b.SetResult( send(handler.GetHandler(), b.GetData(), b.GetLength(), 0) );
	return (b.GetResult() > 0);
}
bool LinuxTcpClient::Recv(ISocketBuffer& b)
{
	if( false == handler.IsValid() || NULL == b.GetData() || b.GetSize() < 1 )
	{
		return false;
	}
	b.SetLength( recv(handler.GetHandler(), b.GetData(), b.GetSize(), 0) );
	return (b.GetLength() < 1);
}
bool LinuxTcpClient::SendTo(IAddress& a, ISocketBuffer& b)
{
	return Send(b);
}
bool LinuxTcpClient::RecvFrom(IAddress& a, ISocketBuffer& b)
{
	return Recv(b);
}
void LinuxTcpClient::SetSocketHandler(const SocketHandler& s)
{
	handler = s;
}
const SocketHandler& LinuxTcpClient::GetSocketHandler(void) const
{
	return handler;
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
