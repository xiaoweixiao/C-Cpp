#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
void swap(int *x,int *y)
{
	int t=0;
	t=*x;
	*x=*y;
	*y=t;
}
int main()
{
	int a=10;
	int b=20;
	printf("a=%d\nb=%d\n",a,b);
	swap(&a,&b);
	printf("a=%d\nb=%d\n",a,b);
	system("pause");
	return 0;
}