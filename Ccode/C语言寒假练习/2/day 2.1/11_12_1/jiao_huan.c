#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int a=0;
	int b=0;
	int temp=0;
	printf("������������Ҫ����������");
	scanf("%d %d",&a,&b);
	printf("a=%d\nb=%d\n",a,b);
	temp=a;
	a=b;
	b=temp;
	printf("������\n");
	printf("a=%d\nb=%d\n",a,b);
	system("pause");
	return 0;
}