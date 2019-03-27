//正确无误
//#include<iostream>
//#include<vector>
//using namespace std;
//int main()
//{
//	int n;
//	vector<int> input;
//	while (cin >> n&&n!=0)
//		input.push_back(n);
//
//	for (size_t i = 0;i<input.size();i++)
//	{
//		int left = input[i];//剩余空瓶
//		int water = 0;
//		while (left)
//		{
//			if (left == 1)
//			{
//				cout << water << endl;
//				break;
//			}
//			else if (left == 2)
//			{
//				cout << water + 1 << endl;
//				break;
//			}
//			else
//			{
//				water = water + left / 3;
//				left = left % 3 + left/3;
//			}
//		}
//	}
//	system("pause");
//	return 0;
//}


//2不会 
//#include<iostream>
//#include<string>
//using namespace std;
//int main()
//{
//	string s1, s2;
//	cin >> s1 >> s2;
//	int len = 0;
//	int maxlen = 0;
//	string ret;
//	for (size_t i = 0; i < s1.size(); i++)
//	{
//		for (size_t j = 0; j < s2.size(); j++)
//		{
//			while (s1[i] == s2[j])
//			{
//				len++;
//				i++, j++;
//			}
//			if (len>maxlen)
//			{
//				ret = s1.substr(i - len, i);
//				maxlen = len;
//			}
//		}
//	}
//	cout << ret << endl;
//	system("pause");
//}

//I am a student student. a am I
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
class Solution {
public:
	string ReverseSentence(string str) {
		string ret;
		reverse(str.begin(), str.end());

		size_t start = 0;
		size_t pos = str.find(' ', start);
		string tmp;
		while (pos != string::npos)
		{
			tmp = str.substr(start, pos - start);
			reverse(tmp.begin(), tmp.end());
			tmp.push_back(' ');
			ret.insert(ret.size(), tmp);
			start = pos + 1;
			pos = str.find(' ', start);
		}
		tmp = str.substr(start);
		reverse(tmp.begin(), tmp.end());
		ret.insert(ret.size(), tmp);
		return ret;
	}
};
int main()
{
	Solution s;
	string str{ "student. a am I" };
	cout<<s.ReverseSentence(str);
	system("pause");
}