//#include<iostream>
//using namespace std;
//int main()
//{
//	int num;
//	int left;
//	int count = 0;
//	while (cin >> num)
//	{
//		left = 1024 - num;
//		//1	4	16	64
//		count+= left / 64;//64
//		left = left%64;
//		count += left / 16;//16
//		left = left % 16;
//		count += left / 4;//4
//		left = left % 4;
//		count += left;//1
//
//		cout << count << endl;
//	}
//}

//#include<iostream>
//#include<vector>
//#include<string>
//using namespace std;
//int main()
//{
//	int n;
//	while (cin >> n)
//	{
//		vector<string> input(n);
//		vector<string> output(n);
//		for (int i = 0; i < n; i++)
//			cin >> input[i];
//		for (int i = 0; i < n; i++)
//		{
//			string::iterator it = input[i].begin();
//			while (it < input[i].end())
//			{
//				if (it+2<input[i].end()&&*it == *(it + 1) && *(it + 1) == *(it + 2))
//				{
//					string::iterator pit = it;
//					input[i].erase(it);
//					it = pit;
//				}
//
//				if (it + 3<input[i].end() && *it == *(it + 1) && *(it + 2) == *(it + 3))
//				{
//					string::iterator pit = it;
//					input[i].erase(it+2);
//					it = pit;
//					it += 2;
//				}
//				it++;
//			}
//			cout << input[i] << endl;
//		}
//	}
//}

//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//int main()
//{
//	int ex;
//	while (cin >> ex)
//	{
//		while (ex--)
//		{
//			int n;
//			cin >> n;
//			int gift = n;
//			vector<int> fen(n);
//			for (int i = 0; i < n; i++)
//				cin >> fen[i];
//
//			for (int i = 1; i < n-1; i++)
//			{
//				if (fen[i]>fen[i - 1])
//					gift++;
//
//			}
//			cout << gift;
//		}
//	}
//}


#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	int N, M;
	while (cin >> N >> M)
	{
		vector<double> num(N);
		double ret = 0;
		for (int i = 0; i<N; i++)
			cin >> num[i];

		sort(num.begin(), num.end());
		if (M > N)
		{
			int sh = M - N;
			ret = num[N - sh];
			ret = ret / 2.0;
		}
		else
		{
			int i = 0;
			int half = num[N - 1] / 2;
			while (num[N - M-i]<half)
			{
				half = num[N - M - (++i)] / 2;
			}

			ret = half>num[N - M] ? half : num[N-M];
		}
		printf("%.2f", ret);
	}
}