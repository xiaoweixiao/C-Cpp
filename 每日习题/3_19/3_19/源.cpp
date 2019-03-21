//#include<iostream>
//using namespace std;
//
//int main()
//{
//	int year = 0, month = 0, day = 0, ret = 0;
//	int Day[13] = { 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365 };
//	while (cin >> year >> month >> day)
//	{
//		ret = Day[month - 1] + day;
//		if (month>2)
//		{
//			if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
//				ret += 1;
//		}
//		cout << ret << endl;
//	}
//	return 0;
//}


#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	int n;
	int count = 0;
	while (cin >> n)
	{
		vector<int> num(n);
		for (int i = 0; i < n; i++)
			cin >> num[i];
		sort(num.begin(), num.end());
		
		int x = n;
		int sum = 0, mu = 0;
		while (x--)
		{
			sum = 0, mu = 0;
			for (int i = 0; i < n; i++)
			{
				sum += num[i];
				mu += num[i];
			}
			if (sum>mu)
				count++;
		}
	}
	cout << count << endl;
	return 0;
}