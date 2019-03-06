//#include<iostream>
//#include<string>
//#include<set>
//using namespace std;
//int main()
//{
//	int n;
//	set<int> ret;
//	string in;
//	while (cin >> in)
//	{
//		n = in[0];
//		for (size_t i = 1; i < in.size(); i++)
//			ret.insert(in[i]);
//	}
//	int first = ret[n];
//}

//#include<iostream>
//#include<string>
//using namespace std;
//int main()
//{
//	string str;
//	while (getline(cin,str))
//	{
//		size_t pos = str.find(".");
//		string ret = str.substr(0, pos + 1);
//		string dele = str.substr(pos + 2);
//
//		for (size_t i = 0; i < dele.size(); i++)
//		{
//			string::iterator it = ret.begin();
//			while (it != ret.end())
//			{
//				if (dele[i] == *it)
//				{
//					ret.erase(it);
//					it = ret.begin();
//				}
//				it++;
//			}
//		}
//		cout << ret << endl;
//	}
//}


#include<iostream>
using namespace std;

int main(void)
{
	printf("%s , %5.3s\n", "computer", "computer");
	system("pause");
	return 0;
}


//int main()
//{
//	int x, y, count = 0;
//	for (x = 0, y = 0; (y = 123) && (x < 4); x++)
//		count++;
//	cout << count << endl;
//	system("pause");
//}