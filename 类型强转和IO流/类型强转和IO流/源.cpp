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


//#include<iostream>
//using namespace std;
//
//class Person{
//protected:
//	string _name;
//	virtual void Print()
//	{
//		cout << "I am the father" << endl;
//	}
//};
//
//class Student :public Person
//{
//public:
//	int _num;
//	virtual void Print()
//	{
//		cout << "I am the son" << endl;
//	}
//};
//void Func(Person* p)
//{
//	Student* sp = dynamic_cast<Student*>(p);//ֻ�����������ָ��ת��
//	sp->Print();
//}
//int main()
//{
//	Person p;
//	Student s;
//	//Func(&p);//ʹ��dynamic_cast�����ܽ�����ָ��ת��������ָ�룬��ֹ��Խ����Ϊ
//	Func(&s);
//	system("pause");
//	return 0;
//}


//#include<iostream>
//using namespace std;
//int main()
//{
//	int a = 10;
//	int*p = static_cast<int*>(&a);
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
//	int b = reinterpret_cast<int>(p);
//	system("pause");
//	return 0;
//}


//#include<iostream>
//using namespace std;
//
//class A
//{
//public:
//	explicit A(int a)
//	{
//		cout << "A(int a)" << endl;
//	}
//private:
//	int _a;
//};
//
//int main()
//{
//	A a2 = 1;
//	system("pause");
//}


#include<iostream>
using namespace std;

int main()
{
	/*size_t pos = 0;
	int end= 3;
	while (end >= pos)
		--end;*/
	cout << sizeof(size_t) << endl;
	cout << sizeof(unsigned) << endl;
	system("pause");
	return 0;
}