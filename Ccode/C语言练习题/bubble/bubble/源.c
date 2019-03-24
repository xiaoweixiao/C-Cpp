#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<Windows.h>
int main()
{
	int arr[] = { 9, 5, 6, 4, 7, 8, 2, 13, 5, 20 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	int i = 0, j = 0;
	int flag = 0;
	for (i = 0; i < sz - 1; i++)
	{
		for (j = 0; j < sz - i - 1; j++)
		{
			if (arr[j]>arr[j+1])
			{
				arr[j] ^= arr[j+1];
				arr[j+1] ^= arr[j];
				arr[j] ^= arr[j+1];
				flag = 1;
			}	
		}
		if (flag == 0)
			break;
	}
	for (int k = 0; k < sz; k++)
		printf("%d ", arr[k]);
	printf("\n");
	system("pause");
	return 0;
}