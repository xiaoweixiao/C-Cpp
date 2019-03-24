#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int i=0;
	printf("\n\n\n");
	for(i=0;i<4;i++)
	{
		int j=0;
		for(j=0;j<5-i;j++)
			printf(" ");
		for(j=0;j<3+i;j++)
			printf("。");
		for(j=0;j<7-2*i;j++)
			printf(" ");
		for(j=0;j<3+i;j++)
			printf("。");
		printf("\n");
	}
	for(i=0;i<10;i++)
	{
		int j=0;
		for(j=0;j<2+2*i;j++)
			printf(" ");
		for(j=0;j<12-2*i;j++)
			printf("。");
		printf("\n");
	}
	system("pause");
	return 0;
}
