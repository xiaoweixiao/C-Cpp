////剑指35
//#include<iostream>
//using namespace std;
//int main()
//{
//
//}

//1正确
//#include<iostream>
//using namespace std;
//int main()
//{
//	int n;
//	while (cin >> n)
//	{
//		if (n > 0 && n <= 500000)
//		{
//			int ret = 0;
//			for (int j = 0; j <= n; j++)
//			{
//				int sum = 0;
//				for (int i = 1; i < j; i++)
//				{
//					if (j%i == 0)
//						sum += i;
//				}
//				if (sum>0&&sum == j)
//					ret++;
//			}
//			cout << ret << endl;
//		}
//		else
//			cout << -1 << endl;
//	}
//	return 0;
//}


//2
#include<iostream>
#include<string>
#include <string.h>
using namespace std;
int main()
{
	string str;
	while (getline(cin, str))
	{
		size_t pos = str.find('-');
		string s1 = str.substr(0, pos);//起始位置，步长
		string s2 = str.substr(pos + 1);

		//个子、对子、三个、顺子(连续5张)，四个炸弹、王炸
		int size1 = s1.size();
		int size2 = s2.size();
		if ((strcmp(s1.c_str(), "joker JOKER") == 0) || (strcmp(s1.c_str(), "JOKER joker") == 0))
		{
			cout << s1 << endl;
			return 0;
		}
		else if ((strcmp(s2.c_str(), "joker JOKER") == 0) || (strcmp(s2.c_str(), "JOKER joker") == 0))
		{
			cout << s2 << endl;
			return 0;
		}
		if (size1>4&&size2>4&&s1[0]<s1[1]&&s2[0]<s2[1])//顺子
		{
			//JQKA2
			if (s1[0]=='J')
			{
				cout << s1 << endl;
				return 0;
			}
			if (s2[0] == 'J')
			{
				cout << s2 << endl;
				return 0;
			}
			else if (s1[0]>2&&s1[0]<11&&s1[0]<s2[0])
			{
				cout << s2 << endl;
				return 0;
			}
			else if (s1[0]>2 && s1[0]<11 && s1[0]<s2[0])
			{
				cout << s2 << endl;
				return 0;
			}
			else
			{
				cout << "ERROR" << endl;
				return 0;
			}
		}
		else if (size1 == size2&&size1 > 0 && size1 < 8)
		{
			if (s1[0]>2 && s1[0] < 11)//3~10的纯子
			{
				if (s1[0]<s2[0])
				{
					cout << s2 << endl;
					return 0;
				}
				else
				{
					cout << s1 << endl;
					return 0;
				}
			}
			else if (s1[0]=='A'&&!s2[0]!='2')
			{
				cout << s1 << endl;
				return 0;
			}
		}
		else
		{
			cout << "ERROR" << endl;
			return 0;
		}
	}
}