#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<Windows.h>
#define exchange(num) ((((num)&0xAAAAAAAA)>>1)|(((num)&0x55555555)<<1))

int main()
{
	int num = 123;
	printf("%d\n", exchange(num));
	system("pause");
	return 0;
}