#include <string.h>
#include <linux/tcp.h>
#include "LinuxTcpInfo.h"
#include "LinuxTcpOption.h"

LinuxTcpInfo::LinuxTcpInfo(void)
{
	memset(&data, 0, sizeof(data));
}

void* LinuxTcpInfo::GetBuffer(void)
{
	return (void*)data;
}
const int LinuxTcpInfo::GetLength(void)const
{
	return sizeof(struct tcp_info);
}
const int LinuxTcpInfo::GetState(void)const
{
	return (*(struct tcp_info*)data).tcpi_state;
}

const int LinuxTcpInfo::GetCaState(void)const
{
	return (*(struct tcp_info*)data).tcpi_ca_state;
}
const bool LinuxTcpInfo::GetInfo(const class ISocket& s)
{
	LinuxTcpOption option;

	if( option.AttachSocket(s) )
	{
		return option.GetTcpInfo(*this);
	}
	return false;
}
