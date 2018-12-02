//带头双向循环链表(无死角)
//带头(头结点不存储数据）
#include<iostream>
#include<string>
using namespace std;

template<class T>
struct Node{
	T _data;
	Node* _next;
	Node* _prev;
};
template<class T>
class List{
public:
	List()
	{
		_head = new Node<T>;
		_head->_next = _head;
		_head->_prev = _head;
	}
	void SetEmpty()//释放链表，只留下头结点
	{
		if (_head)
		{
			Node<T>*cur = _head->_next;
			while (cur != _head)
			{
				Node<T>*next = cur->_next;
				delete cur;
				cur = next;
			}
			_head->_next = _head;
			_head->_prev = _head;
		}
	}
	~List()//析构函数，释放所有资源
	{
		SetEmpty();
		delete _head;
	}
	List(const List&l)
	{
		_head = new Node<T>;
		_head->_next = _head;
		_head->_prev = _head;
		Node<T>*cur = l._head->_next;
		while (cur != l._head)
		{
			PushBack(cur->_data);
			cur = cur->_next;
		}
	}
	
	List<T>& operator=(List<T> l)
	{
		SetEmpty();
		Node<T>*cur = l._head->_next;
		while (cur != l._head)
		{
			PushBack(cur->_data);
			cur = cur->_next;
		}
		return *this;
	}

	//增加结点
	void PushBack(const T&x)
	{
		Insert(_head->_prev,x);
	}
	void PushFront(const T&x)
	{
		Insert(_head, x);
	}
	//删除结点
	void Erase(Node<T>*pos)//删除掉pos位置结点
	{
		Node<T>*next = pos->_next;
		Node<T>*prev = pos->_prev;
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
	//插入结点
	void Insert(Node<T>*pos, const T& x)//任意结点pos位置后插入数据x
	{
		Node<T>*node = new Node<T>;
		node->_data = x;
		//pos  node   next
		Node<T>*next = pos->_next;

		pos->_next = node;
		node->_prev = pos;
		node->_next = next;
		next->_prev = node;
	}
	//查
	Node<T>* Find(const T&x)//任意类型的数据x，去查找数据是x的结点，找不到，返回NULL
	{
		Node<T>*cur = _head->_next;
		while (cur != _head)
		{
			if (x == cur->_data)
				return cur;
			cur = cur->_next;
		}
		return NULL;
	}
	//改
	void Chang(Node<T>*pos, const T&x)//把pos结点位置的数据更换成x
	{
		pos->_data = x;
	}
	//打印
	void Print()
	{
		Node<T>*cur = _head->_next;
		while (cur != _head)
		{
			cout << cur->_data;
			cur = cur->_next;
		}
		cout << endl;
	}
	//该接口向类外提供链表表头
	Node<T>* Head()
	{
		return _head;
	}
private:
	Node<T>* _head;
};
void TestList()
{
	List<string>l1;
	l1.PushBack("是");
	l1.PushFront("我");
	l1.PushBack("大");
	l1.PushBack("佬");
	l1.Print();

	l1.Chang(l1.Head()->_next , "你");
	l1.Print();
	l1.PopBack();
	l1.Print();
	l1.PopFront();
	l1.Print();
	cout << "找到了:"<<l1.Find("大") << "->"<<l1.Find("大")->_data << endl;

	List<string>l2(l1);
	List<string>l3;
	l3 = l1;
	l2.Print();
	l3.Print();

}
