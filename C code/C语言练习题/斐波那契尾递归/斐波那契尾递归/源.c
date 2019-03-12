#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<Windows.h>
long long fib(int n, int c1, int c2)
{
	if (n < 3)
		return c1;
	else
	{
		printf("%d	", c1 + c2);
		return fib(n - 1, c2, c1 + c2);
	}
}


int main()
{
	int n = 0;
	scanf("%d", &n);
	long start_time = GetTickCount();
	fib(n,1,1);
	long end_time = GetTickCount();
	printf("斐波那契函数实现时间：%ld\n", end_time - start_time);
	system("pause");
	return 0;
}