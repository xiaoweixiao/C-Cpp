#pragma once
#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<Windows.h>
#include<assert.h>
#include<stack>
#include"stack.h"
using namespace std;

void InsertSort(int* arr, int n)//������
{
	assert(arr);

	for (int i = 0; i < n - 1; ++i)
	{
		int end = i;
		int flag = 0;
		int tmp = arr[end+1];
		while (end >= 0 && arr[end]>tmp)
		{
			flag = 1;
			arr[end + 1] = arr[end];	
			--end;//����end�Ƚ�����֮����Ҫ--end���ٸ�end֮ǰ��ֵ�Ƚ�
		}
		if (flag == 1)
		{
			end++;
			arr[end] = tmp;
		}
	}
}
void SellSort(int* arr, int n)//ϣ��������
{
	assert(arr);
	int gap = 3;

	for (int i = 0; i < n - gap; ++i)
	{
		int end = i;
		int flag = 0;
		int tmp = arr[end + gap];
		while (end >= 0 && arr[end]>tmp)
		{
			flag = 1;
			arr[end + gap] = arr[end];
			end-=gap;//����end�Ƚ�����֮����Ҫ--end���ٸ�end֮ǰ��ֵ�Ƚ�
		}
		if (flag == 1)
		{
			end+=gap;//ֻҪ���й���λ�ƶ�������Ҫ+��1��end<0 ��2�����ҵ����ʿ�λ֮��end-��
			arr[end] = tmp;
		}
	}
}
void BubbleSort(int* arr, int n)//����
{
	
	for (int i = 0; i < n-1; ++i)//n������Ҫð��ðn-1��
	{
		int flag = 0;
		for (int j = 0; j < n-1-i; j++)
		{
			if (arr[j]>arr[j + 1])
			{
				int tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
				flag = 1;
			}
		}
		if (flag == 0)
			break;
	}
}

void SelectSort(int*arr, int n)//����
{
	int i;
	for (i = n - 1; i > 0; --i)
	{
		int max = arr[0];
		int maxindex = 0;
		for (int j = 0; j<=i; ++j)
		{
			if (arr[j] > max)
			{
				max = arr[j];
				maxindex = j;
			}
		}
		int tmp = arr[maxindex];
		arr[maxindex] = arr[i];
		arr[i] = tmp;
	}
}


//������
void Adjustdown(int* arr, int from,int n)//С��
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

void HeapSort(int* arr, int n)//����
{
	int FirstNotLeaf = (n - 2) >> 1;//n-1�����һ�������±�
	for (int i = FirstNotLeaf; i >= 0; --i)
		Adjustdown(arr, i, n);;// С�ѽ���
	
	int j = n - 1;
	while (j>0)
	{
		swap(arr[0], arr[j]);
		--j;
		Adjustdown(arr, 0, j);
	}
}

//��������
void MidThree(int*arr,int first,int end,int mid)
{
	if (arr[first] > arr[end])
		swap(arr[first], arr[end]);

	//arr[first]<=arr[end]
	if (arr[mid] < arr[first])
		swap(arr[first], arr[end]);
	else if (arr[mid] < arr[end])//arr[mid]>arr[mid]>arr[first]
		swap(arr[mid], arr[end]);
}
int Partion1(int*arr,int left,int right)//ǰbegin�Ҵ󣬺�end��С
{
	int mid = left + (right-left) / 2;
	if (right - left>2)
		MidThree(arr, left, right, mid);//��Ԫ�ء�βԪ�ء�arr[mid]����λ���ŵ�arr[end]λ��

	int& key = arr[right];
	while (left < right)
	{
		while (left < right&&arr[left] <= key)
			++left;
		while (left<right&&arr[right] >= key)
			--right;
		swap(arr[left], arr[right]);
	}
	swap(arr[left], key);
	return left;
}
int Partion2(int* arr, int left, int right)
{
	int mid = left + (right - left) / 2;
	if (right - left>2)
		MidThree(arr, left, right, mid);

	int key = arr[right];
	int cur = left, prev =  left - 1;
	while (cur < right)
	{
		if (arr[cur] < key&&++prev != cur)
			swap(arr[cur], arr[prev]);
		++cur;
	}
	swap(arr[right], arr[++prev]);
	return prev;
}
int Partion3(int* arr, int left, int right)
{
	int mid = left + (right - left) / 2;
	if (right - left>2)
		MidThree(arr, left, right, mid);

	int key = arr[right];

	while (left < right)
	{
		while (left < right && arr[left] <= key)
		{
			++left;
		}
		arr[right] = arr[left];
		while (left < right && arr[right] >= key)
		{
			--right;
		}
		arr[left] = arr[right];
	}
	arr[right] = key;
	return right;
}
void QuickSort(int* arr, int left, int right)
{
	int len = right - left + 1;
	if (len < 5)
	{
		for (int start = left + 1; start <= right; start++)
		{
			int pos = start;
			int insert = arr[pos];
			while (pos>0 && arr[pos - 1] > insert)
			{
				arr[pos] = arr[pos - 1];
				pos--;
			}
			arr[pos] = insert;
		}
	}
	else
	{
		
	}
}

//�ǵݹ����
//void QuickSort(int* arr, int left, int right)
//{
//	Stack s;
//	StackInit(&s, 20);
//
//	int mid = (left + right) / 2;
//	if (right - left>2)
//		MidThree(arr, left, right - 1, mid);//��Ԫ�ء�βԪ�ء�arr[mid]����λ���ŵ�arr[end]λ��
//	int key = arr[right - 1];
//	int keyindex = right - 1;
//	int begin = left, end = right - 1;
//
//
//	while (begin < end || !StackEmpty(&s))
//	{
//		int mright = end;//�����¼���ڽ����ƶ��������end��begin
//		//�ڲ��������㣬�����µ�ȡ�����ж��µ����������Ƿ���Ҫ��ջʱ����
//		int mleft = begin;
//
//		while (begin < end)
//		{
//			while (begin < end&&arr[begin] <= key)
//				++begin;
//			while (begin < end&&arr[end] >= key)
//				--end;
//			//arr[begin]һ���Ǳ�key�����
//			//arr[end]һ���Ǳ�keyС����
//			if (begin<end)
//				swap(arr[begin], arr[end]);//С����ǰ�ߣ������ź��
//			//����begin==end������arr[begin]>key;	
//		}
//		if (begin != keyindex)
//			swap(arr[begin], arr[keyindex]);
//
//
//		if (begin-mleft>1)//ǰ�벿����ջ������ǰ�벿�ֲ�����1
//		{
//			StackPush(&s, 0);
//			StackPush(&s, begin - 1);
//		}
//		if (keyindex - begin>1)//��벿����ջ�������Ǻ�벿�ֲ�����1
//		{
//			StackPush(&s, begin);
//			StackPush(&s, mright);
//		}
//		if (!StackEmpty(&s))//���ջ��Ϊ��ȡ����������Ϊ�µ�����
//		{
//			end = StackTop(&s);
//			StackPop(&s);
//			begin = StackTop(&s);
//			StackPop(&s);
//		}
//		
//		int mid = (left + right) / 2;
//		if (right - left>2)
//			MidThree(arr, left, right - 1, mid);//��Ԫ�ء�βԪ�ء�arr[mid]����λ���ŵ�arr[end]λ��
//		key = arr[end];//���¹ؼ���key
//		keyindex = end;
//	}
//}

void QuickSortNotR(int* arr, int left, int right)
{
	assert(arr);
	stack<int> s;
	s.push(left);
	s.push(right);//�����right������Ҫ����right
	while (!s.empty())//ջ��Ϊ��
	{
		int right = s.top();
		s.pop();
		int left = s.top();
		s.pop();

		int index = Partion1(arr, left, right);
		if ((index - 1) > left)//��������
		{
			s.push(left);
			s.push(index - 1);
		}
		if ((index+1) < right)//��������
		{
			s.push(index + 1);
			s.push(right);
		}
	}
}
//�鲢����
void MergeArray(int*arr, int*tmp, int left,int right)
{
	if (left >= right)
		return;
	else
	{
		int index = 0;
		int mid = (left + right) / 2;


		MergeArray(arr, tmp, left, mid);
		MergeArray(arr, tmp, mid + 1, right);//����

		//�鲢
		int index1 = left, index2 = mid+1;
		while (index1 <= left && index2 <= right)
		{
			if (arr[index1] < arr[index2])
				tmp[index++] = arr[index1++];

			else
				tmp[index++] = arr[index2++];
		}
		while (index1 <= mid)
			tmp[index++] = arr[index1++];

		while (index2 <= right)
			tmp[index++] = arr[index2++];

		for (int i = 0; i < index; ++i)
			arr[left+i] = tmp[i];
	}	
}
void MergeSort(int*arr,int n)
{
	int*tmp = (int*)malloc(n*sizeof(int));
	MergeArray(arr, tmp, 0, n - 1);
	free(tmp);
}