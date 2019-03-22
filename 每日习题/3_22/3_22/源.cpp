//1.本地IDE没问题，在线OJ无法通过
//#include<iostream>
//#include<vector>
//
//using namespace std;
//int main()
//{
//	int n;
//	cin >> n;
//	if (n > 1)
//	{
//		vector<vector<int>> num;
//		num.resize(n);
//		for (int i = 0; i < n; i++)
//			num[i].resize(2 * i + 1);
//
//		for (int i = 0; i < n; i++)
//		{
//			num[i][0] = 1;
//			num[i][num[i].size() - 1] = 1;
//		}
//
//		for (int i = 1; i < n; i++)
//		{
//			for (int j = 0; j < 2 * i + 1; j++)
//			{
//				if (num[i][j] == 0)
//				{
//					if (j - 2 >= 0)
//						num[i][j] += num[i - 1][j - 2];
//					if (j - 1 >= 0)
//						num[i][j] += num[i - 1][j - 1];
//					if (j<num[i - 1].size())
//						num[i][j] += num[i - 1][j];
//				}
//			}
//		}
//
//		for (int i = 0; i < num[n - 1].size(); i++)
//		{
//			if (num[n - 1][i] % 2 == 0)
//			{
//				cout << i + 1 << endl;
//				system("pause");
//				return 0;
//			}
//		}
//		cout << -1 << endl;
//		system("pause");
//		return 0;
//	}
//}

//不会
//#include<iostream>
//#include<string>
//using namespace std;
//int main()
//{
//	string s1,s2;
//	cin >> s1 >> s2;
//	cout << s1.c_str() + s2.c_str() << endl;
//	return 0;
//}