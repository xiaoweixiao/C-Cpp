//ͨ��쳲�����������ʵ�ַ�����������и��Ӷȵ���Ҫ��
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<Windows.h>
long long fib(int n)
{
	int f0 = 0, f1 = 1, f2 = n;
	if (n < 3)
		return 1;
	else
	{
		for (int i = 2; i <= n; ++i)
		{
			f2 = f1 + f0;
			f0 = f1;
			f1 = f2;
		}
	}
	return f2;
}


//long long fib(int n)
//{
//	if (n < 3)
//		return 1;
//	else
//	{
//		return fib(n - 1) + fib(n - 2);
//	}
//}

int main()
{
	int n = 0;
	scanf("%d", &n);
	long start_time = GetTickCount();
	fib(n);
	printf("%d\n", fib(n));
	long end_time = GetTickCount();
	printf("쳲�������������ʱ�䣺%ldms\n", end_time - start_time);
	system("pause");
	return 0;
}