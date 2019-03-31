//#include<iostream>
//#include<vector>
//using namespace std;
//int main()
//{
//	//3
//	//3 1		1 2 3 4 5 6
//	//3 2		1 2 3 4 5 6 
//	//2 2		1 1 1 1
//	size_t group;
//	cin >> group;
//	vector<vector<int>> input(group);
//	for (size_t i = 0; i < group; i++)
//	{
//		size_t n, k;
//		cin >> n >> k;
//		input[i].resize(2 * n);
//		for (size_t j = 0; j < 2 * n; j++)
//			cin >> input[i][j];
//
//		vector<int> out(input[i]);
//		int index = out.size() - 1;
//		while (k--)
//		{
//			index = out.size() - 1;
//			int left = n - 1, right = 2 * n - 1;
//			while (left >= 0)
//			{
//				out[index--] = input[i][right--];
//				out[index--] = input[i][left--];
//			}
//			for (size_t y = 0; y < out.size(); y++)
//				input[i][y] = out[y];
//		}
//		for (size_t x = 0; x < out.size(); x++)
//			cout << out[x] << ' ';
//		cout << endl;
//	}
//	system("pause");
//	return 0;
//}

//10
//UUUU
//7 8 9 10
//7

#include<iostream>
#include<string>
using namespace std;
int main()
{
	int n;
	string s;
	char c;

	cin >> n;
	int cur = 0;
	while (cin >> c)
		s.push_back(c);
	for (size_t i = 0; i < s.size(); i++)
	{
		if (s[i] == 'U')
		{
			if (cur == 0)
				cur = n - 1;
			else
				cur--;
		}
		else
		{
			if (cur == n-1)
				cur = 0;
			else
				cur++;
		}
	}

	for (int i = cur; i < n; i++)
		cout << i+1 << ' ';
	cout<<endl<< cur+1 << endl;
	system("pause");
	return 0;
}