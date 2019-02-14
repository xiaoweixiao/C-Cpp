//#include<iostream>
//using namespace std;
//
//int main()
//{
//	cout << sizeof(double) << endl;
//	system("pause");
//}
//#include<iostream>
//using namespace std;
//
//int main()
//{
//	struct node
//	{
//		unsigned int a : 4;     
//		unsigned int : 4;     
//		unsigned int c : 4;     
//		int d : 32;             
//		int e: 6;             
//	};
//	printf("%d\n", sizeof(node));
//	system("pause");
//}


//struct S1
//{
//	char c1;//1		1
//	int i;//4		8
//	char c2;//1		12
//};
//struct S2
//{
//	char c1;//1		1
//	char c2;//1		4
//	int i;//4		8
//};
//struct A
//{
//	int _a : 2;
//	int _b : 5;
//	int _c : 10;
//	int _d : 30;
//};






//union Un
//{
//	char c;
//	int i;
//};

//union Un1
//{
//	char c[5];
//	int i;
//};
//union Un2
//{
//	short c[7];
//	int i;
//};
//int main()
//{
//	//联合变量的定义
//	union Un1 un1;
//	union Un2 un2;
//	//计算连个变量的大小
//	printf("%d\n", sizeof(un1));
//	printf("%d\n", sizeof(un2));
//	system("pause");
//}



//typedef enum Color
//{
//};
//int main()
//{
//	cout <<sizeof(Color) << endl;
//	system("pause");
//}


#include<iostream>
using namespace std;
union ip_addr
{
	unsigned long addr;
	struct
	{
		unsigned char c1;
		unsigned char c2;
		unsigned char c3;
		unsigned char c4;
	}ip;
};
int main()
{
	union ip_addr my_ip;
	my_ip.addr = 176238749;
	printf("%d.%d.%d.%d\n", my_ip.ip.c4, my_ip.ip.c3, my_ip.ip.c2, my_ip.ip.c1);
	system("pause");
}