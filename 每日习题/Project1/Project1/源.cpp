#include<iostream>
#include<string>
using namespace std;


//1.完成正确
//class BinInsert {
//public:
//	int binInsert(int n, int m, int j, int i) {
//		int ret = n;
//		int move = i < j ? i : j;
//		ret += m << move;
//		return ret;
//	}
//};
//int main()
//{
//	BinInsert b;
//	cout << b.binInsert(1024, 19, 2, 6);
//}

//asdfas  werasdfaswer
int main()
{
	string s1, s2;
	while (cin >> s1 >> s2)
	{
		int ret = 0;
		for (size_t i = 0; i < s1.size(); i++)
		{
			int count = 0;
			for (size_t j = 0; j < s2.size(); j++)
			{
				int tmp = 0;
				while (s1[i] == s2[j])
				{
					i++, j++;
					tmp++;
				}
				if (tmp>count)
					count = tmp;
			}
			if (count > ret)
				ret = count;
		}
		cout << ret << endl;
	}
}