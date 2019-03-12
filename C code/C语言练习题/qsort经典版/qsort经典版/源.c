#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<Windows.h>
int *my_qsort(int arr[], int sz)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < sz-1; i++)
	{
		for (j = 0; j < sz - i - 1; j++)
		{
			if (arr[j]>arr[j + 1])
			{
				arr[j] ^= arr[j + 1];
				arr[j + 1] ^= arr[j];
				arr[j] ^= arr[j + 1];
			}
		}
	}
	return arr;
}
int main()
{
	int i = 0;
	int arr[10] = { 0, 1, 3, 5, 7, 9, 8, 6, 2, 4 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	my_qsort(arr, sz);
	for (; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	system("pause");
	return 0;
}