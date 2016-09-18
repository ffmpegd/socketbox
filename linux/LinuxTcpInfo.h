#ifndef __LINUXTCPINFO_H__
#define __LINUXTCPINFO_H__

class LinuxTcpInfo
{
private:
	char data[1024];

public:
	LinuxTcpInfo(void);

public:
	void* GetBuffer(void);
	const int GetLength(void)const;
public:
	const int GetState(void)const;
	const int GetCaState(void)const;
	const bool GetInfo(const class ISocket&);
};

#endif//__LINUXTCPINFO_H__
