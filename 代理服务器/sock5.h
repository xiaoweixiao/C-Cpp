#ifndef _SOCKS5_H_
#define _SOCKS5_H_
#include"epoll.h"

class Socks5 :public Epoll
{
public:
	Socks5()
	{
		cout << "Socks5" << endl;
	}
protected:

};
#endif //_SOCKS5_H_