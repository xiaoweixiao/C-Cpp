#ifndef __COM_H__
#define __COM_H__

#include<iostream>
#include<stdio.h>
#include<stdarg.h>
#include<string>
#include <unistd.h>
#include <sys/types.h>          /* See NOTES */
#include <sys/socket.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/epoll.h>

using namespace std;

#define __DEBUG__
#define __TRACE__

static string GetFilenName(const string&path)
{
	char ch = '/';
#ifdef _WIN32
	ch = '\\';
#endif //_WIN32
	size_t pos = path.rfind(ch);
	if (pos == string::npos)
		return path;
	else
		return path.substr(pos + 1);
}

#define TraceLog(...) __TraceDebug(__FILE__,__LINE__,__FUNCTION__,__VA_ARGS__);
#define ErrorLog(...) __ErrorDebug(__FILE__,__LINE__,__FUNCTION__,__VA_ARGS__);

inline static void __ErrorDebug(const char* filename, int line, const char*function, const char*fomat, ...)
{
#ifndef __DEBUG__
	fprintf(stdout, "[ERROR][%s:%d:%s]:", GetFilename(filename).c_str(), line, function);//输出调用函数信息
	//输出用户打印的信息
	va_list args;
	va_start(args, format);
	vfprintf(stdout, format, args);
	va_end(args);

	fprintf(stdout, "errmsg:%s,error:%d\n", strerror(errno), errno);
	fprintf(stdout, '\n');
#endif // __DEBUG__
}


inline static void __TraceDebug(const char* filename, int line, const char*function, const char*fomat, ...)
{
#ifndef __TRACE__
	fprintf(stdout, "[TRACE][%s:%d:%s]:", GetFilename(filename).c_str(), line, function);//输出调用函数信息
	//输出用户打印的信息
	va_list args;
	va_start(args, format);
	fprintf(stdout, format, args);
	va_end(args);

	fprintf(stdout, "errmsg:%s,error:%d\n", strerror(errno), errno);
	fprintf(stdout, '\n');
#endif // __DEBUG__
}
#endif //_COM_H_