#include <pthread.h>
#include "NetPacket.h"
#include "SocketBuffer.h"
#include "PacketMaker.h"
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
	time_t lastrecv = 0;
	time_t reconnec = 0;
	LinuxTcpInfo info;
	LinuxSocketOption option;

	option.AttachSocket(client);
	option.DisableBlock();
	lastrecv = time(0);
	reconnec = lastrecv;

	while(1)
	{
		time_t now = time(0);
		SocketBuffer buffer(1024);
		if( client.Recv(buffer) )
		{
			queue.PushBack(buffer.GetData(), buffer.GetLength());
			printf("Recv(%d)\n", buffer.GetLength());
			lastrecv = now;
		}
		else if( !client.GetSocketHandler().IsValid() )
		{
			if( now - reconnec > 5 )
			{
				Reconnect();
				reconnec = now;
				printf("Reconnect(%d)\n", __LINE__);
			}
		}
		else if( (now - lastrecv) > 2 )
		{
			lastrecv = now;
			info.GetInfo(client);
			if( info.GetState() != 1 )
			{
				Reconnect();
				printf("Reconnect(%d)\n", __LINE__);
			}
		}
		if( queue.Size() > 4 )
		{
			DisassemblyPacket();
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
	PacketMaker packet;
	if( packet.GetPacket(queue) )
	{
		packet.ShowData();
		packet.ShowString();
	}
}
bool ClientManager::SendString(const IString& s)
{
	PacketMaker packet;

	if( packet.MakePacket(s.data(), 0x00, s.length()) )
	{
		if( client.Send(packet.GetData(), packet.GetLength()+4) > 0 )
		{
			packet.ShowData();
			packet.ShowString();
		}
		else
		{
			client.Close();
		}
	}
	return false;
}
