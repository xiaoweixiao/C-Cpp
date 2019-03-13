//#include<iostream>
//#include<string>
//#include<vector>
//using namespace std;
//int main()
//{
//	int n;
//	while (cin >> n)
//	{
//		vector<string> str(n);
//		for (int i = 0; i < n; i++)
//			cin >> str[i];
//
//		bool dict = true, length = true;
//		for (int i = 0; i < n - 1; i++)
//		{
//			if (str[i].size()>str[i + 1].size())
//				length = false;
//			size_t shortlen = str[i].size() < str[i + 1].size() ? str[i].size() : str[i + 1].size();
//			for (size_t j = 0; j<shortlen; j++)
//			{
//				while (dict&&str[i][j]>str[i + 1][j])
//					dict = false;
//			}
//			if (dict&&shortlen == str[i + 1].size())
//				dict = false;
//		}
//		if (dict&&length)
//			cout << "both" << endl;
//		else if (dict && !length)
//			cout << "lexicographically" << endl;
//		else if (!dict&&length)
//			cout << "lengths" << endl;
//		else
//			cout << "none" << endl;
//	}	
//	return 0;
//}
#include<iostream>
using namespace std;

int MinTimes(int& num1, int&num2)
{
	int times = num1;
	if (num1 == num2)return num1;
	else
	{
		if (num2%num1 == 0)
			return num2;
		while (num2%num1)
		{
			times *= num1;
			int tmp = num1;
			num1 = num2%num1;
			num2 = tmp;
		}
	}
}
int main()
{
	int num1,num2;
	cin >> num1 >> num2;
	cout << MinTimes(num1, num2) << endl;
	system("pause");
	return 0;
}