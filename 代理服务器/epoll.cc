#include"epoll.h"

void Epoll::Start()
{
	_lisfd = socket(AF_INET, SOCK_STREAM, 0);//0：域间套接字
	if (_lisfd == -1)
	{
		ErrorLog("create socket");
		return;
	}

	struct sockaddr_in addr;
	memset(&addr, 0, sizeof(addr));
	addr.sin_family = AF_INET;
	addr.sin_port = htons(_port);
	addr.sin_addr.s_addr = htonl(INADDR_ANY);//INADDR_ANY任意一块网卡
	if (bind(_lisfd, (struct sockaddr*)&addr, sizeof(addr)) < 0);
	{
		ErrorLog("bind socket");
		return;
	}

	if (listen(_lisfd, 100000) < 0)
	{
		ErrorLog("listen");
		return;
	}

	TraceLog("epoll server listening on %d", _port);

	_eventfd = epoll_create(100000);//int epoll_create(int size);
	if (_eventfd == -1)
	{
		ErrorLog("epoll_create");
		return;
	}

	//进入时间循环
	EventLoop();
}
void Epoll::EventLoop()
{

}