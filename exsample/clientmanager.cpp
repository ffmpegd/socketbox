#include "ClientManager.h"

int main(int argc, char **argv)
{
	ClientManager::CreateConnection("192.168.1.246", 10010);
	ClientManager::RunThread();
	while(1)
	{
		getchar();
	}
	return 0;
}
