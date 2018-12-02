// 1.现代写法 
// 2.传统写法 
// 3.字符串增删查改 
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<assert.h>
#include<string.h>
using namespace std;
class String
{
public:
	String(const char* str = "")//构造函数
		:_str(new char[strlen(str) + 1])
		,_capacity ( strlen(str) + 1)
		, _size(strlen(str)+1)
	{
		strcpy(_str,str);
	}
	~String()//析构
	{
		if (_str)
			delete[] _str;
		_size = _capacity = 0;
	}
	String(const String& s)// String s2(s1)
	{
		_str = new char[s._size + 1];
		_capacity = s._capacity;
		_size = s._size;
		strcpy(_str, s._str);
	}
	char& operator[](const size_t x)
	{
		assert(x < _size);
		return _str[x];
	}
	size_t Size()
	{
		return _size;
	}
	String& operator=(const String& s)// s1 = s2
	{
		if (_str != s._str)
		{
			delete[] _str;
			_str = new char[strlen(s._str) + 1];
			strcpy(_str, s._str);
			_size = s._size;
			_capacity = s._capacity;
		}
		return *this;
	}

	//交换
	void Swap(String& s)// s1.Swap(s2); 
	{
		swap(_str, s._str);
		swap(_capacity, s._capacity);
		swap(_size, s._size);
	}
	//以C字符格式输出
	const char* c_str()
	{
		return _str;
	}
	//增
	void Expand(size_t n)
	{
		if (n > _capacity)
		{
			char* new_str = new char[n];
			strcpy(new_str, _str);
			delete[] _str;
			_str = new_str;
			_capacity = n;
		}
	}
	void Insert(size_t pos, char ch)//下标为pos的位置，插入字符ch
	{
		if (_size == _capacity)
			Expand(_capacity*2);
		//将pos位置之后的数据由后向前依次向后挪一位
		size_t i = _size;
		while (i >pos)
		{
			_str[i] = _str[i - 1];
		}

		_str[pos] = ch;
		_size++;
	}
	void Insert(size_t pos, const char* str)//下标为pos的位置，插入String str
	{
		if (_size + strlen(str) >= _capacity)
			Expand(_size + strlen(str) + 1);
		//将pos位置之后的数据由后向前依次向后挪strlen(str)位
		size_t end = _size + strlen(str);
		size_t old_end = _size;
		while (old_end > pos)
		{
			_str[end] = _str[old_end];
			end--;
			old_end--;
		}
		//
	}
	
	void PushBack(char ch)
	{
		if (_size == _capacity)
			Expand(_capacity*2);
		_str[_size] = ch;
		_str[++_size] = '\0';
	}
	void PushBack(const char* str);
	//删
	void PopBack();
	void Erase(size_t pos, size_t n = 1);

	size_t Find(char ch);
	size_t Find(const char* str); // ? 

	String operator+(char ch);// s1 + 'a' 
	String& operator+=(char ch);
	String operator+(const char* str);
	String& operator+=(const char* str);

	bool operator>(const String& s);
	bool operator>=(const String& s);
	bool operator<(const String& s);
	bool operator<=(const String& s);
	bool operator==(const String& s);
	bool operator!=(const String& s);

private:
	char* _str;
	size_t _size;
	size_t _capacity;
};

void TestString()
{
	String s1("I am BEST");
	String s2(s1);
	String s3;
	s3 = s2;
	s3[0] = 'T';
	s3.Swap(s2);
	
}
int main()
{
	TestString();
	system("pause");
	return 0;
}
