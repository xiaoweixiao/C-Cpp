#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<Windows.h>
void adjust(int arr[], int sz)
{
	int i, j;
	for (i = 0, j = sz - 1; i < j;)
	{
		if ((arr[i] % 2 == 0) && (arr[j] % 2 == 1))
		{
			arr[i] ^= arr[j];
			arr[j] ^= arr[i];
			arr[i] ^= arr[j];
		}
		if (arr[i] % 2 == 1)
			i++;
		if (arr[j] % 2 == 0)
			j--;
	}
}
int main()
{
	int i = 0;
	int arr[10] = { 10, 21, 20, 33, 44, 51, 62, 73 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	adjust(arr, sz);
	for (; i < sz; i++)
	{
		printf("%d\n", arr[i]);
	}
	system("pause");
	return 0;
}