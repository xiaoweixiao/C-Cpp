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
//	Person p{ "����", 20 };
//	vector<int> vec{ 1, 2, 3, 4, 5 };
//	map<string, string> dict{ { "insert", "����" }, { "left", "���" } };
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
//	char c1{ x }; // ����ͨ������
//	//char c2{ y }; // �޷�ͨ�����룬y�ĸ��ֽڶ�ʧ
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
//	// c�������short����������ݶ�ʧ������ܹ��ñ���������a+b�Ľ���Ƶ�c��ʵ�����ͣ��Ͳ����������
//	auto c = a + b;
//	std::map<std::string, std::string> m{ { "apple", "ƻ��" }, { "banana", "�㽶" } };
//	// ʹ�õ�������������, ����������̫����
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
//	decltype(r) y1 = i;       //��Ϊ r Ϊ int& ,���� y1 Ϊint&
//	auto y2 = r;              //��Ϊ r Ϊ int& ,��auto��������ã����� y2 Ϊint
//	y1++;
//	cout << r << i << y2 << endl;
//
//	decltype(*p) h1 = i;      //���� h1 ��int&�� ԭ����潲
//	auto h2 = *p;             // h2 Ϊ int.
//	system("pause");
//}


//void* GetMemory(size_t size)
//{
//	return malloc(size);
//}
//int main()
//{
//	// ���û�д��������Ƶ�����������
//	cout << typeid(decltype(GetMemory)).name() << endl;
//	// ����������б��Ƶ����Ǻ�������ֵ������,ע�⣺�˴�ֻ�����ݣ�����ִ�к���
//	cout << typeid(decltype(GetMemory(0))).name() << endl;
//	system("pause");
//	return 0;
//}


//int main()
//{
//	int a = 10;
//	int b = 20;
//	// ��decltype����a+b��ʵ�����ͣ���Ϊ����c������
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
//	// ��ֹ����������Ĭ�ϵĿ������캯���Լ���ֵ���������
//	A(const A&) = delete;
//	A& operator=(const A&) = delete;
//private:
//	int _a;
//};
//int main()
//{
//	A a1(10);
//	//A a2(a1);����ʧ�ܣ���Ϊ����û�п������캯��
//	A a3(20);
//	//a3 = a2;����ʧ�ܣ���Ϊ����û�и�ֵ���������
//	return 0;
//}


//class Info
//{
//public:
//	// Ŀ�깹�캯��
//	Info()
//		: _type(0)
//		, _a('a')
//	{
//		InitRSet();
//	}
//	// ί�ɹ��캯��
//	Info(int type)
//		: Info()
//	{
//		_type = type;
//	}
//	// ί�ɹ��캯��
//	Info(char a)
//		: Info()
//	{
//		_a = a;
//	}
//private:
//	void InitRSet()
//	{
//		//��ʼ����������
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