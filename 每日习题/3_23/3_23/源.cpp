//网上看了思路，代码过了
//#include<iostream>
//#include<vector>
//
//using namespace std;
//
//int main()
//{
//	//f(n)=f(n-1)+f(n-3)*2
//	int month;
//	while (cin >> month)
//	{
//		vector<int> num(month);
//		for (size_t i = 0; i < 2; i++)
//			num[i] = 1;
//		if (month < 4)
//		{
//			cout << 1 << endl;
//			return 0;
//		}
//
//		for (int i = 2; i < month; i++)
//			num[i] = num[i - 1] + num[i - 2];
//		cout << num[month - 1] << endl;
//	}
//	return 0;
//}

//第二题不会做，这是网上拷贝的
#/*include<cstdio>
#include<string>
#include<cstring>
#include<iostream>
#include<algorithm>
#define N 20
using namespace std;
int f[N][N];
string a, b;
void init(){
	getline(cin, a);
	getline(cin, b);
	memset(f, 0, sizeof f);
	f[1][1] = 1;
	if (a[0] == '*') f[1][0] = 1;
	if (a[0] == '?') f[0][0] = 1;
}
int main(){
	init();
	for (int i = 1; i <= a.size(); i++)
	for (int j = 1; j <= b.size(); j++)
	{
		if (a[i - 1] == '?') f[i][j] = f[i - 1][j - 1];
		else if (a[i - 1] == '*' && (f[i - 1][j - 1] || f[i][j - 1] || f[i - 1][j])) f[i][j] = 1;
		else if (a[i - 1] == b[j - 1] && f[i - 1][j - 1]) f[i][j] = 1;
	}
	if (f[a.size()][b.size()]) cout << "matched" << endl;
	else cout << "not matched" << endl;
	return 0;
}*/

