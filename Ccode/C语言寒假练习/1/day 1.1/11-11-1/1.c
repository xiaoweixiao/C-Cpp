#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int i=0;
	int j=0;
	int count=0;
	for(i=100;i<=200;i++)//for(i=101;i<=200;i+=2)
	{
		for(j=2;j<i;j++)//for(j=2;j<sqrt(i);j++)
		{
			if(i%j==0)
			break;
			
		}
		if(i==j)//if(j>sqrt(i))
		{
			printf("%d  ",i);
			count ++;
		}
	}
	printf("\ncount=%d\n",count);
	system("pause");
	return 0;
}
