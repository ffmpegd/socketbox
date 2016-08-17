#include "INetAddress.h"

INetAddress::INetAddress(void)
{
	SetDomain(AF_INET);
	SetIp(IString("0.0.0.0"));
	SetPort(0);
}
INetAddress::INetAddress(const IString& ip, int port)
{
	SetIp(ip);
	SetPort(port);
	SetDomain(AF_INET);
}
void INetAddress::SetIp(const IString& ip)
{
	if( NULL == ip.data() )
	{
		address.sin_addr.s_addr = inet_addr("0.0.0.0");
	}
	address.sin_addr.s_addr = inet_addr(ip.data());
}
const IString INetAddress::GetIp(void)
{
	return IString(inet_ntoa(address.sin_addr));
}
void INetAddress::SetPort(int port)
{
	address.sin_port = htons((short)port);
}
const int INetAddress::GetPort(void)
{
	return ntohs(address.sin_port);
}
const void INetAddress::SetDomain(int domain)
{
	address.sin_family = domain;
}
const int INetAddress::GetDomain(void)
{
	return address.sin_family;
}
void* INetAddress::GetAddress(void)
{
	return (void*)&address;
}
const int INetAddress::GetLength(void)
{
	return sizeof(address);
}
