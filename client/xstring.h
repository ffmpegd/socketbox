#ifndef __XSTRING_H__
#define __XSTRING_H__
#include <time.h>
#include <string>
#include <cstdio>
#include <cstdarg>
#include <cstdlib>
using namespace std;

class xstring : public string
{
public:
	string& operator()() 
	{
		return (*(string*)this);
	}
    xstring& operator=(const xstring& xs)
    {
		(*(string*)this) = xs.data();
        return *this;
    }
public:
    xstring(){}
    xstring(const string& s)
    {
        (*(string*)this) = s;
    }
    xstring(const xstring& xs)
    {
        (*(string*)this) = xs;
    }
	xstring(const char*fmt,...)
	{
		if( fmt )
		{
			va_list ap;
			char buf[8192] = {0};
			va_start(ap, fmt);
			if( vsnprintf(buf, sizeof(buf), fmt, ap) > 0 )
			{
				*this = string(buf);
			}
			va_end(ap);
		}
	}
public:
	const string& tostring() const
	{
		return *(string*)this;
	}
	int format(const char* fmt,...)	
	{
		if( fmt )
		{
			int r = 0;
			va_list ap;
			char buf[8192] = {0};
			va_start(ap, fmt);
			if( r = vsnprintf(buf, sizeof(buf), fmt, ap) > 0 )
			{
				(*(string*)this) = buf;
			}
			va_end(ap);
			return r;
		}
		return -1;
	}
public:
	float tofloat() const
	{
		if( this->empty() )
			return 0.0000;
		return strtof(data(),NULL);
	}
	double todouble () const
	{
		if( this->empty() )
			return 0.0000;
		return strtod(data(),NULL);
	}
	int toint() const
	{
		if( this->empty() )
			return int(0);
		return atoi(data());
	}
    bool toboolean() const
    {
        if( "TRUE" == (*(string*)this) )
            return true;
        if( "true" == (*(string*)this) )
            return true;
        return false;
    }
    time_t todaytime() const
    {
        struct tm t;
        if( !strptime(data(),"%H:%M:%S",&t) )
            return time_t(0);
        return (t.tm_hour*3600+t.tm_min*60+t.tm_sec);
    }
    time_t todatetime() const
    {
        struct tm t;
        if( !strptime(data(),"%Y-%m-%d %H:%M:%S",&t) )
            return time_t(0);
        return mktime(&t);
    }
};

#endif//__XSTRING_H__
