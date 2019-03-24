#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<Windows.h>
int search_num(int arr[3][3], int key,int row,int col)
{
	int i = 0;
	int j = col - 1;
	while ((i < row) && (j >= 0))
	{
		if (key>arr[i][j])
			i++;
		else if (key < arr[i][j])
			j--;
		else
			return 1;
	}
	return 0;
}
int main()
{
	int ret = 0;
	int arr[3][3] = { { 1, 2, 3 }, { 2, 3, 4 }, { 3, 4, 5 } };
	int key = 4;
	ret=search_num(arr,key,3,3);
	if (ret == 1)
		printf("找到了\n");
	else
		printf("没找到\n");
	system("pause");
	return 0;
}