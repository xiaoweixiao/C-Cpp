#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<Windows.h>
int main()
{
	int a = 10, b = 20;
	printf("a=%d b=%d\n", a, b);
	a ^= b;
	b ^= a;
	a ^= b;
	printf("a=%d b=%d\n",a,b);
	system("pause");
	return 0;
}