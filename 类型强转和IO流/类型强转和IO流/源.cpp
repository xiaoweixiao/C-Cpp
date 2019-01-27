//#include<iostream>
//using namespace std;
//int main()
//{
//	volatile const int a = 10;
//	int*p =(int*) &a;
//	*p = 20;
//	cout << a << endl;
//	system("pause");
//	return 0;
//}

//#include<iostream>
//#include<string>
//using namespace std;
//int main()
//{
//	int a = 10;
//	int*p = &a;
//
//	int b = (int)p;
//	system("pause");
//	return 0;
//}

//#include<iostream>
//using namespace std;
//int main()
//{
//	const int a = 10;
//	int*p = const_cast<int*>(&a);
//	*p = 20;
//	cout << a << endl;
//	system("pause");
//	return 0;
//}

#include<iostream>
using namespace std;
int main()
{
	int a = 10;
	int*p = static_cast<int*>(&a);
	*p = 20;
	cout << a << endl;
	system("pause");
	return 0;
}