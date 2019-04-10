//3
//#include<iostream>
//using namespace std;
//int main()
//{
//	char* szX = "abc";
//	char* szY = "abc";
//	char* x = "A";
//	szX = x;
//	cout << *szX << endl << *szY << endl;
//	system("pause");
//}

//5
//#include<iostream>
//using namespace std;
//struct S1
//{
//	char c1;
//	int i;
//	char c2;
//};
//
//
////练习2
//struct S2
//{
//	char c1;
//	char c2;
//	int i;
//};

//练习3
//struct S3
//{
//	double d;
//	char c;
//	int i;
//};
//
////练习4-结构体嵌套问题
//struct S4
//{
//	char c1;
//	struct S3 s3;
//	//double d;
//};
//int main()
//{
//	printf("S1:%d\n", sizeof(struct S1));
//	printf("S2:%d\n", sizeof(struct S2));
//	printf("S3:%d\n", sizeof(struct S3));
//	printf("S4:%d\n", sizeof(struct S4));
//	system("pause");
//}

//位段对齐
//#include<iostream>
//using namespace std;
//struct S
//{
//	char a : 3;//1
//	char b : 4;//1
//	char c : 5;//2
//	char d : 4;//3
//};
//struct A{
//	unsigned a : 19;	    //4
//	unsigned b : 11;		//4
//	unsigned c : 4;			//8
//	unsigned d : 29;		//12
//	char index;			    //16
//};
//int main()
//{
//	cout << sizeof(struct  S) << endl;
//	system("pause");
//}

//编程1题
//#include<iostream>
//#include<vector>
//using namespace std;
//int main()
//{
//	int n;
//	while (cin >> n)
//	{
//		vector<int> in(n);
//		for (int i = 0; i<n; i++)
//			cin >> in[i];
//
//		int team = 1;
//		//找波峰或者波谷
//		for (int i = 1; i<n - 1; i++)
//		{
//			if ((in[i]>in[i - 1] && in[i]>in[i + 1]) || (in[i] < in[i - 1] && in[i] < in[i + 1]))
//			{
//				team++;
//
//				//波峰的下一个位置已经比较过了必须跳过，比如1 2 1 2 1 2 1 2 1就会出错
//				if (i != n - 3)
//					i++;
//			}
//			
//		}
//		cout << team << endl;
//	}
//	return 0;
//}
//编程2题
//#include<iostream>
//#include<string>
//#include<algorithm>
//
//using namespace std;
//int main()
//{
//	string str;
//	while (getline(cin, str))
//	{
//		reverse(str.begin(), str.end());//整体逆序，要求单词逆序，现在再把每个单词字母逆序回来
//		string::iterator start = str.begin();
//		while (start != str.end())
//		{
//			string::iterator end = start;
//			while (end != str.end() && (*end) != ' ')
//				end++;
//			reverse(start, end);
//			if (end != str.end())
//				start = end + 1;
//			else
//				start = end;
//		}
//		cout << str << endl;
//	}
//	return 0;
//}

#include <iostream>
#include <string>
using namespace std;
// I like beijing.
//beijing.like I
int main()
{
	//类似于将单词一个个头插到str
	string str, temp;
	cin >> str;
	while (cin >> temp)
		str = temp + " " + str;
	cout << str << endl;
	return 0;
}