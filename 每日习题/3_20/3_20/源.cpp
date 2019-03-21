//完全正确
//#include<iostream>
//using namespace std;
//int main()
//{
//	int num;
//	while (cin >> num)
//	{
//		int ret = 0;
//		int n = num;
//		while (n)
//		{
//			if ((n & 1) == 1)
//				ret++;
//			n = n >> 1;
//		}
//		cout << ret << endl;
//	}
//	return 0;
//}


#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Gloves {
public:
	int findMinimum(int n, vector<int> left, vector<int> right) {
		
	}
};

int main()
{
	Gloves g;
	cout << g.findMinimum(4, { 0, 7, 1, 6 }, { 1, 5, 0, 6 });//左手2，右手8只
	return 0;
}