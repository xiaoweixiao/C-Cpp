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

typedef void (*FUNC)();//����ָ��

void PrintVirtable(int *table)//ʵ��������Ĳ�����Ҫ������ָ�룬��Ϊ����ָ����int*ͬ�������ĸ��ֽڣ��������ﻯ��Ϊ��
{
	for (int i = 0; table[i] != 0; i++)
	{
		printf("��%d���麯��%p->",i, &table[i]);
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
	//ȡ��f�ĵ�ַ��ǿ��ת����int*���͵�ָ��,�����ü��ɵõ�����f��ǰ�ĸ��ֽڵ�����(���ĸ��ֽڵ��������麯���ĵ�ַ),
	//��Ϊ����PrintVirtable�Ĳ�����int*���ͣ�������(*((int*)&f))����һ����int*����ָ�룬������Ҫǿ��ת����
	PrintVirtable((int*)(*((int*)&s)));
	system("pause");
	return 0;
}
