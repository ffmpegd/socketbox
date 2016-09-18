#ifndef __ISOCKETOPTION_H__
#define __ISOCKETOPTION_H__
#include "IDebug.h"
#include "ISocket.h"

class ISocketOption
{
public:
	virtual bool AttachSocket(const ISocket&){IDebug::Assert(__func__);}
	virtual bool AcceptConnection(void){IDebug::Assert(__func__);}
	virtual bool BindToDevice(void){IDebug::Assert(__func__);}
	virtual bool GetBroadcast(void){IDebug::Assert(__func__);}
	virtual bool SetBroadcast(int){IDebug::Assert(__func__);}
	virtual bool EnableBsdCompat(void){IDebug::Assert(__func__);}
	virtual bool EnableDebug(void){IDebug::Assert(__func__);}
	virtual bool GetDomain(void){IDebug::Assert(__func__);}
	virtual bool GetSocketError(int&){IDebug::Assert(__func__);}
	virtual bool DontRoute(void){IDebug::Assert(__func__);}
	virtual bool SetKeepAlive(int){IDebug::Assert(__func__);}
	virtual bool GetKeepAlive(void){IDebug::Assert(__func__);}
	virtual bool SetLinger(int){IDebug::Assert(__func__);}
	virtual bool GetLinger(int){IDebug::Assert(__func__);}
	virtual bool SetMark(int){IDebug::Assert(__func__);}
	virtual bool OobInline(int){IDebug::Assert(__func__);}
	virtual bool EnableCredentials(void){IDebug::Assert(__func__);}
	virtual bool DisableCredentions(void){IDebug::Assert(__func__);}
	virtual bool SetPeekOffset(int){IDebug::Assert(__func__);}
	virtual bool GetPerrCredentials(void){IDebug::Assert(__func__);}
	virtual bool SetPriority(int){IDebug::Assert(__func__);}
	virtual bool GetProtocol(void){IDebug::Assert(__func__);}
	virtual bool SetRecvBufferSize(int){IDebug::Assert(__func__);}
	virtual bool GetRecvBufferSize(int){IDebug::Assert(__func__);}
	virtual bool SetRecvBufferSizeForce(int){IDebug::Assert(__func__);}
	virtual bool GetRecvBufferSizeForce(int){IDebug::Assert(__func__);}
	virtual bool SetLowestRecvBuffer(int){IDebug::Assert(__func__);}
	virtual bool SetLowestSendBuffer(int){IDebug::Assert(__func__);}
	virtual bool SetRecvTimeOut(int){IDebug::Assert(__func__);}
	virtual bool SetSendTimeOut(int){IDebug::Assert(__func__);}
	virtual bool EnableReuseAddress(void){IDebug::Assert(__func__);}
	virtual bool DisableReuseAddress(void){IDebug::Assert(__func__);}
	virtual bool SetSendBufferSize(int){IDebug::Assert(__func__);}
	virtual bool GetSendBufferSize(int){IDebug::Assert(__func__);}
	virtual bool SetSendBufferSizeForce(int){IDebug::Assert(__func__);}
	virtual bool GetSendBufferSizeForce(int){IDebug::Assert(__func__);}
	virtual bool EnableTimestamp(void){IDebug::Assert(__func__);}
	virtual bool DisableTimestamp(void){IDebug::Assert(__func__);}
	virtual bool SetBusyPoll(int){IDebug::Assert(__func__);}
	virtual bool EnableBlock(void){IDebug::Assert(__func__);}
	virtual bool DisableBlock(void){IDebug::Assert(__func__);}
};

#endif//__ISOCKETOPTION_H__
