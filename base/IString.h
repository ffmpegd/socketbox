#ifndef __ISTRING_H__
#define __ISTRING_H__
#include "IDebug.h"
#include <string>

class IString : public std::string
{
public:
	IString(){}
	IString(const char *s)
	{
		if( s )
		{
			*(std::string*)this = s;
		}
	}
public:
	virtual int Format(const char *fmt,...){IDebug::Assert(__func__);}
};

#endif//__ISTRING_H__
