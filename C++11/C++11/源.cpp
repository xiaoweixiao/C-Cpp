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
//	Person p{ "张威", 20 };
//	vector<int> vec{ 1, 2, 3, 4, 5 };
//	map<string, string> dict{ { "insert", "插入" }, { "left", "左边" } };
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

//int main()
//{
//	const int x = 10;
//	const int y = 1024;
//	char c1{ x }; // 可以通过编译
//	//char c2{ y }; // 无法通过编译，y的高字节丢失
//	return 0;
//}

//
//#include <map>
//#include <string>
//#include<iostream>
//using namespace std;
//
//int main()
//{
//	short a = 32670;
//	short b = 32670;
//	// c如果给成short，会造成数据丢失，如果能够让编译器根据a+b的结果推导c的实际类型，就不会存在问题
//	auto c = a + b;
//	std::map<std::string, std::string> m{ { "apple", "苹果" }, { "banana", "香蕉" } };
//	// 使用迭代器遍历容器, 迭代器类型太繁琐
//	auto it = m.begin();
//	while (it != m.end())
//	{
//		cout << it->first << " " << it->second << endl;
//		++it;
//	}
//	return 0;
//}



//int main()
//{
//	vector<int> ret{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
//	for (size_t i = 0; i < ret.size(); i++)
//		cout << ret[i] << endl;
//	system("pause");
//	return 0;
//}

//#include<iostream>
//#include<vector>
//using namespace std;
//
//int main()
//{
//	int i = 42, *p = &i, &r = i;
//	decltype(r) y1 = i;       //因为 r 为 int& ,所以 y1 为int&
//	auto y2 = r;              //因为 r 为 int& ,但auto会忽略引用，所以 y2 为int
//	y1++;
//	cout << r << i << y2 << endl;
//
//	decltype(*p) h1 = i;      //这里 h1 是int&， 原因后面讲
//	auto h2 = *p;             // h2 为 int.
//	system("pause");
//}


//void* GetMemory(size_t size)
//{
//	return malloc(size);
//}
//int main()
//{
//	// 如果没有带参数，推导函数的类型
//	cout << typeid(decltype(GetMemory)).name() << endl;
//	// 如果带参数列表，推导的是函数返回值的类型,注意：此处只是推演，不会执行函数
//	cout << typeid(decltype(GetMemory(0))).name() << endl;
//	system("pause");
//	return 0;
//}


//int main()
//{
//	int a = 10;
//	int b = 20;
//	// 用decltype推演a+b的实际类型，作为定义c的类型
//	decltype(a + b) c;
//	cout << typeid(c).name() << endl;
//	system("pause");
//	return 0;
//}

//class A
//{
//public:
//	A(int a)
//		: _a(a)
//	{}
//	// 禁止编译器生成默认的拷贝构造函数以及赋值运算符重载
//	A(const A&) = delete;
//	A& operator=(const A&) = delete;
//private:
//	int _a;
//};
//int main()
//{
//	A a1(10);
//	//A a2(a1);编译失败，因为该类没有拷贝构造函数
//	A a3(20);
//	//a3 = a2;编译失败，因为该类没有赋值运算符重载
//	return 0;
//}


//class Info
//{
//public:
//	// 目标构造函数
//	Info()
//		: _type(0)
//		, _a('a')
//	{
//		InitRSet();
//	}
//	// 委派构造函数
//	Info(int type)
//		: Info()
//	{
//		_type = type;
//	}
//	// 委派构造函数
//	Info(char a)
//		: Info()
//	{
//		_a = a;
//	}
//private:
//	void InitRSet()
//	{
//		//初始化其他变量
//	}
//private:
//	int _type{ 0 };
//	char _a{ 'a' };
//	//...
//};

//struct A1
//{
//	virtual void func1(int) {}
//};
//
//struct B1 : A1
//{
//	virtual void func1(int) override {} // OK
//};