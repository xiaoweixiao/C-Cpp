#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<windows.h>
int main()
{
	int a=10;
	int b=20;
	a=a+(b-a)/2;
	printf("两个数的平均值是：%d\n",a);
	system("pause");
	return 0;
}