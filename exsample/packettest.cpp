#include <stdio.h>
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

	client.Open();
	client.Connect("192.168.1.246", 10010);

	while(1)
	{
		NetPacket p;
		IString s = "Source:Board";
		p.MakePacket(s.data(), 0x00, s.length());
		printf("Send(%d)\n", client.Send(p.GetData(), p.GetLength()) );
		getchar();
	}
}
