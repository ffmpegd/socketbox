#include <stdio.h>
#include <stdlib.h>
#include "NetPacket.h"
#include "SocketBuffer.h"
#include "LinuxTcpInfo.h"
#include "LinuxTcpOption.h"
#include "LinuxSocketOption.h"
#include "LinuxTcpClient.h"


int main(int argc, char **argv)
{
	LinuxTcpInfo info;
	LinuxTcpClient client;

	int port = 10010;
	IString ip = "192.168.1.186";

	client.Open();
	if( argc > 1 )
	{
		ip = argv[1];
	}
	if( argc > 2 )
	{
		port = atoi(argv[2]);
	}
	client.Connect(ip, port);

	while(1)
	{
		NetPacket p;
		IString s = "Source:Board";
		p.MakePacket(s.data(), 0x00, s.length());
		printf("Send(%d)\n", client.Send(p.GetData(), p.GetLength()+4) );
		p.ShowData();
		getchar();
	}
}
