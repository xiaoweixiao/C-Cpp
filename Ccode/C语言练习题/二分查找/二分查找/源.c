
//µİ¹é
#include<stdio.h>
#include<Windows.h>
#include<assert.h>
int binary_search(int*arr, int left, int right,int key)
{
	assert(arr != NULL);
	while (left<=right)
	{
		int mid = left + ((right - left) >> 1);
		if (arr[mid] > key)
			return binary_search(arr, left, mid - 1, key);
		else if (arr[mid] < key)
			return binary_search(arr, mid + 1, right, key);
		else
			return mid;
	}
	return -1;
}
void test()
{
	int arr[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int len = sizeof(arr) / sizeof(arr[0]);


	printf("%d\n", binary_search(arr, 0, 9, 0));
	printf("%d\n", binary_search(arr, 0, 9, 1));
	printf("%d\n", binary_search(arr, 0, 9, 2));
	printf("%d\n", binary_search(arr, 0, 9, 3));
	printf("%d\n", binary_search(arr, 0, 9, 4));
	printf("%d\n", binary_search(arr, 0, 9, 5));
	printf("%d\n", binary_search(arr, 0, 9, 6));
	printf("%d\n", binary_search(arr, 0, 9, 7));
	printf("%d\n", binary_search(arr, 0, 9, 8));
	printf("%d\n", binary_search(arr, 0, 9, 9));
	printf("%d\n", binary_search(arr, 0, 9, 10));
}
int main()
{
	//Test();
	test();
	system("pause");
	return 0;
}
//·Çµİ¹é
//#include<stdio.h>
//#include<Windows.h>
//#include<assert.h>
//int binary_search(int*arr, int len, int key)
//{
//	assert(arr);
//	int left = 0;
//	int right = len - 1;
//	int mid = 0;
//	while (left <= right)
//	{
//		mid = left + ((right - left) >> 1);
//		if (arr[mid] > key)
//		{
//			right = mid - 1;
//		}
//		else if (arr[mid] < key)
//		{
//			left = mid + 1;
//		}
//		else
//		{
//			return mid;
//		}
//	}
//	return -1;
//}
//void Test()
//{
//	int arr[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
//	int len = sizeof(arr) / sizeof(arr[0]);
//
//	printf("%d\n", binary_search(arr, len, 0));
//	printf("%d\n", binary_search(arr, len, 1));
//	printf("%d\n", binary_search(arr, len, 2));
//	printf("%d\n", binary_search(arr, len, 3));
//	printf("%d\n", binary_search(arr, len, 4));
//	printf("%d\n", binary_search(arr, len, 5));
//	printf("%d\n", binary_search(arr, len, 6));
//	printf("%d\n", binary_search(arr, len, 7));
//	printf("%d\n", binary_search(arr, len, 8));
//	printf("%d\n", binary_search(arr, len, 9));
//	printf("%d\n", binary_search(arr, len, 10));
//}
//int main()
//{
//	Test();
//	system("pause");
//	return 0;
//}