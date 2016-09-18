#include <string.h>
#include "NetPacket.h"


NetPacket::NetPacket(void)
{
	memset(m_data, 0, sizeof(m_data));
}

bool NetPacket::MakePacket(const char *buf, const char cmd, const int len)
{
	if( NULL == buf || len < 0 )
	{
		return false;
	}
	if( (len + 1 + 1 + 4) > sizeof(m_data) )
	{
		return false;
	}
	SetLength(len + 1 + 1 + 4);
	SetCommand(cmd);
	SetData(buf, len);
	return true;
}
void NetPacket::SetLength(const int length)
{
	m_data[0] = char(length >> 24);
	m_data[1] = char(length >> 16);
	m_data[2] = char(length >> 8);
	m_data[3] = char(length >> 0);
	m_data[4] = char(0xF1);
}
void NetPacket::SetCommand(const int command)
{
	m_data[5] = char(command);
}
void NetPacket::SetData(const char *buf, const int len)
{
	if( len < 1 || len < sizeof(m_data)-6 )
	{
		return;
	}
	memcpy(m_data + 5, buf, len);
}
const void* NetPacket::GetData(void)const
{
	return m_data;
}
const int NetPacket::GetLength(void)const
{
	int length = 0;
	length |= (int(m_data[0]) << 24);
	length |= (int(m_data[1]) << 16);
	length |= (int(m_data[2]) << 8);
	length |= (int(m_data[3]) << 0);
	return length;
}
