

//ѡ��1
//int main()
//{
//	int x, y, count = 0;
//	for (x = 0, y = 0; (y = 123) && (x < 4); x++)
//		count++;
//	cout << count << endl;
//	system("pause");
//}

//ѡ��2
//#include<iostream>
//using namespace std;
//
//int main(void)
//{
//	printf("%s , %5.3s\n", "computer", "computer");
//	system("pause");
//	return 0;
//}


//���1��
//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//int main()
//{
//	int n;
//	while (cin >> n)
//	{
//		long long ret = 0;//ʹ��int��ͨ����66��
//		vector<int> in(3 * n);
//		for (int i = 0; i<3 * n; i++)
//			cin >> in[i];
//		sort(in.begin(), in.end());
//
//		//1    2    5    5    5    8
//		//3*n-2�ǵ����ڶ�������Ҳ�������һ�����λ��
//		//��һ�����λ���±���n��0��n-1��ÿ����С��
//		for (int i = n; i <= 3 * n - 2; i += 2)//i+=2���м�ճ���������һ��������
//			ret += in[i];
//		cout << ret << endl;
//	}
//	return 0;
//}


//���2��

//O(s1.size()*s2.size())
//#include<iostream>
//#include<string>
//using namespace std;
//int main()
//{
//	string s1;
//	string s2;
//	string ret;
//	while (getline(cin, s1))
//	{
//		getline(cin, s2);
//		for (size_t j = 0; j<s1.size(); j++)
//		{
//			size_t i = 0;
//			for (; i<s2.size(); i++)
//			{
//				if (s1[j] == s2[i])
//					break;
//			}
//			if (i == s2.size())
//				ret.push_back(s1[j]);
//		}
//		cout << ret << endl;
//	}
//	return 0;
//}

//O(s2.size()+256)
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
			hash[str2[i]]++;

		for (int i = 0; i < str1.size(); i++)
		{
			if (hash[str1[i]] == 0)
				ret.push_back(str1[i]);
		}
		cout << ret << endl;
	}
}