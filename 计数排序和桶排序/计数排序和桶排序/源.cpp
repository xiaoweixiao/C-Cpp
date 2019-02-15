#include<iostream>
#include<vector>

using namespace std;
void CountSort(int* arr,int len)
{
	int min = arr[0], max = arr[0];
	for (int i = 0; i < len; i++)//遍历数组找到最大值和最小值
	{
		if (arr[i] < min)
			min = arr[i];
		if (arr[i]>max)
			max = arr[i];
	}

	vector<int> v(max - min + 1, 0);
	for (int i = 0; i < len; i++)//统计次数
	{
		v[arr[i] - min]++;
	}

	int index = 0;
	for (size_t i = 0; i < v.size(); i++)//遍历辅助空间
	{
		while (v[i]--)//辅助空间的值表示该下标出现的次数
		{
			arr[index++] = i + min;
		}
	}
}
void BucketSort(int* arr, int len)
{
	vector<vector<int>> LSD(10);
	vector<vector<int>> MSD(10);
	for (int i = 0; i < len; i++)//将数组元素扔进个位桶
	{
		LSD[arr[i] % 10].push_back(arr[i]);
	}

	
	for (int i = 0; i < 10; i++)//将二维数组LSD中的数字依次扔进十位桶
	{
		if (LSD[i].size()>0)
		{
			for (size_t j = 0; j < LSD[i].size(); j++)
			{
				int insert = LSD[i][j];
				MSD[insert / 10].push_back(insert);
			}
		}
	}

	int index = 0;//将数据拷贝回原数组
	for (int i = 0; i < 10; i++)//将二维数组LSD中的数字依次扔进十位桶
	{
		if (MSD[i].size()>0)
		{
			for (size_t j = 0; j < MSD[i].size(); j++)
			{
				arr[index++] = MSD[i][j];
			}
		}
	}
}
int main()
{
	int arr[] = { 73, 22, 93, 43, 55, 14, 28, 65, 39, 81 };
	int len = sizeof(arr) / sizeof(arr[0]);
	BucketSort(arr,len);
	for (int i = 0; i < len; i++)
		cout << arr[i] << "  ";
	cout << endl;
	system("pause");
	return 0;
}