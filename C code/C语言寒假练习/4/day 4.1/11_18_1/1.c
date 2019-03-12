#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int n=0;
	int i=0;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		int j=0;
		for(j=0;j<n-1-i;j++)
		{
			printf(" ");
		}
		for(j=0;j<2*i+1;j++)
		{
			printf("*");
		}
		printf("\n");
	}
    for(i=0;i<n-1;i++)
	{
		int j=0;
		for(j=0;j<i+1;j++)
		{
			printf(" ");
		}
			
		for(j=0;j<2*(n-1-i)-1;j++)
		{
			printf("*");
		}		
	printf("\n");
	}
	system("pause");
	return 0;
}
