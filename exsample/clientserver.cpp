#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include "PacketMaker.h"
#include "SocketBuffer.h"
#include "LinuxTcpInfo.h"
#include "LinuxTcpServer.h"
#include "LinuxSocketOption.h"

void SignalPipe(int sig);
int main(int argc, char **argv)
{
	int port = 3333;
	IString ip = "0.0.0.0";
	LinuxTcpServer server;
	LinuxTcpServer worker;
	LinuxSocketOption option;

	if( argc > 1 )
	{
		ip = argv[1];
	}
	if( argc > 3 )
	{
		port = atoi(argv[2]);
	}

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
	if( !server.Bind(ip, port) )
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
	signal(SIGPIPE, SignalPipe);
	NetPacket::RegisterTrace(printf);
	while(server.GetSocketHandler().IsValid())
	{
		char c = getchar();
		if( worker.Send(&c, 1) == 1 )
		{
			PacketMaker p;
			IString s = "{\"Id\":\"0000000001\", \"Time\":\"82323829323\"}";
			p.MakePacket(s.data(), 0, s.length());
			if( worker.Send(p.GetData(), p.GetLength()+4) > 0 )
			{
				p.ShowString();
			}
			else
			{
				printf("Send failed(%d)\n", __LINE__);
				worker.Close();
			}
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
void SignalPipe(int sig)
{
	printf("%s(%d)\n", __func__, sig);
}
