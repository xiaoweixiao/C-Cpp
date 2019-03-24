#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<Windows.h>
int main()
{
	int a = 1, b = 2, c, i = 1;
	double sum = 0;
	for (i = 1; i <= 20; i++)
	{
		sum += 1.0*b / a;
		c = a;
		a = b;
		b = a + c;
	}
	printf("%.2lf",sum);
	system("pause");
	return 0;
}