#include<iostream>
#include<assert.h>
using namespace std;

//日期类
class Date
{
	friend class Time;
public:
	
	Date(int year=2018,int month=6,int day=19)
		:_year(year)
		,_month(month)
		,_day(day)
	{
		cout << "Date()" << endl;
	}

	Date(const Date& d)
		:_year(d._year)
		, _month(d._month)
		, _day(d._day)
	{
		cout << "Date(const Date& d)" << endl;
	}

	Date& operator =(const Date& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;

		cout << "Date& operator=(const Date& d)" << endl;
		return *this;
	}

	~Date()
	{
		cout << "~Date()" << endl;
	}
	void Show()
	{
		cout << "Date show:"<<_year << ":" << _month << ":" << _day << endl;
	}
	Date&CheckDate()
	{
		int date[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		if (_month == 2 && ((_year % 4 == 0 && _year % 100 != 0) || (_year % 400 == 0)))
		{
			date[2] += 1;
		}
	}
private:
	int _year;
	int _month;
	int _day;
};
//时间类
class Time{
public:
	void Show()
	{
		cout <<"Time Show"<< _d._year << ":" << _d._month << ":" << _d._day;
		cout << _hour << ":" << _minute << ":" << _second << endl;
	}
	Time(const int hour = 23, const int minute = 59, const int second = 59)
		:_hour(hour)
		,_minute(minute)
		,_second(second)
	{
		if (!Islegal(_hour, _minute, _second))
			assert(0);
		cout << "Time construct" << endl;
	}
	/*Time(const int&hour,const int&minute,const int&second)
	:_hour(hour)
	,_minute(minute)
	,_second(second)
	{
	}*/
	Time(const Time&t)
		:_hour(t._hour)
		, _minute(t._minute)
		, _second(t._second)
	{
		cout << "Time copy" << endl;
	}
	Time&operator=(const Time&t)
	{
		_hour = t._hour;
		_minute = t._minute;
		_second = t._second;
		return*this;
	}
	~Time()
	{
		cout << "Time distruct" << endl;
	}
	Time&CheckTime()
	{
		while (!(_second < 60))
		{
			_second -= 60;
			_minute += 1;
		}
		while (!(_minute < 60))
		{
			_minute -= 60;
			_hour += 1;
		}
		while (!(_hour < 24))
		{
			_hour -= 24;
			_d._day += 1;
		}
		_d.CheckDate();
		return *this;
	}
	Time operator+(const Time &t) const
	{
		Time t1 = (*this);
		Time t2 = t;
		t1._minute += t2._minute;
		t1._minute += t2._minute;
		t1._second += t2._second;
		

		return t1;
	}
private:
	bool Islegal(int&hour, int&minute, int&second)
	{
		if (hour >= 0 && hour < 24 && minute >= 0 && minute < 60 && second >= 0 && second < 60)
			return true;
		else
			return false;
	}
private:
	int _hour;
	int _minute;
	int _second;
	Date _d;
};

int main()
{
	//测试Date类
	Date d1(2018, 9, 19);
	Date d2(d1);
	Date d3;
	d3 = d1;
	d1.Show();
	d2.Show();
	d3.Show();

	//测试Time类
	system("pause");
	return 0;
}
//#include<iostream>
//
//using namespace std;
//
//class Time{
//	int _hour;
//	int _minute;
//	int _second;
//	
//public:
//	friend ostream& operator<<(ostream&out, const Time&t);
//	friend istream& operator>>(istream&in, Time&t);
//	
//};
//ostream& operator<<(ostream&out, const Time&t)
//{
//	out << t._hour << ":" << t._minute << ":" << t._second << endl;
//	return out;
//}
//istream& operator>>(istream&in, Time&t)
//{
//	cout << "请输入年月日：" << endl;
//	in >> t._hour;
//	in >> t._minute;
//	in >> t._second;
//	return in;
//}
//int main()
//{
//	Time t1;
//	cin >> t1; 
//	cout << t1;
//	system("pause");
//	return 0;
//}

//#include<iostream>  
//using namespace std;
//
//class Date
//{
//public:
//	Date()
//	{
//		cout << "Date()" << endl;
//	}
//
//	Date(const Date& d)
//	{
//		cout << "Date(const Date& d)" << endl;
//	}
//
//	Date& operator =(const Date& d)
//	{
//		cout << "Date& operator=(const Date& d)" << endl;
//		return *this;
//	}
//
//	~Date()
//	{
//		cout << "~Date()" << endl;
//	}
//};
//
//// 1.Date 对象做参数传值 & 传引用  
//void fun1(Date d)
//{}
//
////void fun1(Date& d)  
////{}  
//
//// 2.Date 对象做返回值传值 & 传引用  
//Date fun2()
//{
//	Date d;
//	return d;
//}
//
////Date& fun2()  
////{  
////  Date d ;  
////  return d ;  
////}  
//
//// 3.Date 对象做临时返回值传值 &传引用(编译器优化问题)  
//Date fun3()
//{
//	return Date();
//}
//
////Date& fun3()  
////{  
////  return Date ();  
////}  
//
//void Test1()
//{
//	Date d1;
//	fun1(d1);
//}
//
//void Test2()
//{
//	Date d2 = fun2();
//}
//
//void Test3()
//{
//	Date d3;
//	d3 = fun3();
//}
//int main()
//{
//	Test2();
//	system("pause");
//}
//#include <iostream>
//using namespace std;
//
//class Cpoint{
//public:
//	static int value;
//	static int num;
//	Cpoint(int x, int y){
//		xp = x; yp = y;
//		value++;
//		cout << "调用构造:" << value << endl;
//	}
//
//	~Cpoint(){ num++; cout << "调用析构:" << num << endl; }
//
//private:
//	int xp, yp;
//};
//
//int Cpoint::value = 0;
//int Cpoint::num = 0;
//class CRect{
//public:
//	CRect(int x1, int x2) :mpt1(x1, x2), mpt2(x1, x2) { cout << "调用构造\n"; }
//	~CRect(){ cout << "调用析构\n"; }
//private:
//	Cpoint mpt1, mpt2;
//};
//
//int main()
//{
//	CRect p(10, 20);
//	cout << "Hello, world!" << endl;
//	system("pause");
//	return 0;
//}