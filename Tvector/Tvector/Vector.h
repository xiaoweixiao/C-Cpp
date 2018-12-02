#include<iostream>
#include<assert.h>
#include<string>
using namespace std;

template<class T>

class Vector{
public:
	//类内定义构造函数
	/*Vector()
		:_Array(NULL)
		, _size(0)
		, _capacity(0)
	{}*/
	
	Vector();//类外定义构造函数，类内声明
	~Vector()
	{
		if (_Array)
		{
			delete[] _Array;
			_size = _capacity = 0;
		}
	}
	Vector(const Vector<T>&t)
	{
		if (t._size != 0)
		{
			_Array = new T[t._size];
			memcpy(_Array, t._Array, sizeof(T)*t._size);
			_capacity = _size = t._size;
		}
		else
		{
			_Array = NULL;
			_capacity = _size = 0;
		}
	}
	/*Vector<T>& operator=(const Vector<T>&v)
	{
		if (this != &v)
		{
			delete[] _Array;
			if (v._size != 0)
			{
				_Array = new T[v._size];
				memcpy(_Array, t._Array, sizeof(T)*t._size);
				_size = _capacity = t._size;
			}
			else
			{
				_size = 0;
			}
		}
		return *this;
	}*/
	
	Vector&operator=(Vector<T> v)//现代写法的赋值操作运算符
	{
		if (v._size!=0)
		{
			swap(_Array, v._Array);
			swap(_capacity, v._capacity);
			swap(_size, v._size);
		}
		else
		{
			_size = 0;
		}
		return *this;
	}
	T& operator[](size_t pos)//const对象不可调用，[]意味着可读可写
	{
		return _Array[pos];
	}

	const T& operator[](size_t pos) const//const类型的对象可调用
	{
		return _Array[pos];
	}
	void PushBack(const T& x)
	{
		Insert(_size,x);
	}
	void PopBack()
	{
		Erase(_size - 1);
	}
	void Insert(size_t pos, const T& x)
	{
		assert(pos <= _size);
		//是否需要增容
		if (_size == _capacity)
		{
			size_t newcapacity = _capacity == 0 ? 3 : _capacity * 2;
			T*newArray = new T[newcapacity];
			for (size_t i = 0; i < _size; i++)
				newArray[i] = _Array[i];

			delete[] _Array;
			_Array = newArray;
			_capacity = newcapacity;
		}
		//pos位置以后的节点从后到前后挪一位
		size_t end = _size;
		while (pos < end)
		{
			_Array[end] = _Array[end - 1];
			end--;
		}
		_Array[pos] = x;
		_size++;
	}
	void Erase(size_t pos)//删除pos位置
	{
		assert(pos <= _size);
		size_t cur = pos;
		while (cur < _size-1)
		{
			_Array[cur] = _Array[cur + 1];
			cur++;
		}
		_size--;
	}
	
	size_t Find(const T& x)
	{
		size_t i = 0;
		for (i = 0; i < Size(); i++)
		{
			if (x == _Array[i])
			{
				cout << "找到了" << endl;
				return i;
			}

		}
		cout << "没找到" << endl;
		return -1;
	}
	size_t Size()
	{
		return _size;
	}
	void Print()
	{
		size_t i = 0;
		while (i < _size)
		{
			cout << _Array[i] << "	";
			i++;
		}
		cout << endl;
	}
private:
	T* _Array;
	size_t _size;
	size_t _capacity;
};

//类外定义构造函数
template<class T>
Vector<T>::Vector()
	:_Array(NULL)
	, _size(0)
	, _capacity(0)
{}

void Test1()
{
	Vector<string> s2;
	s2.PushBack("aaaaaaaaaaaaaaaaaaa");
	s2.PushBack("bbb");
	s2.PushBack("ccc");
	s2.PushBack("ddd");
	s2.Print();

	Vector<int> v1;
	//Vector<int>类型
	//Vector类名
	v1.PushBack(1);
	v1.PushBack(2);
	v1.PushBack(3);
	v1.PushBack(4);
	Vector<int>v2(v1);
	v2[v2.Find(3)] = 8;
	v2.Print();
	Vector<int>v3;
	v3 = v2;
	v3.PopBack();
	v3.Print();
}