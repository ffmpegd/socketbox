#include <cstdio>
#include "SocketBuffer.h"
#include "LinuxTcpClient.h"

int main(int argc, char **argv)
{
	LinuxTcpClient client;
	SocketBuffer b("SocketBuffer\n");

	if( false == client.Open() )
	{
		printf("client.Open() failed!\n");
		return -1;
	}
	if( false == client.Connect("0.0.0.0", 3333) )
	{
		printf("client.Connect() failed!\n");
		perror("client.Connect()");
		return -1;
	}
	client.Send(b);
	while(1)
	{
		SocketBuffer sb(32);
		client.Recv(sb);
		printf("sb.GetSize(%d).GetLength(%d).GetResult(%d)\n", sb.GetSize(), sb.GetLength(), sb.GetResult());
		client.Send(sb);
	}

	return 0;
}
