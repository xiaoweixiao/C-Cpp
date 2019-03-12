#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int n=0;
	int i=0;
	scanf("%d",&n);
	for(i=31;i>0;i-=2)
	{
		printf("%d ",(n>>i)&1);
	}
	printf("\n");
	for(i=30;i>=0;i-=2)
	{
		printf("%d ",(n>>i)&1);
	}
	system("pause");
	return 0;
}