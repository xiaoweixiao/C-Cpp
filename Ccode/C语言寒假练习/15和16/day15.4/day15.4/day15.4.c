#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<windows.h>
#include<stdarg.h>
#include<assert.h>
char* printf_a(char* s,...)
{
	va_list arg;
	assert(s);
	va_start(arg,s);
	while(*s!='\0')
	{
		if(*s)
		{
			putchar(va_arg(arg,char));
		}
		
	}
	va_end(arg);

int main()
{
	printf_a("hello bit !!!come on!!!")
	system("pause");
	return 0;
}