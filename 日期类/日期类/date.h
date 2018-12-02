//构造析构判断合法日期初始化类表
#include<iostream>
using namespace std;
class date{
public:
	date(int year = 2018, int month = 6, int day = 16)//带缺省的构造
		:_year(year)
		, _month(month)
		, _day(day)
	{
		if (IsLegalDay(_year, _month, _day))
			;//cout << "construct" << endl;
		else
			cout << "error date" << endl;
	}
	date(const date&d)//拷贝构造
		:_year(d._year)
		, _month(d._month)
		, _day(d._day)
	{
		//cout << "copy construct" << endl;
	}
	~date()//析构
	{
		//cout << "~date()" << endl;
	}
	void Show()
	{
		cout << _year << '-' << _month << '-' << _day << endl;
	}
	date operator+(const int&day)
	{
		date tmp(*this);
		if (day <0)
		{
			return tmp - (-day);
		}
		else
		{
			tmp._day += day;
			while (tmp._day > GetMonthday(tmp._year, tmp._month))
			{
				tmp._day -= GetMonthday(tmp._year, tmp._month);
				tmp._month += 1;
				if (tmp._month == 13)
				{
					tmp._month = 1;
					tmp._year += 1;
				}
			}
		}
		return tmp;
	}
	int operator-(const date&d)
	{
		date d1(*this);
		date d2(d);
		int count = 0;
		while (d1 < d2)
		{
			d1++;
			count++;
		}
		while (d2 < d1)
		{
			d2++;
			count++;
		}
		return count;
	}
	date operator-(int day)
	{
		date tmp(*this);
		if (day < 0)
		{
			return tmp + (-day);
		}
		else
		{
			tmp._day -= day;
			while (tmp._day<1)
			{
				tmp._month -= 1;
				if (tmp._month < 1)
				{
					tmp._year -= 1;
					tmp._month = 12;
				}
				tmp._day += GetMonthday(tmp._year, tmp._month);
			}
		}
		return tmp;
	}
	
	date& operator=(const date&d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
		return *this;
	}
	bool operator>(const date&d)
	{
		if ((_year > d._year)
			|| ((_year == d._year) && (_month > d._month))
			|| ((_year == d._year) && (_month == d._month) && (_day > d._day)))
			return true;
		else
			return false;
	}
	bool operator==(const date&d)
	{
		if ((_year == d._year) && (_month == d._month) && (_day == d._day))
			return true;
		else
			return false;
	}
	bool operator!=(const date&d)
	{
		return !(*this == d);
	}
	bool operator>=(const date&d)
	{
		return (*this > d )||( *this == d);
	}

	bool operator<(const date&d)
	{
		return (!(*this>d)) && (*this != d);
	}
	bool operator<=(const date&d)
	{
		return !(*this > d);
	}

	date& operator++()
	{
		return *this = *this + 1;
	}
	date operator++(int)
	{
		date tmp(*this);
		*this = *this + 1;
		return tmp;
	}
	date& operator--()
	{
		return *this = *this - 1;
	}
	date operator--(int)
	{
		date tmp(*this);
		*this = *this - 1;
		return tmp;
	}

private:
	int GetMonthday(const int&year,const int&month)
	{
		int const montharr[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		if ((month == 2) && (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0)))
			return montharr[month] + 1;
		else
			return montharr[month];
	}
	bool IsLegalDay(const int&year,const int&month,const int&day)
	{
		if ((year > 1600) && (month>0 && month<13) && (day>0&&day < GetMonthday(year, month)))
			return true;
		else
			return false;
	}
private:
	int _year;
	int _month;
	int _day;
};