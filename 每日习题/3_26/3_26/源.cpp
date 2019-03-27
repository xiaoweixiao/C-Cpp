//#include<iostream>
//#include<string>
//#include<algorithm>
//using namespace std;
//
//int main()
//{
//	string str;
//	while (cin >> str)
//	{
//		reverse(str.begin(), str.end());
//	}
//	cout << str << endl;
//	system("pause");
//}

#include<iostream>
using namespace std;
bool IsSushu(int num)
{
	if (num < 2)
		return false;
	else if (num == 2)
		return true;
	for (int i = 2; i < num; i++)
	{
		if (num % i == 0)
			return false;
	}
	return true;
}
int main()
{
	int num;
	while (cin >> num)
	{
		int start = num / 2;
		for (int i = start; i > 0; i--)
		{
			if (IsSushu(i))
			{
				for (int j = start; j < num; j++)
				{
					if (IsSushu(j) && i + j == num)
					{
						cout << i << endl << j << endl;
						return 0;
					}
				}
			}
			
		}
	}
	return 0;
}