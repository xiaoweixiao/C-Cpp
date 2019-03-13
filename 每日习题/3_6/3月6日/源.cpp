//#include<iostream>
//#include<string>
//using namespace std;
//int main()
//{
//	string str;
//	while (cin >> str)
//	{
//		string ret;
//		size_t len = ret.size();
//		for (size_t i = 0; i<str.size(); i++)
//		{
//			if (!(str[i] >= '0' && str[i] <= '9'))
//				i++;
//			else
//			{
//				string tmp;
//				char min = str[i];
//				tmp.push_back(str[i++]);
//				while (str[i] >= '0' && str[i] <= '9'&&str[i]>min)
//				{
//					min = str[i];
//					tmp.push_back(str[i++]);
//				}
//
//				if (tmp.size() > len)
//				{
//					ret.swap(tmp);
//					len = ret.size();
//				}
//			}
//		}
//		cout << ret << endl;
//	}
//}

#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
int main()
{
	string str;
	while (getline(cin,str))
	{
		vector<int> v;
		for (size_t i = 0; i < str.size(); i++)
		{
			if ()
		}
		size_t len = v.size();
		size_t count = 1;
		sort(v.begin(), v.end());
		for (size_t i = 0; i < len - 1; i++)
		{
			while (v[i] == v[i + 1])
			{
				count++;
			}
			if (count >= len >> 1)
				cout << v[i] << endl;
			i++;
		}
	}
	
}