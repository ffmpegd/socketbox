#ifndef __IADDRESS_H__
#define __IADDRESS_H__
#include "IString.h"

class IAddress
{
public:
	virtual void* GetAddress(void){IDebug::Assert(__func__);}	
};

#endif//__IADDRESS_H__
