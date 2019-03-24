#include"sort.h"

void GetLeastNumbers(int* input, int n, int* output, int k)
{
	if (input == NULL || output == NULL || k>n || n <= 0 || k <= 0)
		return;

	int  start = 0;
	int  end = n - 1;
	int  index = Partion1(input ,start,end);
	while (index != k - 1)
	{
		if (index>k - 1)
		{
			end = index - 1;
			index = Partion1(input, start, end);
		}
		else
		{
			start = index + 1;
			index = Partion1(input,start,end);
		}
	}

	for (int i = 0; i < k; ++i)
		output[i] = input[i];
}
void TestSort()
{
	int arr[] = { 4,1,3,0,2,5,9,8,6,7 };
	int len = sizeof(arr) / sizeof(int);
	GetLeastNumbers(arr, len, arr,4);
	for (int i = 0; i < len; i++)
		printf("%d ", arr[i]);
	printf("\n");
}
//void MergeArray(int len1,int len2,int*arr1,int* arr2,int* c)
//{
//	int index1 = 0, index2 = 0;
//	int index3 = 0;
//	while (index1 < len1&&index2 < len2)
//	{
//		if(arr1[index1] <= arr2[index2])
//			c[index3++] = arr1[index1++];
//
//		else
//			c[index3++] = arr2[index2++];
//	}
//	while (index1 < len1)
//		c[index3++] = arr1[index1++];
//
//	while (index2 < len2)
//		c[index3++] = arr2[index2++];
//}
//void TestMergeArray()
//{
//	int arr1[] = { 1, 3, 4, 5, 6, 9 };
//	int arr2[] = { 3, 6, 8, 10, 105 };
//	int len1 = sizeof(arr1) / sizeof(int);
//	int len2 = sizeof(arr2) / sizeof(int);
//	int*c = (int*)malloc((len1 + len2)*sizeof(int));
//	MergeArray(len1,len2,arr1, arr2,c);
//	Print(c,len1+len2);
//}
int main()
{
	TestSort();
	//TestMergeArray();
	system("pause");
	return 0;
}
