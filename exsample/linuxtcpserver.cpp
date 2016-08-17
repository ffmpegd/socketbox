#include "LinuxTcpServer.h"
#include "SocketBuffer.h"
#include <cstdio>

int main(int argc, char **argv)
{
	INetAddress address;
	LinuxTcpServer server;
	LinuxTcpServer worker;
	SocketBuffer b("SocketBuffer\n");

	if( !server.Open() )
	{
		printf("server.Open() failed!\n");
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
	while(1)
	{
		SocketBuffer sb(32);
		worker.Recv(sb);
		perror("worker.Recv()");
		worker.Send(sb);
		perror("worker.Send()");
	}
	printf("address(%d, %d, %s)\n", address.GetDomain(), address.GetPort(), address.GetIp().data());
	address.SetIp("192.168.1.111");
	address.SetPort(2222);
	printf("address(%d, %d, %s)\n", address.GetDomain(), address.GetPort(), address.GetIp().data());

	return 0;
}
