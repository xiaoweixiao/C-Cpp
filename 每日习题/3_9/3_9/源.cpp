//#include<iostream>
//using namespace std;
//int main()
//{
//	int W, H, ret;
//	while (cin >> W >> H)
//	{
//		ret = W*H;
//		for (int i = 2; i < W; i++)
//		{
//			if (i % 2 == 0)
//			{
//				ret -= 2;
//			}
//		}
//		for (int j = 2; j < H; j++)
//		{
//			if (j % 2 == 0)
//			{
//				ret-=2;
//			}
//		}
//	}
//	cout << ret << endl;
//	system("pause");
//}


#include<iostream>
#include<vector>
using namespace std;
struct Point{
	int x;
	int y;
};
vector<Point>& FindPath()
{
	path.push_back({ 0, 0 });
	for (int i = 0; i < m; i++)
	{
		int j = 0;
		for (; j < n; j++)
		{
			if (map[i][j] == 1)
				path.push_back({ i, j });
		}
		if (i == 0 && j == n - 1)
		{
			if (path.size()<minpower)

		}
	}
}
int main()
{
	int m, n, P;
	while (cin >> m >> n >> P)
	{
		int minpower = 3 * m*n;
		vector<Point> path;
		vector<vector<int>> map;
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
				scanf("%d", map[i][j]);
		}
	}
}