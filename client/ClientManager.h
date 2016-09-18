#ifndef __CLIENTMANAGER_H__
#define __CLIENTMANAGER_H__
#include "ByteQueue.h"
#include "INetAddress.h"
#include "LinuxTcpClient.h"

class ClientManager
{
private:
	static ByteQueue queue;
	static INetAddress address;
	static LinuxTcpClient client;

public:
	static bool RunThread(void);
	static void* ThreadEntry(void*);
	static bool CreateConnection(const IString&, int);
	static bool DestroyConnection(void);
	static bool DisassemblyPacket(void);
	static bool Reconnect(void);
	static bool SendString(const IString&);
};

#endif//__CLIENTMANAGER_H__
