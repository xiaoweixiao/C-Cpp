#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<Windows.h>
int main()
{
	int a=0, n=0, i=0, sum=0, tmp=0;
	scanf("%d %d", &a, &n);
	for (i = 0; i < n; i++)
	{
		tmp = tmp* 10 + a;
		sum = sum + tmp;
	}
	printf("%d\n", sum);
	system("pause");
	return 0;
}