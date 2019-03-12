#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int Is_prime(int num)
{
	int i=0;
	for(i=1;i<(num/2);i++)
	{
		if(num%i!=0)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
}
int main()
{
	int num=0;
	scanf("%d",&num);
	Is_prime(num);
	if(Is_prime(num))
	{
		printf("是素数\n");
	}
	else
	{
		printf("不是素数\n");
	}
	system("pause");
	return 0;
}