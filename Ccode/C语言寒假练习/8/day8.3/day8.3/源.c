#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<windows.h>
#define  size 10
int main()
{
	int i = 0;
	int j = 0;
	int a[10][10];
	//计算杨辉三角
	for (i = 0; i<size; i++)
	{
		a[i][0] = 1;
		a[i][i] = 1;
		for (j = 1; j<i; j++)
			a[i][j] = a[i - 1][j - 1] + a[i - 1][j];
	}


	//打印输出
	for (i = 0; i<size; i++)
	{
		for (j = 0; j<size - i - 1; j++){
			printf("   ");
		}
		for (j = 0; j <= i; j++){
			printf("%5d ", a[i][j]);
		}
		putchar('\n');/*printf("\n");*/
	}
	system("pause");
	return EXIT_SUCCESS;
}