#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
void print(int n)
{
	if (n>9)
	{
		print(n / 10);
	}
	printf("%d ", n % 10);
}


int main()
{
	int n = 46789;
	print(n);
	system("pause");
	return 0;
}