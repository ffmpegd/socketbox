#ifndef __BYTEQUEUE__
#define __BYTEQUEUE__
#include <list>
#include <xstring.h>

class ByteQueue
{
	private:
		int m_size;
		list<char> m_queue;

	public:
		ByteQueue()
		{
			m_size = 0;
		}

	public:
		int Size() const	
		{
			return m_size;
		}

	public://PushBack
		void PushBack(const char c)
		{
			m_size++;
			m_queue.push_back(c);	
		}
		void PushBack(char *buf, int len)
		{
			PushBack((const char*)buf, len);
		}
		void PushBack(const  char *buf, int len)
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
		void PushBack(const void* buf, int len)
		{
			PushBack((const char*)buf, len);
		}

	public://PushFront
		void PushFront(const char c)
		{
			m_size++;
			m_queue.push_front(c);	
		}
		void PushFront(const std::string& data)
		{
			PushFront(data.data(), data.length());
		}
		void PushFront(const unsigned char *buf, int len)
		{
			PushFront((const char*)buf, len);
		}
		void PushFront(const char *buf, int len)
		{
			if( NULL == buf || len < 1)
				return;
			for(int i = 0; i < len; i++)
			{
				m_size++;
				m_queue.push_front(buf[len-1-i]);
			}
		}

	public://PopFront
		 char PopFront()
		{
			 char c = 0;

			if( m_size > 0 )
			{
				m_size--;
				c = m_queue.front();
				m_queue.pop_front();
			}
			return c;
		}
		int PopFront( char *buf, int len)
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
		 char PopBack()
		{
			 char c = 0;
			if( m_size > 0 )
			{
				c = m_queue.back();
				m_queue.pop_back();
			}
			return c;
		}
		int PopBack( char *buf, int len)
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
