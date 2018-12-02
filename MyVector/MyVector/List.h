#include<iostream>
using namespace std;
typedef int DataType;
struct Node{
	DataType _value;
	Node* _next;
	Node* _prev;
};
class List{
public:
	List()
	{
		_head = new Node(Node());//构造函数开辟头结点，头结点给个匿名对象
		_head->_next = _head;
		_head->_prev = _head;
	}
	~List()
	{
		SetEmpty();
		delete _head;
	}
	List(const List&l)
	{
		_head = new Node(Node());//构造函数开辟头结点，头结点给个匿名对象
		_head->_next = _head;
		_head->_prev = _head;

		Node*cur = l._head->_next;
		while (cur != l._head)
		{
			PushBack(cur->_value);
			cur = cur->_next;
		}
	}
	void SetEmpty()//将链表置空
	{
		if (_head)
		{
			Node* cur = _head->_prev;
			while (cur != _head)
			{
				Node*prev = cur->_prev;
				delete cur;
				cur = prev;
			}
		}
		_head->_next = _head;
		_head->_prev = _head;
	}
	List& operator=(List& l)
	{
		SetEmpty();
		Node*cur = l._head->_next;
		while (cur != l._head)
		{
			PushBack(cur->_value);
			cur = cur->_next;
		}
	}

	//增
	void Insert(Node* pos, DataType x)//在pos位置后添加数据x结点
	{
		Node*next = pos->_next;
		Node*node = new Node(Node());
		node->_value = x;

		pos->_next = node;
		node->_prev = pos;
		node->_next = next;
		next->_prev = node;
	}
	void PushBack(DataType x)
	{
		Insert(_head->_prev, x);
	}
	void PushFront(DataType x)
	{
		Insert(_head, x);
	}

	//删
	void Erase(Node*pos)//删除pos结点
	{
		Node*prev = pos->_prev;
		Node*next = pos->_next;

		delete pos;
		prev->_next = next;
		next->_prev = prev;
	}
	void PopBack()
	{
		Erase(_head->_prev);
	}
	void PopFront()
	{
		Erase(_head->_next);
	}
	

	//查找
	Node* Find(DataType x)
	{
		Node*cur = _head->_next;
		while (cur != _head)
		{
			if (cur->_value == x)
				return cur;
			cur = cur->_next;
		}
		return NULL;
	}
	//改
	void Change(Node*pos, DataType x)//把pos结点数据更换成x
	{
		pos->_value = x;
	}
	void Print()
	{
		Node*cur = _head->_next;
		while (cur != _head)
		{
			cout << cur->_value << "	";
			cur = cur->_next;
		}
		cout << endl;
	}
private:
	Node* _head;
};

void TestL()
{
	List l1;
	l1.PushBack(2);
	l1.PushFront(1);
	l1.PushBack(3);
	l1.PushBack(4);
	l1.Print();
	List l2(l1);
	l2.PopBack();
	l2.Print();
	List l3 = l2;
	l3.PopFront();
	l3.Print();
	l3.Change(l3.Find(2), 8);
	l3.Print();
}