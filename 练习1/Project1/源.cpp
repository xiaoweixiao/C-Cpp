#include<iostream>

using namespace std;

int main()
{
	volatile const int a = 2;
	int* p = (int*)&a;

	*p = 3;
	cout << a << endl;
	system("pause");
}