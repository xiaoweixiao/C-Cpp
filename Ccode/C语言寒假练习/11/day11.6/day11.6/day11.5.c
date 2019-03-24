#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<Windows.h>
#define Max(x,y) ((x)>(y)?(x):(y))
int main()
{
	int a=0;
	int b=0;
	scanf("%d %d",&a,&b);
	printf("%d\n",Max(a,b));
	system("pause");
	return 0;
}