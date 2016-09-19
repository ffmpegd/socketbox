#include <stdlib.h>
#include <signal.h>
#include "NetPacket.h"
#include "ClientManager.h"

void SignalPipe(int sig);
int main(int argc, char **argv)
{
	int port = 3333;
	//IString ip = "192.168.1.186";
	IString ip = "0";
	
	if( argc > 1 )
	{
		ip = argv[1];
	}
	if( argc > 2 )
	{
		port = atoi(argv[2]);
	}

	signal(SIGPIPE, SignalPipe);
	NetPacket::RegisterTrace(printf);
	ClientManager::CreateConnection(ip, port);//"192.168.1.246", 10010);
	ClientManager::RunThread();
	while(1)
	{
		ClientManager::SendString("Source:Board");
		getchar();
	}
	return 0;
}
void SignalPipe(int sig)
{
	printf("%s(%d)\n", __func__, sig);
}
