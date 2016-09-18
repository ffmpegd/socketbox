#ifndef __BYTEQUEUE__
#define __BYTEQUEUE__
#include <list>
#include <xstring>
#include "socketdefine.h"

class ByteQueue
{
	private:
		size_t m_size;
		list<char> m_queue;

	public:
		ByteQueue()
		{
			m_size = 0;
		}

	public:
		size_t Size() const	
		{
			return m_size;
		}

	public://PushBack
		void PushBack(const uchar c)
		{
			m_size++;
			m_queue.push_back(c);	
		}
		void PushBack(uint len)
		{
			uint lenin = htonl(len);
			PushBack((uchar*)&lenin, sizeof(len));
		}
		void PushBack(cchar *buf, size_t len)
		{
			PushBack((const uchar*)buf, len);
		}
		void PushBack(const unsigned char *buf, size_t len)
		{
			if( NULL == buf )
				return;
			for(int i = 0; i < len; i++)
			{
				m_size++;
				m_queue.push_back(buf[i]);
			}
		}
		void PushBack(const std::string& data)
		{
			PushBack(data.data(), data.length());
		}

	public://PushFront
		void PushFront(const uchar c)
		{
			m_size++;
			m_queue.push_front(c);	
		}
		void PushFront(const std::string& data)
		{
			PushFront(data.data(), data.length());
		}
		void PushFront(uint len)
		{
			uint lenin = htonl(len);
			PushFront((uchar*)&lenin, sizeof(len));
		}
		void PushFront(const char *buf, size_t len)
		{
			PushFront((uchar*)buf, len);
		}
		void PushFront(const uchar *buf, size_t len)
		{
			if( NULL == buf )
				return;
			for(int i = 0; i < len; i++)
			{
				m_size++;
				m_queue.push_front(buf[len-1-i]);
			}
		}

	public://PopFront
		unsigned char PopFront()
		{
			unsigned char c = 0;

			if( m_size > 0 )
			{
				m_size--;
				c = m_queue.front();
				m_queue.pop_front();
			}
			return c;
		}
		size_t PopFront(unsigned char *buf, size_t len)
		{
			if( NULL == buf )
				return -1;
			if( m_size < 1 )
				return -1;
			if( len < 1 )
				return -1;
			if( len > m_size )
				len = m_size;
			for(int i = 0; i < len; i++)
			{
				
				buf[i] = m_queue.front();
				m_queue.pop_front();
				m_size--;
			}
			return len;
		}

	public://PopBack
		unsigned char PopBack()
		{
			unsigned char c = 0;
			if( m_size > 0 )
			{
				c = m_queue.back();
				m_queue.pop_back();
			}
			return c;
		}
		size_t PopBack(unsigned char *buf, size_t len)
		{
			if( len < 1 )
				return -1;
			if( NULL == buf )
				return -1;
			if( m_size < 1 )
				return -1;
			if( len > m_size )
				len = m_size;
			for(int i = 0; i < len; i++)
			{
				buf[len-i-1] = m_queue.back();
				m_queue.pop_back();
				m_size--;
			}
			return len;
		}
};

#endif//__BYTEQUEUE__
