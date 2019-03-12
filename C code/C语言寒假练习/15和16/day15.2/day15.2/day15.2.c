#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<Windows.h>
#include<stdarg.h>
int aver(int num, ...)
{
	int i=0;
	int sum=0;
	va_list arg;
	va_start(arg,num);
		for(i=0;i<num;i++)
		{
			sum=sum+va_arg(arg,int);
		}
	va_end(arg);
	return sum/num;
}
int main()
{
	printf("平均数是%d\n",aver(10,1,2,3,4,5,6,7,8,9,5));
	system("pause");
	return 0;
}