#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<Windows.h>
int main()
{
	int a, b,max;
	printf("请输入两个需要比较大小的数:");
	scanf("%d  %d",&a,&b);
	max = a > b ? a : b;
	printf("%d",max);
	system("pause");
	return 0;
}