#ifndef __PACKETMAKER_H__
#define __PACKETMAKER_H__
#include "ByteQueue.h"
#include "NetPacket.h"

class PacketMaker : public NetPacket
{
public:
	bool GetPacket(ByteQueue&);
	bool TryGetPacket(ByteQueue&);

private:
	const int BufferToLenth(const char*)const;
};

#endif//__PACKETMAKER_H__
