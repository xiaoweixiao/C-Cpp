//#include<iostream>
//using namespace std;
//int F(int n)
//{
//	if (n < 2)
//		return n;
//	else if (n ==2)
//		return 1;
//	else
//	{
//		int first = 1;
//		int second = 1;
//		for (int index = 3; index <= n; ++index)
//		{
//			int tmp = second;
//			second = first + second;
//			first = tmp;
//		}
//		return second;
//	}
//}
//int main()
//{
//	int a ;
//	cin >> a;
//	cout<<F(a);
//	system("pause");
//}

//#include<iostream>
//#include<string>
//using namespace std;
//
//class Person{
//protected:
//	string _name;
//};
//
//class Student:public Person
//{
//	int _num;
//public:
//	void Show()
//	{
//		cout << "Name:" << _name << endl << "Num:" << _num << endl;
//	}
//};
//int main()
//{
//	Person p;
//	Student s;
//	p = s;//子类对象赋值給父类
//
//	Person* pp = &s;//父类指针指向子类
//	Person& bp = s;//父类引用指向子类
//
//	Student* sp = (Student*)&p;//子类指针指向父类，需要强转才可以
//	Student& x = (Student&)p;//子类引用指向父类，需要强转才可以
//
//	system("pause");
//}


//#include<iostream>
//using namespace std;
//class Motor{
//public:
//	Motor(const int displacement=5000)
//		:_displacement(displacement)
//	{
//		cout << "Motor construct" << endl;
//	}
//protected:
//	int _displacement;
//};
//class Wheel{
//public:
//	Wheel(const int&num)
//	:_num(num)
//	{
//		cout << "Wheel construct" << endl;
//	}
//protected:
//	int _num;
//};
//
//class Car :private Motor, protected Wheel
//{
//public:
//	Car(const int& displacement,const int& num,const int& val)
//		:Motor(displacement)
//		, Wheel(num)
//		, _val(val)
//	{
//		cout << "Car construct" << endl;
//	}
//	void Show()
//	{
//		cout << "发动机排放量：" << _displacement << "\n轮胎数：" << _num << "\n价值" << _val << "万" << endl;
//	}
//private:
//	int _val;
//};
//
//int main()
//{
//	Car c(6000, 4, 20);
//	c.Show();
//	system("pause");
//	return 0;
//}




//#include<iostream>
//
//using namespace std;
//
//class Father{
//public:
//	Father(const int& f)
//		:_f(f)
//	{}
//	void Show()
//	{
//		cout << _f << endl;
//	}
//protected:
//	int _f;
//};
//class Son:public Father
//{
//public:
//	Son(const int& f,const int& s)
//		:Father(f)
//		, _s(s)
//	{
//
//	}
//	void Show()
//	{
//		cout << _s << endl;
//	}
//private:
//	int _s;
//};
//
//int main()
//{
//	Son s(1000,500);
//	s.Show();
//	s.Father::Show();
//	system("pause");
//}


//#include<iostream>
//#include<string>
//
//using namespace std;
//
//class Grandfather{
//public:
//	int a;
//};
//
//class Father :virtual public Grandfather
//{
//public:
//	int b;
//};
//
//class Mother :virtual public Grandfather
//{
//public:
//	int c;
//};
//
//class Son :public Father,public Mother
//{
//public:
//	int d;
//};
//int main()
//{
//	Son s;
//	s.a = 10;
//	s.b = 20;
//	s.c = 30;
//	s.d = 40;
//	cout << sizeof(s) << endl;
//	system("pause");
//	return 0;
//}

//#include<iostream>
//
//class A{
//public:
//	virtual void func()
//	{
//
//	}
//};
//int main()
//{
//	std::cout << sizeof(A) << std::endl;
//	system("pause");
//	return 0;
//}
#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	int s;
	while (cin >> s)
	{
		int c = 0;
		int r = sqrt(s);
		for (int i = 1; i <= r; i++)
		{
			int m = s - i*i;
			int k = (int)sqrt(m);
			if (k*k == m)
				c++;
		}
		cout << c * 4 << endl;
	}
	return 0;
}