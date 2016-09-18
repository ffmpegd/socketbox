#include <stdio.h>
#include "SocketBuffer.h"
#include "LinuxTcpInfo.h"
#include "LinuxTcpServer.h"
#include "LinuxSocketOption.h"

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
	LinuxTcpInfo info;
	while(server.GetSocketHandler().IsValid())
	{
		char c = getchar();
		if( worker.Send(&c, 1) == 1 )
		{
			continue;
		}
		if( worker.GetSocketHandler().IsValid() )
		{
			info.GetInfo(worker);
			if( info.GetState() != 1 )
			{
				worker.Close();
			}
		}
		if( !worker.GetSocketHandler().IsValid() )
		{
			server.Accept(worker);
		}
	}
	return 0;
}
