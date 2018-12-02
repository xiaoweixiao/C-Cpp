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
	//��ӡ˳���
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
	//��
	void Insert(size_t pos, DataType x)//���±�Ϊpos��λ�ã���������x
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
	//ɾ
	void Erase(size_t n)//ɾ���±�Ϊn������
	{
		//assert(n > 0 && n < (size_t)_finish);
		if (_first+n<=_first||_first+n>_finish)//ɾ���Ƿ��±�ʱ�����쳣
			throw  "ɾ���˷Ƿ��±�";
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
	//��ѯ
	size_t Find(DataType x)//��������Ϊx����ֵ���±�
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
	void Reverse(size_t n)//����˳������������ݳ��Ȳ���
	{
		if (_first + n >= _finish)//�µ�������С���벻С��ԭ�����ݳ��ȣ�������ܶ�ʧ����
		{
			Resize(n, Size());
		}
		else
		{
			return;
		}
	}
	void Resize(size_t n, DataType value)//����˳������ݳ���(�������÷�Χ��Ľضϣ�����)������
	{
		//���ռ�
		DataType* new_first = new DataType[n];
		DataType*new_endof = new_first + n;
		DataType* new_finish = new_first;

		//��������
		DataType*cur = _first;
		while (cur < _finish&&cur<_first+value)
		{
			*new_finish = *cur;
			cur++;
			new_finish++;
		}

		//�ͷžɿռ�
		delete[] _first;
		_first = _endof = NULL;

		_first = new_first;
		_finish = new_finish;
		_endof = new_endof;
	}
private:
	void Expand(size_t n)//����
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
	cout << "�ҵ�˳���v2�е�����3�������±��ǣ�"<<v2.Find(3) << endl;
}