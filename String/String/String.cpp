// 1.�ִ�д�� 
// 2.��ͳд�� 
// 3.�ַ�����ɾ��� 
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<assert.h>
#include<string.h>
using namespace std;
class String
{
public:
	String(const char* str = "")//���캯��
		:_str(new char[strlen(str) + 1])
		,_capacity ( strlen(str) + 1)
		, _size(strlen(str)+1)
	{
		strcpy(_str,str);
	}
	~String()//����
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

	//����
	void Swap(String& s)// s1.Swap(s2); 
	{
		swap(_str, s._str);
		swap(_capacity, s._capacity);
		swap(_size, s._size);
	}
	//��C�ַ���ʽ���
	const char* c_str()
	{
		return _str;
	}
	//��
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
	void Insert(size_t pos, char ch)//�±�Ϊpos��λ�ã������ַ�ch
	{
		if (_size == _capacity)
			Expand(_capacity*2);
		//��posλ��֮��������ɺ���ǰ�������Ųһλ
		size_t i = _size;
		while (i >pos)
		{
			_str[i] = _str[i - 1];
		}

		_str[pos] = ch;
		_size++;
	}
	void Insert(size_t pos, const char* str)//�±�Ϊpos��λ�ã�����String str
	{
		if (_size + strlen(str) >= _capacity)
			Expand(_size + strlen(str) + 1);
		//��posλ��֮��������ɺ���ǰ�������Ųstrlen(str)λ
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
	//ɾ
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
