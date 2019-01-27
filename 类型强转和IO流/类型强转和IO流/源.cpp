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
//	Student* sp = dynamic_cast<Student*>(p);//只允许子类对象指针转换
//	sp->Print();
//}
//int main()
//{
//	Person p;
//	Student s;
//	//Func(&p);//使用dynamic_cast，不能将父类指针转换成子类指针，防止了越界行为
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
	size_t pos = 0;
	int end= 3;
	while (end >= pos)
		--end;
	system("pause");
	return 0;
}