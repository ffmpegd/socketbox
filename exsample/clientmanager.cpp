#include <stdlib.h>
#include "ClientManager.h"

int main(int argc, char **argv)
{
	int port = 10010;
	IString ip = "192.168.1.186";
	
	if( argc > 1 )
	{
		ip = argv[1];
	}
	if( argc > 2 )
	{
		atoi(argv[2]);
	}

	ClientManager::CreateConnection(ip, port);//"192.168.1.246", 10010);
	ClientManager::RunThread();
	while(1)
	{
		ClientManager::SendString("Source:Board");
		getchar();
	}
	return 0;
}
