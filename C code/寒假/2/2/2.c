#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<Windows.h>
int main()
{
	int a, b,max;
	printf("������������Ҫ�Ƚϴ�С����:");
	scanf("%d  %d",&a,&b);
	max = a > b ? a : b;
	printf("%d",max);
	system("pause");
	return 0;
}