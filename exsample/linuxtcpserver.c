#include "LinuxTcpServer.h"
#include "INetAddress.h"
#include <cstdio>

int main(int argc, char **argv)
{
	INetAddress address;
	LinuxTcpServer server;
	LinuxTcpServer worker;
	ISocketBuffer buf;

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
	worker.Send(buf);
	printf("address(%d, %d, %s)\n", address.GetDomain(), address.GetPort(), address.GetIp().data());
	address.SetIp("192.168.1.111");
	address.SetPort(2222);
	printf("address(%d, %d, %s)\n", address.GetDomain(), address.GetPort(), address.GetIp().data());

	return 0;
}
