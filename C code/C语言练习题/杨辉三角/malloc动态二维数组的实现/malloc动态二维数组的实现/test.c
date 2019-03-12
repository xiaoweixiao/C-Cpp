#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<Windows.h>

void Show_yanghui(int n)
{
	int col = 0, row = 0;
	int**mem = (int**)malloc(sizeof(int*)*n);
	if (mem == NULL)
		return;
	for (int i = 0; i < n; i++)
	{
		mem[i] = (int*)malloc(sizeof(int)*n);
		if (mem[i] == NULL)
			return;
	}
	for (col = 0; col < n; col++)
	{
		for (row = 0; row <= col; row++)
		{
			if (row == col || row == 0)
				mem[col][row] = 1;
		}
	}
	for (col = 2; col < n; col++)
	{
		for (row = 1; row < col; row++)
			mem[col][row] = mem[col - 1][row - 1] + mem[col - 1][row];
	}
	for (col = 0; col <n; col++)
	{
		for (row = n - col - 1; row>0; row--)
		{
			printf(" ");
		}
		for (row = 0; row <= col; row++)
		{
			printf("%d ", mem[col][row]);
		}
		printf("\n");
	}


	for (int i = 0; i < n; i++)
		free(mem[i]);
	free(mem);
}
int main()
{
	printf("Please Enter n:");
	int n = 0;
	scanf("%d", &n);
	Show_yanghui(n);
	system("pause");
	return 0;
}