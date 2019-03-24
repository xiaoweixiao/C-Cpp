#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>
int binary_search(int arr[], int key, int left, int right)
{
	while (left <= right)
	{
		int mid = left + ((right - left) >> 1);
		if (arr[mid] > key)
			right = mid - 1;
		else if (arr[mid] < key)
			left = mid + 1;
		else
		{
			return mid;
		}
	}
	return -1;
}

int main()
{
	//二分查找
	//折半查找
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int key = 7;
	int ret = 0;
	int sz = sizeof(arr) / sizeof(arr[0]);
	ret = binary_search(arr, key, 2, 8);
	if (ret == -1)
	{
		printf("找不到\n");
	}
	else
	{
		printf("找到了:%d\n", ret);
	}
	system("pause");
	return 0;
}