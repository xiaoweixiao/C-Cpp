#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main()
{
	string str;
	size_t n = 0;
	while (getline(cin, str))
	{
		vector<string> ret;
		size_t begin = 0;
		for (size_t i = 0; i < str.size(); i++)
		{
			string s;
			if (str[i] == '"')
			{
				begin = i + 1;
				while (str[i] != '"')
					i++;
				s = str.substr(begin, i);
			}
			else
			{
				begin = i;
				while (str[i] != ' ')
					i++;
				s = str.substr(begin, i);
			}
			ret.push_back(s);
		}
		for (size_t i = 0; i < ret.size(); i++)
			cout << ret[i] << endl;
	}
}

//#include<iostream>
//#include<vector>
//using namespace std;
//
//int main()
//{
//	int N, M;
//	while (cin >> N >> M)
//	{
//		int count = 0;
//		while (N < M)
//		{
//			for (int i = N - 1; i > 1; i--)
//			{
//				if (N%i == 0 && N + i <= M)
//				{
//					N = N + i;
//					count++;
//					break;
//				}
//			}
//		}
//		cout << count << endl;
//	}
//}