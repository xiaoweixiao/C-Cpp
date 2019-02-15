//#include<iostream>
//using namespace std;
//void SelectSort(int* arr, int len)
//{
//	int end = len - 1;
//	for (int j = 0; j < len; j++)
//	{
//		int max = 0;
//		for (int i = 0; i <= end; i++)
//		{
//			if (arr[i]>arr[max])
//				max = i;
//		}
//		swap(arr[max], arr[end]);
//		end--;
//	}
//}
//int main()
//{
//	int arr[] = { 49, 38, 65, 97, 76, 13, 27, 49, 55, 4 };
//	int len = sizeof(arr) / sizeof(arr[0]);
//	SelectSort(arr, len);
//	for (int i = 0; i < len; i++)
//		cout << arr[i] << "  ";
//	cout << endl;
//	system("pause");
//	return 0;
//}



//#include<iostream>
//using namespace std;
//void SelectSort(int* arr,int len)
//{
//	int begin = 0, end = len - 1;
//	while (begin < end)
//	{
//		int max = begin;
//		int min = begin;
//		for (int i = begin; i <= end; i++)
//		{
//			if (arr[i]>arr[max])
//				max = i;
//			if (arr[i] < arr[min])
//				min = i;
//		}
//		if (min == end)//判断最小值是否在最大值要放置的位置
//			min = max;
//		swap(arr[max], arr[end]);
//	
//		if (max == begin)//判断最大值是不是在最小值要放置的位置
//			max = min;
//		swap(arr[min], arr[begin]);
//		end--; begin++;
//	}
//}
//int main()
//{
//	int arr[] = {49,38,65,97,76,13,27,49,55,4};
//	int len = sizeof(arr) / sizeof(arr[0]);
//	SelectSort(arr,len);
//	for (int i = 0; i < len; i++)
//		cout << arr[i] <<"  ";
//	cout << endl;
//	system("pause");
//	return 0;
//}


//#include<iostream>
//#include<vector>
//
//using namespace std;
//
//void AdjustDown(vector<int>& arr, int parent, int len)
//{
//	int child = parent * 2 + 1;
//
//	while (child + 1<len&&child>0)
//	{
//		if (arr[child + 1]<arr[child])
//			child++;
//		if (arr[parent]>arr[child])
//		{
//			swap(arr[parent], arr[child]);
//			parent = child;
//			child = parent * 2 + 1;
//		}
//		else
//			break;
//	}
//}
//void MakeHeap(vector<int>& arr, int len)
//{
//	for (int i = (len - 2) / 2; i >= 0; i--)//最后一个结点的父亲结点就是最后一个非叶子节点
//	{
//		AdjustDown(arr, i, len);
//	}
//}
//void AdjustUp(vector<int>& v)
//{
//	int insert = v.size() - 1;
//	int parent = (insert - 1) / 2;
//	while (v[parent] > v[insert]&&parent>=0)
//	{
//		swap(v[parent], v[insert]);
//		insert = parent;
//		parent = (insert - 1) / 2;
//	}
//}
//int main()
//{
//	int arr[] = { 53, 17, 78, 9, 45, 65, 87, 23, 31 };
//	int len = sizeof(arr) / sizeof(arr[0]);
//	vector<int> v(arr, arr + len);
//	MakeHeap(v, len);
//
//	
//	v.push_back(11);
//	AdjustUp(v);
//
//	int end = v.size() - 1;
//	v[0] = v[end];
//	v.pop_back();
//	AdjustDown(v, 0, end + 1);
//	for (size_t i = 0; i < v.size(); i++)
//		cout << v[i] << "  ";
//	cout << endl;
//	system("pause");
//	return 0;
//}


#include<iostream>
using namespace std;
void Adjustdown(int* arr, int from, int n)//向下调整
{
	int father = from;
	int child = 2 * father + 1;
	while (child<n)
	{
		if (child + 1 < n&&arr[child] > arr[child + 1])
			child++;
		if (child < n&&arr[child] < arr[father])
		{
			swap(arr[child], arr[father]);
			father = child;
			child = 2 * father + 1;
		}
		else
			break;
	}
}

void HeapSort(int* arr, int n)//升序
{
	int FirstNotLeaf = (n - 2) >> 1;//n-1是最后一个结点的下标
	for (int i = FirstNotLeaf; i >= 0; --i)
		Adjustdown(arr, i, n);;// 小堆建成

	int j = n - 1;
	while (j>0)
	{
		swap(arr[0], arr[j]);
		--j;
		Adjustdown(arr, 0, j);
	}
}

void TestSort()
{
	int arr[] = { 4, 1, 3, 0, 2, 5, 9, 8, 6, 7 };
	int len = sizeof(arr) / sizeof(int);
	HeapSort(arr, len);
	for (int i = 0; i < len; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

int main()
{
	TestSort();
	system("pause");
	return 0;
}