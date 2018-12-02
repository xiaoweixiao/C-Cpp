//��ͷ˫��ѭ������(������)
//��ͷ(ͷ��㲻�洢���ݣ�
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
	void SetEmpty()//�ͷ�����ֻ����ͷ���
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
	~List()//�����������ͷ�������Դ
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

	//���ӽ��
	void PushBack(const T&x)
	{
		Insert(_head->_prev,x);
	}
	void PushFront(const T&x)
	{
		Insert(_head, x);
	}
	//ɾ�����
	void Erase(Node<T>*pos)//ɾ����posλ�ý��
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
	//������
	void Insert(Node<T>*pos, const T& x)//������posλ�ú��������x
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
	//��
	Node<T>* Find(const T&x)//�������͵�����x��ȥ����������x�Ľ�㣬�Ҳ���������NULL
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
	//��
	void Chang(Node<T>*pos, const T&x)//��pos���λ�õ����ݸ�����x
	{
		pos->_data = x;
	}
	//��ӡ
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
	//�ýӿ��������ṩ�����ͷ
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
	l1.PushBack("��");
	l1.PushFront("��");
	l1.PushBack("��");
	l1.PushBack("��");
	l1.Print();

	l1.Chang(l1.Head()->_next , "��");
	l1.Print();
	l1.PopBack();
	l1.Print();
	l1.PopFront();
	l1.Print();
	cout << "�ҵ���:"<<l1.Find("��") << "->"<<l1.Find("��")->_data << endl;

	List<string>l2(l1);
	List<string>l3;
	l3 = l1;
	l2.Print();
	l3.Print();

}
