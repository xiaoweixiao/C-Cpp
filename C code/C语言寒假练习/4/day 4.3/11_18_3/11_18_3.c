#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main()
{
	int a=0;
	int n=0;
	int i=0;
	int sum=0;
	int tmp=0;
	scanf("%d %d",&a ,&n);
	for(i=0;i<n;i++)
	{
		tmp=tmp*10+a;
		sum=sum+tmp;
	}
	printf("%d\n",sum);
	system("pause");
	return 0;
}
