#include<assert.h>
#include<iostream>
using namespace std;

typedef int DataType;

class Vector{
public:
	Vector()
		:_first(NULL)
		,_finish(NULL)
		,_endof(NULL)
	{
	}
	~Vector()
	{
		if (_first)
		{
			delete[] _first;
			_first = _finish = _endof = NULL;
		}
	}
	Vector(const Vector& v)
	{
		_first = new DataType[v.Size()];
		_finish = _first + v.Size();
		_endof = _first + v.Size();

		memcpy(_first, v._first, sizeof(DataType)*v.Size());
	}
	size_t Size() const
	{
		return _finish - _first;
	}
	size_t Capacity() const
	{
		return _endof - _first;
	}
	//打印顺序表
	void Print()
	{
		DataType* cur = _first;
		while (cur != _finish)
		{
			cout << *cur << "	";
			cur++;
		}
		cout << endl;
	}
	void CheckCapacity()
	{
		if (_finish == _endof)
		{
			size_t capacity = Capacity();
			capacity>0 ? Expand(capacity * 2) : Expand(3);
		}
	}
	//增
	void Insert(size_t pos, DataType x)//在下标为pos的位置，插入数据x
	{
		CheckCapacity();
		DataType*cur = _finish;
		while (cur >_first + pos )
		{
			*cur = *(cur - 1);
			cur--;
		}
		*(_first + pos) = x;
		_finish++;
	}
	void PushBack(DataType x)
	{
		CheckCapacity();
		*_finish = x;
		++_finish;
	}
	//删
	void Erase(size_t n)//删除下标为n的数据
	{
		//assert(n > 0 && n < (size_t)_finish);
		if (_first+n<=_first||_first+n>_finish)//删除非法下标时候，抛异常
			throw  "删除了非法下标";
		DataType*cur = _first + n;
		while (cur < _finish)
		{
			*cur = *(cur + 1);
			cur++;
		}
		_finish--;
	}
	void PopBack()
	{
		if (_finish < _endof)
		{
			_finish--;
		}
	}
	//查询
	size_t Find(DataType x)//查找数据为x的数值的下标
	{
		size_t n = 0;
		while (_first+n < _finish)
		{
			if (*(_first + n) == x)
				return n;
			n++;
		}
		return -1;
	}
public:
	void Reverse(size_t n)//设置顺序表容量，数据长度不变
	{
		if (_first + n >= _finish)//新的容量大小必须不小于原来数据长度，否则可能丢失数据
		{
			Resize(n, Size());
		}
		else
		{
			return;
		}
	}
	void Resize(size_t n, DataType value)//设置顺序表数据长度(超出设置范围外的截断，丢弃)、容量
	{
		//开空间
		DataType* new_first = new DataType[n];
		DataType*new_endof = new_first + n;
		DataType* new_finish = new_first;

		//拷贝数据
		DataType*cur = _first;
		while (cur < _finish&&cur<_first+value)
		{
			*new_finish = *cur;
			cur++;
			new_finish++;
		}

		//释放旧空间
		delete[] _first;
		_first = _endof = NULL;

		_first = new_first;
		_finish = new_finish;
		_endof = new_endof;
	}
private:
	void Expand(size_t n)//扩容
	{
		if (n > Capacity())
		{
			Reverse(n);
		}
	}
private:
	DataType* _first;
	DataType* _finish;
	DataType* _endof;

};


void TestV()
{
	Vector v1;
	v1.PushBack(1);
	v1.PushBack(2);
	v1.PushBack(3);
	v1.PushBack(4);
	v1.Print();
	v1.Resize(8, 2);
	cout << "v1.Size():" << v1.Size() << endl;
	cout << "v1.Capacity():" << v1.Capacity() << endl;
	v1.Reverse(3);
	cout << "v1.Size():" << v1.Size() << endl;
	cout << "v1.Capacity():" << v1.Capacity() << endl;


	Vector v2(v1);
	v2.Print();
	try{
		v2.Erase(8);
	}
	catch (const char* msg)
	{
		cout << msg << endl;
	}
	v2.Print();
	v2.Insert(2, 3);
	v2.Insert(3, 4);
	v2.Print();
	cout << "找到顺序表v2中的数据3，它的下标是："<<v2.Find(3) << endl;
}