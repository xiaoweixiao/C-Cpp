//网上看了思路，代码过了
//#include<iostream>
//#include<vector>
//
//using namespace std;
//
//int main()
//{
//	//f(n)=f(n-1)+f(n-3)*2
//	int month;
//	while (cin >> month)
//	{
//		vector<int> num(month);
//		for (size_t i = 0; i < 2; i++)
//			num[i] = 1;
//		if (month < 4)
//		{
//			cout << 1 << endl;
//			return 0;
//		}
//
//		for (int i = 2; i < month; i++)
//			num[i] = num[i - 1] + num[i - 2];
//		cout << num[month - 1] << endl;
//	}
//	return 0;
//}

//第二题不会做，这是网上拷贝的
#/*include<cstdio>
#include<string>
#include<cstring>
#include<iostream>
#include<algorithm>
#define N 20
using namespace std;
int f[N][N];
string a, b;
void init(){
	getline(cin, a);
	getline(cin, b);
	memset(f, 0, sizeof f);
	f[1][1] = 1;
	if (a[0] == '*') f[1][0] = 1;
	if (a[0] == '?') f[0][0] = 1;
}
int main(){
	init();
	for (int i = 1; i <= a.size(); i++)
	for (int j = 1; j <= b.size(); j++)
	{
		if (a[i - 1] == '?') f[i][j] = f[i - 1][j - 1];
		else if (a[i - 1] == '*' && (f[i - 1][j - 1] || f[i][j - 1] || f[i - 1][j])) f[i][j] = 1;
		else if (a[i - 1] == b[j - 1] && f[i - 1][j - 1]) f[i][j] = 1;
	}
	if (f[a.size()][b.size()]) cout << "matched" << endl;
	else cout << "not matched" << endl;
	return 0;
}*/


//剑指offer一书题解，竟然没通过内存限制
//#include<iostream>
//#include<vector>
//using namespace std;
//class Solution {
//public:
//	int InversePairs(vector<int> data) {
//		vector<int> copy(data.begin(), data.end());
//		int ret = Count(data, copy, 0, data.size() - 1);
//		return ret % 1000000007;
//	}
//	int Count(vector<int>& data, vector<int>& copy, int start, int end)
//	{
//		if (start == end)
//			return 0;
//
//		int len = (end - start) / 2;
//		int left = Count(data, copy, start, len);
//		int right = Count(data, copy, len + 1, end);
//
//		int i = len, j = end;
//		int index = end;//copyindex
//		int count = 0;
//		while (i >= start && j >= len + 1)
//		{
//			if (data[i] > data[j])
//			{
//				copy[index--] = data[i--];
//				count += j - start - len;
//			}
//			else
//				copy[index--] = data[j--];
//		}
//
//		for (; i >= start; i--)
//			copy[index--] = data[i];
//		for (; j >= len + 1; j--)
//			copy[index--] = data[j];
//
//		return left + right + count;
//	}
//};
//int main()
//{
//	vector<int> input{ 7, 5, 6, 4 };
//	Solution s;
//	s.InversePairs(input);
//}

#include<iostream>
#include<vector>
using namespace std;
//class Solution {
//public:
//	void FindNumsAppearOnce(vector<int> data, int* num1, int *num2) {
//		if (data.size()<2)
//			return;
//
//		int ret = 0;
//		for (size_t i = 0; i<data.size(); i++)
//			ret ^= data[i];
//
//		size_t index1 = FindFirst1(ret);
//		*num1 = *num2 = 0;
//		for (size_t j = 0; j<data.size(); j++)
//		{
//			if (Is1(data[j], index1))
//				*num1 ^= data[j];
//			else
//				*num2 ^= data[j];
//		}
//	}
//	size_t FindFirst1(int num)
//	{
//		size_t index1 = 0;
//		while ((index1<32) && ((num&1) == 0))
//		{
//			num = num >> 1;
//			index1++;
//		}
//		return index1;
//	}
//	bool Is1(int num, size_t index1)
//	{
//		num = num >> index1;
//		return (num & 1);
//	}
//};
//int main()
//{
//	vector<int> input{ 2, 4, 3, 6, 3, 2, 5, 5 };
//	Solution s;
//	int num1, num2;
//	s.FindNumsAppearOnce(input,&num1,&num2);
//	cout << num1 << endl << num2 << endl;
//	system("pause");
//}

class Solution {
public:
	vector<vector<int> > FindContinuousSequence(int sum) {
		vector<vector<int>> ret;
		int small = 1, big = 2;
		int cur = 3;
		while (small<big&&big<sum)
		{
			if (cur<sum)
			{
				big++;
				cur += big;
			}
			else if (cur>sum)
			{
				cur -= small;
				small++;
			}
			else
			{
				int len = big - small + 1;
				vector<int> one(len);
				for (int i = 0; i < len; i++)
					one[i] = small + i;

				ret.push_back(one);

				big++;
				cur += big;
			}
		}
		for (size_t i = 0; i < ret.size(); i++)
		{
			for (size_t j = 0; j < ret[i].size(); j++)
				cout << ret[i][j];
			cout << endl;
		}
		return ret;
	}
};
int main()
{
	Solution s;
	s.FindContinuousSequence(9);
	system("pause");
}