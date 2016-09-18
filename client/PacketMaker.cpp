#include "PacketMaker.h"

bool PacketMaker::GetPacket(ByteQueue& queue)
{
	while(queue.Size() > 4)
	{
		if( TryGetPacket(queue) )
		{
			return true;
		}
		if( queue.Size() < GetLength() )
		{
			return false;
		}
	}
	return false;
}
bool PacketMaker::TryGetPacket(ByteQueue& queue)
{
	queue.PopFront(m_data, 4);
	int length = GetLength();
	if( length > queue.Size() )
	{
		return false;
	}
	if( length > sizeof(m_data)-4 )
	{
		queue.PopFront();
		return false;
	}
	if( length < 0 )
	{
		queue.PopFront();
		return false;
	}
	queue.PopFront(m_data+4, length);
	return true;
}
