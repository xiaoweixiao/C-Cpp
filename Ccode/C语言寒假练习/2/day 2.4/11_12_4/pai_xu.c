#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
void swap(int *m,int *n)
{
	int t=*m;
	*m=*n;
	*n=t;
}
int main()
{
	int a;
	int b;
	int c;
	printf("请输入三个数：");
	scanf("%d %d %d",&a,&b,&c);
	if(a<b)
	{
		swap(&a,&b);
	}
	if(a<c)
		{
			swap(&a,&c);
	}
	if(b<c)
	{
		swap(&b,&c);
	}
	printf("这三个数由大到小依次是:%d %d %d\n",a,b,c);
	system("pause");
	return 0;
}
