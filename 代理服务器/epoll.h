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
	int _port;//端口，本机服务，不要ip
	int _lisfd;//监听描述符
	int _eventfd;//事件描述符
};
#endif //_EPOLL_H_