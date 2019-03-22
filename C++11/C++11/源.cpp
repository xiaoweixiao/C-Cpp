//#include<iostream>
//#include<string>
//#include<vector>
//#include<map>
//#include<set>
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
//	vector<int> vec{ 1, 2, 3, 4, 5 };
//	map<string, string> dict{ { "insert", "²åÈë" }, { "left", "×ó±ß" } };
//	set<int> se{ 5, 6, 7, 3, 8 };
//	return 0;
//}


//#include <initializer_list>
//#include<iostream>
//using namespace std;
//template<class T>
//class Vector
//{
//public:
//	// ...
//	Vector(initializer_list<T> l)
//		: _capacity(l.size())
//		, _size(0)
//	{
//		_array = new T[_capacity];
//		for (auto e : l)
//			_array[_size++] = e;
//	}
//	Vector<T>& operator=(initializer_list<T> l)
//	{
//		size_t i = 0;
//		for (auto e : l)
//			_array[i++] = e;
//		return *this;
//	}
//	// ...
//private:
//	T* _array;
//	size_t _capacity;
//	size_t _size;
//};
//int main()
//{
//	Vector<int> v{ 1, 2, 3, 4 };
//}

#include<iostream>
#include<