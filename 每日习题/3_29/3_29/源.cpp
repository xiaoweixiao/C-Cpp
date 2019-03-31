#include<vector>
#include<iostream>
#include<map>
#include<algorithm>
using namespace std;
//class Gift {
//public:
//	int getValue(vector<int> gifts, int n) {
//		map<int, int> times;
//		int half = n / 2;
//		for (int i = 0; i < n; i++)
//			times[gifts[i]]++;
//
//		map<int, int>::iterator it = times.begin();
//		while (it != times.end())
//		{
//			if (it->second>half)
//				return it->first;
//			it++;
//		}
//		return 0;
//	}
//};
//int main()
//{
//	Gift g;
//	g.getValue({1,2,3,2,2},5);
//}

//class Solution {
//public:
//	int InversePairs(vector<int> data) {
//		vector<int> copy(data.size());
//		long long ret = Count(data, copy, 0, data.size() - 1);
//		return ret % 1000000007;
//	}
//	long long Count(vector<int>& data, vector<int>& copy, int start, int end)
//	{
//		if (start == end)
//		{
//			copy[start] = data[start];
//			return 0;
//		}
//
//		int len = (end - start) / 2;
//		long long left = Count(data, copy, start, start + len);
//		long long right = Count(data, copy, start + len + 1, end);
//
//		int i = start + len, j = end;
//		int index = end;//copyindex
//		long long count = 0;
//		while (i >= start && j >= start + len + 1)
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
//		for (; j >= start + len + 1; j--)
//			copy[index--] = data[j];
//
//		return left + right + count;
//	}
//};
//
//int main()
//{
//	Solution s;
//	s.InversePairs({ 364, 637, 341, 406, 747, 995, 234, 971, 571, 219, 993, 407, 416, 366, 315, 301, 601, 650, 418, 355, 460, 505, 360, 965, 516, 648, 727, 667, 465, 849, 455, 181, 486, 149, 588, 233, 144, 174, 557, 67, 746, 550, 474, 162, 268, 142, 463, 221, 882, 576, 604, 739, 288, 569, 256, 936, 275, 401, 497, 82, 935, 983, 583, 523, 697, 478, 147, 795, 380, 973, 958, 115, 773, 870, 259, 655, 446, 863, 735, 784, 3, 671, 433, 630, 425, 930, 64, 266, 235, 187, 284, 665, 874, 80, 45, 848, 38, 811, 267, 575 });
//}

//class Solution {
//public:
//	long long nums = 0;
//	int InversePairs(vector<int> data) {
//		vector<int> copy = data;
//		MSort(data, copy, 0, data.size() - 1);
//		return nums % 1000000007;
//	}
//
//	void Merge(vector<int> &data, vector<int> &copy, int begin, int mid, int end)
//	{
//		int start = begin;//记录开始位置
//		int left = begin;
//		int right = mid + 1;
//		while (left <= mid && right <= end)
//		{
//			if (data[left] < data[right])
//			{
//				copy[begin++] = data[left++];
//			}
//			else
//			{
//				copy[begin++] = data[right++];
//				nums += mid - left + 1;
//			}
//		}
//		while (left <= mid)
//		{
//			copy[begin++] = data[left++];
//		}
//		while (right <= end)
//		{
//			copy[begin++] = data[right++];
//		}
//		while (start <= end)
//		{
//			data[start] = copy[start];
//			start++;
//		}
//	}
//
//	void MSort(vector<int> &data, vector<int> &copy, int begin, int end)
//	{
//		int mid;
//		if (begin < end)
//		{
//			mid = (begin + end) / 2;
//			MSort(data, copy, begin, mid);
//			MSort(data, copy, mid + 1, end);
//			Merge(data, copy, begin, mid, end);
//		}
//	}
//};
//int main()
//{
//	Solution s;
//	s.InversePairs({ 7, 4, 5, 6 });
//}

//class Solution {
//public:
//	string ReverseSentence(string str) {
//		string ret;
//		reverse(str.begin(), str.end());
//
//		size_t start = 0;
//		size_t pos = str.find(' ', start);
//		string word;
//		while (pos != string::npos)
//		{
//			word = str.substr(start, pos - start);
//			reverse(word.begin(), word.end());
//			word.push_back(' ');
//			ret.insert(ret.size(), word);
//			start = pos + 1;
//			pos = str.find(' ', start);
//		}
//		word = str.substr(start);
//		reverse(word.begin(), word.end());
//		ret.insert(ret.size(), word);
//		return ret;
//	}
//};



class Solution {
public:
	bool IsContinuous(vector<int> numbers) {
		sort(numbers.begin(), numbers.end());

		int count = 0;
		for (size_t i = 0; i < 4; i++)
		{
			if (i < numbers.size() && numbers[i] == 0)
				count++;
		}

		for (int index = count; index < 4;index++)
		{
			if (numbers[index + 1] == numbers[index] + 1)
				return false;
			else
			{
				int sub = numbers[index + 1] - numbers[index] - 1;
				if (sub <= count)//王够补空缺
					count -= sub;
				else
					return false;
			}
		}
		return true;
	}
};
int main()
{
	Solution s;
	s.IsContinuous({1,0,3,0,5});
	system("pause");
}