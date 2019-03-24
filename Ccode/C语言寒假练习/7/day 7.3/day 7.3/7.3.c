#define _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<stdio.h>
int Is_leap_year(int year)
{
	if((year%4==0&&year%100!=0)||(year%400==0))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int main()
{
	int year=0;
	scanf("%d",&year);
	Is_leap_year(year);
	if(Is_leap_year(year))
	{
		printf("是闰年\n");
	}
	else
	{
		printf("不是闰年\n");
	}
	system("pause");
	return 0;
}