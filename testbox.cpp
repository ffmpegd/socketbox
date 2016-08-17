#include "ITcpServer.h"
#include "ITcpClient.h"
#include "INetAddress.h"
#include <cstdio>

int main(int argc, char **argv)
{
	INetAddress address;
	ITcpServer server;

	if( server.Open() )
	{
	}
	printf("address(%d, %d, %s)\n", address.GetDomain(), address.GetPort(), address.GetIp().data());
	address.SetIp("192.168.1.111");
	address.SetPort(2222);
	printf("address(%d, %d, %s)\n", address.GetDomain(), address.GetPort(), address.GetIp().data());

	return 0;
}
