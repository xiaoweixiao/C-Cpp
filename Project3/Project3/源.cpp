//#include<iostream>
//#include<vector>
//#include<set>
//using namespace std;

//class Solution {
//public:
//	vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
//		vector<int> ret;
//		int left = 0;
//		int right = input.size() - 1;
//	
//		if ((size_t)k>input.size())return ret;
//
//		int index = Partion(input, left, right);
//		while (index != k - 1)
//		{
//			if (index > k - 1)
//			{
//				right = index - 1;
//				index=Partion(input, left, right);
//			}
//			else
//			{
//				left = index + 1;
//				index = Partion(input, left, right);
//			}
//		}
//		for (int i = 0; i<k; i++)
//			ret.push_back(input[i]);
//		for (size_t i = 0; i < ret.size(); i++)
//			cout << ret[i] << "  ";
//		cout << endl;
//		return ret;
//	}
//	int Partion(vector<int>&input,int left,int right)
//	{
//		int& key = input[right];
//		while (left<right)
//		{
//			while (left<right&&input[left] <= key)
//				left++;
//			while (left<right&&input[right] >= key)
//				right--;
//			swap(input[left], input[right]);
//		}
//		swap(input[left], key);
//		return left;
//	}
//};
#include<iostream>
#include<vector>
#include<set>
using namespace std;
class Solution {
public:
	vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
		multiset<int> mset(input.begin(), input.end());
		vector<int> ret(mset.begin(),mset.end());
		ret.resize(k);
		return ret;
	}
};
int main()
{
	int arr[] = { 4, 5, 1, 6, 2, 7, 3, 8 };
	vector<int> input(arr, arr + sizeof(arr) / sizeof(arr[0]));
	Solution su;
	su.GetLeastNumbers_Solution(input, 4);
	system("pause");
	return 0;
}

//#include<iostream>
//#include <set>
//using namespace std;
//void TestMulSet()
//{
//	int array[] = { 2, 1, 3, 9, 6, 0, 5, 8, 4, 7 };
//	// ע�⣺multiset�ڵײ�ʵ�ʴ洢����<int, int>�ļ�ֵ��
//	multiset<int> s(array, array + sizeof(array) / sizeof(array[0]));
//	for (auto& e : s)
//		cout << e << " ";
//	cout << endl;
//	// ����multiset���Ƿ���Դ洢ֵ��ͬ��Ԫ��
//	s.insert(5);
//	cout << s.count(5) << endl;
//	for (auto& e : s)
//		cout << e << " ";
//	cout << endl;
//	// ɾ������ֵΪ5��Ԫ��
//	s.erase(5);
//	for (auto& e : s)
//		cout << e << " ";
//	cout << endl;
//}
//int main()
//{
//	TestMulSet();
//	system("pause");
//	return 0;
//}

//#include<iostream>
//#include<cstdio>
//using namespace std;
//
//class Person
//{
//public:
//	virtual void BuyTicket(){}
//};
//
//class Student :public Person
//{
//	virtual void BuyTicket(){}
//};
//
//int main()
//{
//	int a = 0;                      //ջ
//	int* b = new int(10);           //*b���ڶ�
//	static int c = 0;               //���ݶ�
//	char* ptr = "Hello World";      //*ptr�洢�ڴ����
//
//	Person p;
//	printf("�麯����ַ:%p\n", *(int*)&p);
//
//	printf("ջ��%p\n", &a);
//	printf("�ѣ�%p\n", b);
//	printf("���ݶΣ�%p\n", &c);
//	printf("����Σ�%p\n", ptr);
//
//	system("pause");
//	return 0;
//}


//#include<iostream>
//using namespace std;
//
//int main()
//{
//	int year = 0, month = 0, day = 0, ret = 0;
//	int Day[13] = { 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365 };
//	while (cin >> year >> month >> day)
//	{
//		ret = Day[month - 1] + day;
//		if (month>2)
//		{
//			if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
//				ret += 1;
//		}
//		cout << ret << endl;
//	}
//	return 0;
//}



//#include <stdio.h>
//#include <stdlib.h>
//int main()
//{
//	char *p, *np;
//	p = (char *)malloc(10);
//	np = (char *)realloc(p, 15);
//	printf("%p\n", p);
//	printf("%p\n", np);
//
//	free(np);
//	np = nullptr;
//	system("pause");
//	return 0;
//}

//#include <cstdlib>
//#include<iostream>
//
//int main()
//{
//	int *p = (int*)calloc(10, sizeof(int));
//	if (nullptr != p)
//	{
//		for (int i = 0; i < 10; i++)
//			std::cout << *(p + i) <<std::endl;
//	}
//	free(p);
//	p = nullptr;
//	system("pause");
//	return 0;
//}

//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//
//void GetMemory(char **p, int num)
//{
//	*p = (char *)malloc(num);
//}
//void Test(void)
//{
//	char *str = NULL;
//	GetMemory(&str, 100);
//	strcpy(str, "hello");
//	printf(str);
//	free(str);
//	str = nullptr;
//}
//int main()
//{
//	Test();
//	system("pause");
//}

//#include<iostream>
//#include<vector>
//#include<queue>
//using namespace std;
//
//struct TreeNode {
//int val;
//struct TreeNode *left;
//struct TreeNode *right;
//TreeNode(int x) :
//val(x), left(NULL), right(NULL) {}
//};
//class Solution {
//public:
//	vector<vector<int> > Print(TreeNode* pRoot) {
//		vector<vector<int> >ret;
//		vector<int>level;
//		if (pRoot == NULL)
//			return ret;
//
//		int prevnum, num = 1;
//		queue<TreeNode *>q;
//		q.push(pRoot);
//		while (!q.empty())
//		{
//			prevnum = num;
//			level.clear();
//			num = 0;
//			while (prevnum--)
//			{
//				level.push_back(q.front()->val);
//				if (q.front()->left != NULL)
//				{
//					q.push(q.front()->left);
//					num++;
//				}
//
//				if (q.front()->right != NULL)
//				{
//					q.push(q.front()->right);
//					num++;
//				}
//				q.pop();
//			}
//			ret.push_back(level);
//		}
//		return ret;
//		/*��α�������Ҫ�Ǹ㶨ÿ��������������ķ�ʽ��Ȼ�Ƕ���һ��������ͳ�ƣ�
//		����ÿһ���ڵ㣬��������������������ȷ�����϶��µķ�ʽȷ����ÿһ��ĸ���
//		����һ��Ľڵ������ȷ��*/
//	}
//};