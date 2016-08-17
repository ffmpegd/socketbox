#ifndef __INETADDRESS_H__
#define __INETADDRESS_H__
#include "IAddress.h"
#include <netinet/in.h>
#include <arpa/inet.h>

class INetAddress : public IAddress
{
private:
	struct sockaddr_in address;
public:
	INetAddress();
	INetAddress(const IString& ip, int port);

public:
	void SetIp(const IString& ip);
	const IString GetIp(void);

	void SetPort(int port);
	const int GetPort(void);

	const int GetDomain(void);
	const void SetDomain(int);
	void* GetAddress(void);
	const int GetLength(void);
};

#endif//__INETADDRESS_H__
