#include "SocketBuffer.h"
#include "LinuxTcpServer.h"
#include "LinuxSocketOption.h"
#include <cstdio>

int main(int argc, char **argv)
{
	LinuxTcpServer server;
	LinuxTcpServer worker;
	LinuxSocketOption option;

	if( !server.Open() )
	{
		printf("server.Open() failed!\n");
		return -1;
	}
	if( !option.AttachSocket(server) )
	{
		printf("option.AttachSocket().InvalidSocket!\n");
		return -1;
	}
	if( !option.EnableReuseAddress() )
	{
		printf("option.EnableReuseAddress() failed!\n");
		perror("option.EnableReuseAddress()");
		return -1;
	}
	if( !server.Bind("0.0.0.0", 3333) )
	{
		printf("server.Bind() failed!\n");
		perror("server.Bind()");
		return -1;
	}
	if( !server.Listen(1) )
	{
		printf("server.Listen() failed!\n");
		return -1;
	}
	if( !server.Accept(worker) )
	{
		printf("server.Accept() failed!\n");
		return -1;
	}
	option.AttachSocket(worker);
	option.EnableBlock();
	INetAddress address;
	worker.GetSocketName(address);
	printf("socketname(%s,%d)\n", address.GetIp().data(), address.GetPort());
	worker.GetPeerName(address);
	printf("socketname(%s,%d)\n", address.GetIp().data(), address.GetPort());
	int e = 0;
	while(option.GetSocketError(e))
	{
		if( 0 != e )
		{
			printf("SocketError=%d\n", e);
			break;
		}
		SocketBuffer sb(32);
		if( !worker.Recv(sb) )
		{
			perror("worker.Recv()");
			break;
		}
		if( !worker.Send(sb) )
		{
			perror("worker.Send()");
			break;
		}
		printf("SocketError=%d\n", e);
	}
	printf("SocketError=%d\n", e);
	perror("option.GetSocketError()");

	return 0;
}
