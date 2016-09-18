#include <pthread.h>
#include "NetPacket.h"
#include "SocketBuffer.h"
#include "ClientManager.h"
#include "LinuxTcpInfo.h"
#include "LinuxTcpOption.h"
#include "LinuxSocketOption.h"

ByteQueue ClientManager::queue;
INetAddress ClientManager::address;
LinuxTcpClient ClientManager::client;


bool ClientManager::RunThread(void)
{
	pthread_t threadid = pthread_t(-1);
	return !pthread_create(&threadid, 0, ThreadEntry, 0);
}
void* ClientManager::ThreadEntry(void*)
{
	LinuxTcpInfo info;
	LinuxSocketOption option;

	option.AttachSocket(client);
	option.DisableBlock();

	while(1)
	{
		SocketBuffer buffer(1024);
		if( client.Recv(buffer) )
		{
			queue.PushBack(buffer.GetData(), buffer.GetLength());
		}
		else if( info.GetInfo(client) && info.GetState() == 1)
		{
			DisassemblyPacket();
		}
		else
		{
			Reconnect();
		}
	}
}
bool ClientManager::CreateConnection(const IString& ip, int port)
{
	if( client.GetSocketHandler().IsValid() )
	{
		client.Close();
	}
	if( false == client.Open() )
	{
		return false;
	}
	LinuxSocketOption option;
	option.AttachSocket(client);
	option.DisableBlock();
	address.SetIp(ip);
	address.SetPort(port);
	return client.Connect(ip, port);
}
bool ClientManager::DestroyConnection(void)
{
	client.Close();
	return !client.GetSocketHandler().IsValid();
}
bool ClientManager::Reconnect(void)
{
	return CreateConnection(address.GetIp(), address.GetPort());
}
bool ClientManager::DisassemblyPacket(void)
{
	if( (queue.Size() + 1) % 32  == 0 )
	{
		printf("%s(%s,%d).size(%d)\n", __func__, address.GetIp().data(), address.GetPort(), queue.Size());
	}
}
