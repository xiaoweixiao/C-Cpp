//#define _CRT_SECURE_NO_WARNINGS
//#include<iostream>
//
//#define Swap(a,b) \
//do{\
//	int c=a;\
//	a=b;\
//	b=c;\
//}while(0);
//
//#define Max(a,b) (((a)>(b))?(a):(b))
//using namespace std;
//
//int main()
//{
//	int x = 3;
//	int y = 7;
//	int z = Max(x++, y++);
//	cout << "x="<<x << ' '<<"y=" << y <<' '<<"z="<< z << endl;
//
//	system("pause");
//	return 0;
//}

//#include<iostream>
//#define Test(Test1,Test2)\
//do{\
//	std::cout << #Test1"and " ##Test2<< std::endl;\
//} while (0);
//int main()
//{
//	Test("I am the head", "I am the tail");
//	system("pause");
//	return 0;
//}
//#include<iostream>
//
//int che_sys1()
//{
//	int i = 1;
//	char*p= (char*)&i;//&i取出整型i的地址，并取出整型的第一个字节
//	return *p;         
//}
//int che_sys2()
//{
//	union un{
//		int i;
//		char c;
//	}u;
//	u.i = 1;
//	return u.c;
//}
//int main()
//{
//	int ret = -1;
//	ret = che_sys1();
//	if (ret == 1)
//		std::cout << "小端存储" << std::endl;
//	else
//		std::cout << "大端存储" << std::endl;
//	ret = -1;
//	ret = che_sys2();
//	if (ret == 1)
//		std::cout << "小端存储" << std::endl;
//	else
//		std::cout << "大端存储" << std::endl;
//	system("pause");
//	return 0;
//}

//#include<stdio.h>
//#include<stdlib.h>
//struct stu
//{
//
//	short c;
//	double a;
//	int b;
//	
//}x;
//int main()
//{
//	printf("%d\n", sizeof(x.c));
//	printf("%d\n", sizeof(x.a));
//	printf("%d\n", sizeof(x.b));
//	printf("%d\n", sizeof(x));
//	system("pause");
//	return 0;
//}



//#include<iostream>

//void func_val(int a)
//{
//	a = 1;
//}
//void func_addr(int*a)
//{
//	*a = 2;
//}
//void func_quote(int&a)
//{
//	a=3;
//}
//int main()
//{
//	int a = 0;
//	std::cout << "初值:" << a << std::endl;
//	func_val(a);
//	std::cout << "传值:" << a << std::endl;
//	func_addr(&a);
//	std::cout << "传地址:" << a << std::endl;
//	func_quote(a);
//	std::cout << "传引用" << a << std::endl;
//	system("pause");
//}
#include<iostream>
using namespace std;
#define N 3
void func(int (*a)[N])
{
	int b[N][N];
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			b[i][j] = a[j][i];
		}
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			a[i][j] = b[i][j];
		}
	}
}
int main()
{

	int a[N][N];
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			a[i][j] = rand() % 10;
	}
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++)
			cout << a[i][j] << ' ';
		cout << endl;
	}
	func(a);
	cout << endl << endl;
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++)
			cout << a[i][j] << ' ';
		cout << endl;
	}
	system("pause");
}