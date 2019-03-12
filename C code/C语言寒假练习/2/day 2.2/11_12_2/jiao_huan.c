#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int a,b;
	printf("请输入两个需要交换的数：");
	scanf("%d %d",&a,&b);
	printf("a=%d\nb=%d\n",a,b);
	//a=a+b;
	//b=a-b;
	//a=a-b;
	a=a^b;//a=011,b=101,a=a^b=110
	b=a^b;//011
	a=a^b;//101
	printf("交换后：\n");
	printf("a=%d\nb=%d\n",a,b);
	system("pause");
	return 0;
}

