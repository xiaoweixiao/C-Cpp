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
////��ϰ2
//struct S2
//{
//	char c1;
//	char c2;
//	int i;
//};

//��ϰ3
//struct S3
//{
//	double d;
//	char c;
//	int i;
//};
//
////��ϰ4-�ṹ��Ƕ������
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

//λ�ζ���
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

//���1��
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
//		//�Ҳ�����߲���
//		for (int i = 1; i<n - 1; i++)
//		{
//			if ((in[i]>in[i - 1] && in[i]>in[i + 1]) || (in[i] < in[i - 1] && in[i] < in[i + 1]))
//			{
//				team++;
//
//				//�������һ��λ���Ѿ��ȽϹ��˱�������������1 2 1 2 1 2 1 2 1�ͻ����
//				if (i != n - 3)
//					i++;
//			}
//			
//		}
//		cout << team << endl;
//	}
//	return 0;
//}
//���2��
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
//		reverse(str.begin(), str.end());//��������Ҫ�󵥴����������ٰ�ÿ��������ĸ�������
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
	//�����ڽ�����һ����ͷ�嵽str
	string str, temp;
	cin >> str;
	while (cin >> temp)
		str = temp + " " + str;
	cout << str << endl;
	return 0;
}