#include<iostream>

using namespace std;

class Father{
public:
	virtual void fun1()
	{
		cout << "Father fun1()" << endl;
	}
	virtual void fun2()
	{
		cout << "Father fun2()" << endl;
	}
public:
	int _f;
};

class Son :public Father
{
public:
	virtual void fun1()
	{
		cout << "Son fun1()" << endl;
	}
	virtual void fun3()
	{
		cout << "Son fun3()" << endl;
	}
public:
	int _s;
};

typedef void (*FUNC)();//函数指针

void PrintVirtable(int *table)//实际上这里的参数需要传函数指针，因为函数指针与int*同样都是四个字节，所以这里化繁为简
{
	for (int i = 0; table[i] != 0; i++)
	{
		printf("第%d个虚函数%p->",i, &table[i]);
		FUNC f = (FUNC)table[i];
		f();
	}
	cout << endl;
}
int main()
{
	Father f;
	Son s;
	s._f = 1;
	s._s = 2;
	PrintVirtable((int*)(*((int*)&f)));
	//取出f的地址，强制转化成int*类型的指针,解引用即可得到对象f的前四个字节的内容(这四个字节的内容是虚函数的地址),
	//因为函数PrintVirtable的参数是int*类型，而现在(*((int*)&f))并不一定是int*类型指针，所以需要强制转化。
	PrintVirtable((int*)(*((int*)&s)));
	system("pause");
	return 0;
}
