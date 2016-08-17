#ifndef __ISOCKETOPTION_H__
#define __ISOCKETOPTION_H__

class ISocketOption
{
public:
	virtual bool SetSocket(const ISocket&){}
	virtual bool AcceptConnection(void){}
	virtual bool BindToDevice(void){}
	virtual bool GetBroadcast(void){}
	virtual bool SetBroadcast(int){}
	virtual bool EnableBsdCompat(void){}
	virtual bool EnableDebug(void){}
	virtual bool GetDomain(void){}
	virtual bool GetError(void){}
	virtual bool DontRoute(void){}
	virtual bool SetKeepAlive(int){}
	virtual bool GetKeepAlive(void){}
	virtual bool SetLinger(int){}
	virtual bool GetLinger(int){}
	virtual bool SetMark(int){}
	virtual bool OobInline(int){}
	virtual bool EnableCredentials(void){}
	virtual bool DisableCredentions(void){}
	virtual bool SetPeekOffset(int){}
	virtual bool GetPerrCredentials(void){}
	virtual bool SetPriority(int){}
	virtual bool GetProtocol(void){}
	virtual bool SetRecvBufferSize(int){}
	virtual bool GetRecvBufferSize(int){}
	virtual bool SetRecvBufferSizeForce(int){}
	virtual bool GetRecvBufferSizeForce(int){}
	virtual bool SetLowestRecvBuffer(int){}
	virtual bool SetLowestSendBuffer(int){}
	virtual bool SetRecvTimeOut(int){}
	virtual bool SetSendTimeOut(int){}
	virtual bool EnableReuseAddress(void){}
	virtual bool DisableReuseAddress(void){}
	virtual bool SetSendBufferSize(int){}
	virtual bool GetSendBufferSize(int){}
	virtual bool SetSendBufferSizeForce(int){}
	virtual bool GetSendBufferSizeForce(int){}
	virtual bool EnableTimestamp(void){}
	virtual bool DisableTimestamp(void){}
	virtual bool SetBusyPoll(int){}
};

#endif//__ISOCKETOPTION_H__
