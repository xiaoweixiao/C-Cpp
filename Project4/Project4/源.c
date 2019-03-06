//#include<iostream>
//#include<vector>
//#include<stack>
//using namespace std;
//
//class Solution {
//public:
//	vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
//		vector<int> ret(input.begin(),input.end());
//		stack<int> s;
//
//		int left = ret[0], right = ret.size() - 1;
//		s.push(left);
//		s.push(right);
//		while (!s.empty())
//		{
//			int right = s.top();
//			s.pop();
//			int left = s.top();
//			s.pop();
//
//			int index = Partion(ret, left, right);
//			if ((index - 1) > left)//左子序列
//			{
//				s.push(left);
//				s.push(index - 1);
//			}
//			if ((index + 1) < right)//右子序列
//			{
//				s.push(index + 1);
//				s.push(right);
//			}
//		}
//		return ret;
//	}
//	int Partion(vector<int>& input,int left,int right)
//	{
//		int key = input[right];
//		int cur = left, prev = left - 1;
//		while (cur < right)
//		{
//			if (input[cur] < key&&++prev != cur)
//				swap(input[cur], input[prev]);
//			++cur;
//		}
//		swap(input[right], input[++prev]);
//		return prev;
//
//	}
//};
//
//int main()
//{
//	int arr[] = { 0, 9, 7, 8, 34, 2, 5, 7, 6 };
//	vector<int> input(arr, arr + sizeof(arr) / sizeof(arr[0]));
//	Solution su;
//	su.GetLeastNumbers_Solution(input, 4);
//	system("pause");
//	return 0;
//}

//
//#include<iostream>
//#include<vector>
//using namespace std;


//class Solution {
//public:
//	int FindGreatestSumOfSubArray(vector<int> array) {
//		int sum = array[0];
//		int max = array[0];
//		for (size_t i = 1; i<array.size(); i++)
//		{
//			if (sum >= 0)//sum最小为1
//			{
//				sum = sum + array[i];
//			}
//			else{
//				sum = array[i];
//			}
//			if (sum>max)
//				max = sum;
//		}
//		return max;
//	}
//};


//class Solution {
//public:
//	int NumberOf1Between1AndN_Solution(int n)
//	{
//		int ret = 0;
//		for (int i = 1; i <= n; i++)
//		{
//			int num = i;
//			if (num % 10 == 1)
//				ret++;
//			num = num / 10;
//			while (num)
//			{
//				if (num % 10 == 1)
//					ret++;
//				num = num / 10;
//			}
//		}
//		return ret;
//	}
//};
//int main()
//{
//	Solution su;
//	su.NumberOf1Between1AndN_Solution(13);
//}


//#include<iostream>
//#include<vector>
//#include<sstream>
//using namespace std;
//
//class Solution {
//public:
//	string PrintMinNumber(vector<int> numbers) {
//		string ret;
//		vector<string> vec;
//		for (size_t i = 0; i < numbers.size(); i++)
//		{
//			ostringstream s;
//			s << numbers[i];
//			vec.push_back(s.str());
//		}
//		SortBubble(vec);
//		for (size_t i = 0; i < vec.size(); i++)
//		{
//			for (size_t j = 0; j < vec[i].size();j++)
//				ret.push_back(vec[i][j]);
//		}
//		return ret;
//	}
//	void SortBubble(vector<string>& vec)//数字高位的降序冒泡
//	{
//		bool flag;//判断是否还要需要冒泡
//		for (size_t j = 0; j < vec.size() - 1; j++)//冒泡次数
//		{
//			flag = false;
//			for (size_t i = 0; i < vec.size() - 1 - j; i++)
//			{
//				if (vec[i][0]>vec[i + 1][0])
//				{
//					swap(vec[i], vec[i + 1]);
//					flag = true;
//				}
//
//				else if (vec[i][0] == vec[i + 1][0])//3	32	321
//				{
//					flag = true;
//					size_t index = 1;
//					int Ok = 1;
//					while (index < vec[i].size() && index < vec[i + 1].size())
//					{
//						Ok = 1;
//						if (vec[i][index] == vec[i + 1][index])
//						{
//							index++;
//							Ok = 0;
//						}
//						else if (vec[i][index] > vec[i + 1][index])
//						{
//							swap(vec[i], vec[i + 1]);
//							break;
//						}
//						else
//							break;
//					}
//					if (Ok == 0)
//					{
//						if (index == vec[i + 1].size())
//							swap(vec[i], vec[i + 1]);
//					}
//				}
//			}
//			if (flag==false)break;
//		}
//		
//	}
//};
//
//int main()
//{
//	vector<int> vec;
//	vec.push_back(3);
//	vec.push_back(32);
//	vec.push_back(321);
//	Solution su;
//	su.PrintMinNumber(vec);
//}

//#include<iostream>
//using namespace std;
//class Solution {
//public:
//	int GetUglyNumber_Solution(int index) {
//		if (index <= 0)
//			return 0;
//
//		int* uglys = new int[index];
//		uglys[0] = 1;
//		int nextUglyIndex = 1;
//		int ugly2 = 0;
//		int ugly3 = 0;
//		int ugly5 = 0;
//		while (nextUglyIndex < index)
//		{
//			int min = Min(uglys[ugly2] * 2, uglys[ugly3] * 3, uglys[ugly5] * 5);
//			uglys[nextUglyIndex] = min;
//			while (uglys[ugly2] * 2 <= uglys[nextUglyIndex])
//				++ugly2;
//			while (uglys[ugly3] * 3 <= uglys[nextUglyIndex])
//				++ugly3;
//			while (uglys[ugly5] * 5 <= uglys[nextUglyIndex])
//				++ugly5;
//			++nextUglyIndex;
//		}
//		int ugly = uglys[nextUglyIndex - 1];
//		return ugly;
//	}
//	int Min(int num1, int num2, int num3){
//		int min = (num1 < num2) ? num1 : num2;
//		min = (min < num3) ? min : num3;
//		return min;
//	}
//};
//
//int main()
//{
//	Solution su;
//	su.GetUglyNumber_Solution(10);
//}


//#include<iostream>
//using namespace std;
//int main()
//{
//	int first = 0, second = 1;
//	while (second<15)
//	{
//		int old1 = first;
//		first = second;
//		second = second + old1;
//	}
//	//first  n  second
//	if (first < second)
//		cout << 15 - first << endl;
//	else
//		cout << second - 15 << endl;
//	system("pause");
//	return 0;
//}

//#include<iostream>
//#include<vector>
//using namespace std;
//
//class Solution {
//public:
//	int FindGreatestSumOfSubArray(vector<int> array) {
//		vector<int> arr;
//		int sum = array[0];
//		for (size_t i = 1; i<array.size(); i++)
//		{
//			if (sum>0)
//				sum += array[i];
//			else
//				sum = array[i];
//			arr.push_back(sum);
//		}
//		sum = 0;
//		for (size_t i = 0; i<arr.size(); i++)
//		{
//			if (array[i]>sum)
//				sum = array[i];
//		}
//		return sum;
//	}
//};
//
//int main()
//{
//	int arr[] = { 6, -3, -2, 7, -15, 1, 2, 2 };
//	vector<int> vec(arr, arr + sizeof(arr) / sizeof(arr[0]));
//	Solution so;
//	cout<<so.FindGreatestSumOfSubArray(vec);
//	system("pause");
//}
#include <stdio.h>
#include <stdlib.h>

typedef struct _Parent
{
	int a;
	int b;
	void(*print)(struct _Parent *This);
}Parent;

typedef struct _Child
{
	Parent parent;
	int c;
}Child;

void print_parent(Parent *This)
{
	printf("a = %d. b = %d.\n", This->a, This->b);
}

void print_child(Parent *This)
{
	Child *p = (Child *)This;
	printf("a = %d. b = %d. c = %d.\n", p->parent.a, p->parent.b, p->c);
}

Parent *create_parent(int a, int b)
{
	Parent *This;

	This = NULL;
	This = (Parent *)malloc(sizeof(Parent));
	if (This != NULL)
	{
		This->a = a;
		This->b = b;
		This->print = print_parent;
		printf("Create parent successfully!\n");
	}

	return This;
}

void destroy_parent(Parent **p)
{
	if (*p != NULL)
	{
		free(*p);
		*p = NULL;
		printf("Delete parent successfully!\n");
	}
}

Child *create_child(int a, int b, int c)
{
	Child *This;

	This = NULL;
	This = (Child *)malloc(sizeof(Child));
	if (This != NULL)
	{
		This->parent.a = a;
		This->parent.b = b;
		This->c = c;
		This->parent.print = print_child;
		printf("Create child successfully!\n");
	}

	return This;
}

void destroy_child(Child **p)
{
	if (*p != NULL)
	{
		free(*p);
		*p = NULL;
		printf("Delete child successfully!\n");
	}
}

int main()
{
	Child *p = create_child(1, 2, 3);
	Parent *q;


	q = (Parent *)p;

	q->print(q);

	destroy_child(&p);
	system("pause");
	return 0;

}
