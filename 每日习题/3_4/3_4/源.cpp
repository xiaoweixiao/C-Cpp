//±‡≥Ã1Ã‚
//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//int main()
//{
//	int n;
//	while (cin >> n)
//	{
//		vector<int> level(3 * n);
//		for (int i = 0; i < (3 * n); i++)
//			cin >> level[i];
//
//		sort(level.begin(), level.end());
//		
//		long long sum = 0;
//		for (int i = n; i <= 3 * n - 2; i += 2)
//			sum += level[i];
//		cout << sum << endl;
//	}
//	return 0;
//}


#include<iostream>
#include<string>
using namespace std;
int main()
{
	string str1;
	string str2;
	string ret;
	while (getline(cin,str1))
	{
		getline(cin, str2);
		int hash[256] = { 0 };
		for (int i = 0; i < str2.size(); i++)
		{
			hash[str2[i]]++;
		}

		for (int i = 0; i < str1.size(); i++)
		{
			if (hash[str1[i]] == 0)
				ret.push_back(str1[i]);
		}
		cout << ret << endl;
	}
}



//1
//int main()
//{
//	int x, y, count = 0;
//	for (x = 0, y = 0; (y = 123) && (x < 4); x++)
//		count++;
//	cout << count << endl;
//	system("pause");
//}

//2
//#include<iostream>
//using namespace std;
//
//int main(void)
//{
//	printf("%s , %5.3s\n", "computer", "computer");
//	system("pause");
//	return 0;
//}

