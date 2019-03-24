#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<Windows.h>
int main()
{
	int max, arr[10] = { 10, 2, 30, 4, 50, 6, 70, 8, 90, 100 }, i,flag=1;
	max = arr[0];
	for (i = 0; i < 10; i++)
	{
		if (arr[i+1]>arr[i])
		{
			max = arr[i+1];
			flag = -flag;
		}
	}
	if (flag == 1)
	{
		return 0;
	}
	printf("max=%d\n",max);
	system("pause");
	return 0;
}
