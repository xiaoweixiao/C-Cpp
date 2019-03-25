//ÕýÈ·ÎÞÎó
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
//		int left = input[i];//Ê£Óà¿ÕÆ¿
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


//2
#include<iostream>
#include<string>
using namespace std;
int main()
{
	string s1, s2;
	cin >> s1 >> s2;
	int len = 0;
	int maxlen = 0;
	string ret;
	for (size_t i = 0; i < s1.size(); i++)
	{
		for (size_t j = 0; j < s2.size(); j++)
		{
			while (s1[i] == s2[j])
			{
				len++;
				i++, j++;
			}
			if (len>maxlen)
			{
				ret = s1.substr(i - len, i);
				maxlen = len;
			}
		}
	}
	cout << ret << endl;
	system("pause");
}