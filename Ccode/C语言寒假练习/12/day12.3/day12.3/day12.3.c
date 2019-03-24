#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<Windows.h>
int main()
{
	int single = 0;
	int i = 0;
	int arr[11] = { 1, 2, 3, 4, 5, 5, 4, 3, 2, 1, 111 };
	single = arr[0];
	for (i = 1; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		single = single^arr[i];
	}
	printf("%d\n", single);
	system("pause");
	return 0;
}