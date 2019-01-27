#ifndef _EPOLL_H_
#define _EPOLL_H_

#include"com.h"

class Epoll
{
public:
	Epoll(int port=8000)
		:_port(port)
		, _lisfd(-1)
		, _eventfd(-1)
	{
	}
	~Epoll()
	{
		if (_lisfd != -1)
			close(_lisfd);
	}

	void OPEvent(int fd, int enevts, int op)
	{
		struct epoll_event event;
		event.events = events;
		event.data.fd = fd;
		epoll_ctl(_event)
	}

	void Start();
	void EventLoop();

protected:
	int _port;//�˿ڣ��������񣬲�Ҫip
	int _lisfd;//����������
	int _eventfd;//�¼�������
};
#endif //_EPOLL_H_