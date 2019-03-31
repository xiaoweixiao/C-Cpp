//#include<iostream>
//#include<vector>
//using namespace std;
//int Son(int a, int b)//最大公约数
//{
//	while (a%b)
//	{
//		int tmp = b;
//		b = a%b;
//		a = tmp;
//	}
//	return b;
//}
//int main()
//{
//	int n, a;
//	while (cin >> n >> a)
//	{
//		int c = a;
//		vector<int> b(n);
//		for (int i = 0; i < n; i++)
//			cin >> b[i];
//		for (int i = 0; i < n; i++)
//		{
//			if (b[i] <= c)
//				c = c + b[i];
//			else
//				c += Son(c, b[i]);
//		}
//		cout << c << endl;
//	}
//	
//	system("pause");
//	return 0;
//}

#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;
int main()
{
	string str;
	while (cin >> str)
	{
		unordered_map<char, int> umap;
		for (size_t i = 0; i < str.size(); i++)
			umap[str[i]]++;

		unordered_map<char, int>::iterator it = umap.begin();
		while (it != umap.end())
		{
			if (it->second == 1)
			{
				cout << it->first;
				break;
			}
			it++;
		}
		if (it == umap.end())
			cout << -1 << endl;
	}
	system("pause");
	return 0;
}
