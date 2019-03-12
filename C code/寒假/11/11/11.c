#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<Windows.h>
int main()
{
	double hight = 100;
	int n = 0;
	double s = hight;
	for (n = 0; n < 9; n++)
	{
		hight = hight / 2.0;
		s = s + 2.0 * hight;
	}
	printf("%.3lf %.3lf\n", hight, s);
	system("pause");
	return 0;
}