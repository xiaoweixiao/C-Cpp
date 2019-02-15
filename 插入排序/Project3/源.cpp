#include<iostream>
#include<assert.h>

using namespace std;

void insertSort(int *arr, int len)
{
	assert(arr);
	for (int start = 1; start <= len - 1; start++)
	{
		int pos = start;//pos��������λ��
		int insert = arr[pos];//��������
		while (pos > 0 && insert < arr[pos - 1])
		{
			arr[pos] = arr[pos - 1];
			pos--;
		}
		arr[pos] = insert;
	}
}

void insertsort2(int *arr, int len)
{
	assert(arr);
	for (int start = 1; start <= len - 1; start++)
	{
		if (arr[start] < arr[start - 1])
		{
			int left = 0;
			int right = start - 1;
			int insert = arr[start];
			while (left <= right)
			{
				int mid = left + ((right - left) >> 1);
				if (insert < arr[mid])
					right = mid - 1;
				else
					left = mid + 1;
			}

			for (int pos = start; pos>0 && pos>right + 1; pos--)
			{
				arr[pos] = arr[pos - 1];
			}
			arr[right + 1] = insert;
		}
	}
}
void ShellSort(int* arr, int n)//ϣ��������
{
	assert(arr);
	int gap = n;//gap��������
	while (gap > 1)
	{
		gap = gap / 3 + 1;//��1�Ǳ�֤���һ�ο϶�������Ϊ1������
		for (int start = 0; start < n - gap; ++start)
		{
			int pos = start;
			int insert = arr[pos + gap];
			while (pos >= 0 && arr[pos]>insert)
			{
				arr[pos + gap] = arr[pos];
				pos -= gap;
			}
			pos += gap;
			arr[pos] = insert;
		}
	}
}
int main()
{
	int arr[] = { 9, 1, 2, 5, 7, 4, 8, 6, 3, 5 };
	int len = sizeof(arr)/sizeof(arr[0]);
	insertSort(arr, len);
	for (int i = 0; i < len; i++)
		printf("%d ", arr[i]);
	system("pause");
}