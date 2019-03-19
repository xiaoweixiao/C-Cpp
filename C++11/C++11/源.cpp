//#include<iostream>
//#include<string>
//using namespace std;
//class Person{
//public:
//	Person(string name,int age)
//		:name_(name)
//		, age_(age)
//	{
//	}
//private:
//	string name_;
//	int age_;
//};
//
//int main()
//{
//	Person p{ "ÕÅÍþ", 20 };
//	return 0;
//}
#include<iostream>
#include <initializer_list>
template<class T>
class SeqList
{
public:
	// ...
	SeqList(const initializer_list<T> l)
		: _capacity(l.size())
		, _size(0)
	{
		_array = new T[_capacity];
		for (auto e : l)
			_array[_size++] = e;
	}
	SeqList<T>& operator=(const initializer_list<T> l)
	{
		size_t i = 0;
		for (auto e : l)
			_array[i++] = e;
		return *this;
	}
	// ...
private:
	T* _array;
	size_t _capacity;
	size_t _size;
};
int main()
{
	SeqList<int> s{ 1, 2, 4 };
}