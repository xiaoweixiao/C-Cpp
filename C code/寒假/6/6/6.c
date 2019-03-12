#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<Windows.h>
int main()
{
	int a, b, c, mul;
	scanf("%d %d", &a,&b);
	c = a%b;
	mul = a*b;
	while (c != 0)
	{
		a = b;
		b = c;
		c = a%b;
	}
	printf("%d\n",mul/b);
	system("pause");
	return 0;
}