#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<Windows.h>
#include<stdarg.h>
int Max(int n,...)
{
	int max=0;
	int i=0;
	va_list arg;
	va_start(arg,n);
	for(i=0;i<n;i++)
	{
		int val=va_arg(arg,int);
		//宏不同于函数，函数有返回值可直接打印返回值，宏必须定义一个变量来接受宏若干参数
		if(val>max)
		{
			max=val;
		}
	}
	va_end(arg);
	return max;
}
int main()
{
	printf("Max==%d\n",Max(10,99,88,77,66,55,4,3,2,1,20));
	system("pause");
	return 0;
}