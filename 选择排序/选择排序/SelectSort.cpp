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

#include<iostream>
using namespace std;
void HeapSort(int* arr, int len)
{
	
}
int main()
{
	
	system("pause");
	return 0;
}

