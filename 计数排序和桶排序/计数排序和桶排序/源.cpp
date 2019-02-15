#include<iostream>
#include<vector>

using namespace std;
void CountSort(int* arr,int len)
{
	int min = arr[0], max = arr[0];
	for (int i = 0; i < len; i++)//���������ҵ����ֵ����Сֵ
	{
		if (arr[i] < min)
			min = arr[i];
		if (arr[i]>max)
			max = arr[i];
	}

	vector<int> v(max - min + 1, 0);
	for (int i = 0; i < len; i++)//ͳ�ƴ���
	{
		v[arr[i] - min]++;
	}

	int index = 0;
	for (size_t i = 0; i < v.size(); i++)//���������ռ�
	{
		while (v[i]--)//�����ռ��ֵ��ʾ���±���ֵĴ���
		{
			arr[index++] = i + min;
		}
	}
}
void BucketSort(int* arr, int len)
{
	vector<vector<int>> LSD(10);
	vector<vector<int>> MSD(10);
	for (int i = 0; i < len; i++)//������Ԫ���ӽ���λͰ
	{
		LSD[arr[i] % 10].push_back(arr[i]);
	}

	
	for (int i = 0; i < 10; i++)//����ά����LSD�е����������ӽ�ʮλͰ
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

	int index = 0;//�����ݿ�����ԭ����
	for (int i = 0; i < 10; i++)//����ά����LSD�е����������ӽ�ʮλͰ
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