//2.ʵ��һ��ͨѶ¼��
//ͨѶ¼���������洢1000���˵���Ϣ��ÿ���˵���Ϣ������
//�������Ա����䡢�绰��סַ
//
//�ṩ������
//1.	�����ϵ����Ϣ
//2.	ɾ��ָ����ϵ����Ϣ
//3.	����ָ����ϵ����Ϣ
//4.	�޸�ָ����ϵ����Ϣ
//5.	��ʾ������ϵ����Ϣ
//6.	���������ϵ��
#include<iostream>
#include<vector>

using namespace std;


struct node
{
	friend class  Phone;
private:
	char* _name;
	short _sex = -1;//0������	1����	2��Ů	
	short _age;
	char* _phone_num;
	char* _addr;
public:
	node()//�����ϵ��
	{
		cout << "��������ϵ��������";
		cin >>_name;

		while (!(_sex <= 2 &&_sex >= 0))
		{
			char* sex=nullptr;
			cout << "��������ϵ���Ա�(�С�Ů���߱���)��";
			cin >> sex;
			if (strcmp(sex, "��") == 0)_sex = 1;
			else if (strcmp(sex, "Ů") == 0)_sex = 2;
			else if (strcmp(sex, "����") == 0)_sex = 0;
			else
				cout << "�������,";
		}

		cout << "����ϵ���������䣺";
		cin >> _age;

		cout << "��������ϵ�˵绰";
		cin >> _phone_num;

		cout << "��������ϵ�˵�ַ" << endl;
		cin >>_addr;
	}
public:
	void Print() const
	{
		cout << "������" << _name << endl;
		switch (_sex)
		{
		case 0:
			cout <<"�Ա�"<< "����" << endl;
			break;
		case 1:
			cout << "�Ա�" << "��" << endl;
			break;
		case 2:
			cout << "�Ա�" << "Ů" << endl;
			break;
		default:
			break;
		}
		cout << "���䣺" << _age << endl;
		cout << "�绰��" << _phone_num << endl;
		cout << "��ַ��" << _addr << endl;
	}
};

class Phone
{
private:
	node** _phone;
	int _size;
	int _capacity;
public:
	node** GetPhone() const
	{
		return _phone;
	}
	Phone()
		:_phone(nullptr)
		, _size(0)
		, _capacity(1000)
	{}

	void Add()//��
	{
		if (_size == _capacity)
		{
			//Exand();
		}
		node* man = new node();

		_phone[_size] = man;
		_size++;
	}
	//��
	vector<int> Find() const
	{
		vector<int> ret;
		int i = 0;//��������±�
		int in = -1;
		cout << "1����������			2���ֻ��Ų���			3����ͥסַ����			4���������" << endl;
		cout << "������ѡ��";
		cin >> in;
		switch (in)
		{
		case 1:
		{
				  char* name = nullptr;
				  cout << "������������";
				  cin >> name;
				  for (i = 0; i < _size; i++)
				  {
					  if (strcmp(name, _phone[i]->_name) == 0)
						  ret.push_back(i);
				  }
				  break;
		}
		case 2:
		{
				  char* Num_ = nullptr;
				  cout << "�������ֻ��ţ�";
				  cin >> Num_;
				  for (i = 0; i < _size; i++)
				  {
					  if (strcmp(Num_, _phone[i]->_phone_num) == 0)
						  ret.push_back(i);
				  }
				  break;
		}
		case 3:
		{
				  char* addr_ = nullptr;
				  cout << "�������ͥסַ��";
				  cin >> addr_;
				  for (i = 0; i < _size; i++)
				  {
					  if (strcmp(addr_, _phone[i]->_addr) == 0)
						  ret.push_back(i);
				  }
				  break;
		}
		case 4:
			{
				short age_;
				cout << "���������䣺";
				cin >> age_;
				for (i = 0; i < _size; i++)
				{
					if (age_ == _phone[i]->_age)
						ret.push_back(i);
				}
				break;
			}
		default:
			cout << "�������" << endl;
			break;
		}
		return ret;
	}
	//ɾ
	void Erase()
	{
		bool sure;
		cout << "��ɾ����ϵ��Ҫ������ϵ�ˣ�" << endl;
		vector<int> man_ = Find();
		
		
		for (size_t i = 0; i < man_.size(); i++)
		{
			cout << i<<"��";
			_phone[man_[i]]->Print();
		}

		int size_;
		cout << "������Ҫɾ������ϵ�˱�ţ�";
		cin >> size_;
		_phone[man_[size_]]->Print();

		cout << "ȷ��Ҫɾ������ϵ����Ϣ��" << endl << "1��ȷ��ɾ��		0���˳�ϵͳ" << endl;
		cin >> sure;

		if (sure)
		{
			for (int i = man_[size_]; i < _size - 1; i++)
			{
				_phone[i] = _phone[i + 1];
				_size--;
			}

			cout << "ɾ���ɹ�" << endl;
		}
		else
			return;
	}

	//��
	void Change()
	{
		int sure = -1;
flag:
		cout << "��Ҫ�޸���ϵ�ˣ���Ҫ���ҵ���ϵ�ˣ�" << endl;
		vector<int> man_ = Find();

		for (size_t i = 0; i < man_.size(); i++)
		{
			cout << i << "��";
			_phone[man_[i]]->Print();
		}


		int size_;
		cout << "������Ҫɾ������ϵ�˱�ţ�";
		cin >> size_;
		_phone[man_[size_]]->Print();

		cout << "��ȷ��Ҫ�޸������ϵ�˵���Ϣ��" << endl << "0�����²���			1��ȷ����ϵ��		2���˳�ϵͳ" << endl;
		cin >> sure;

		if (sure == 1)
		{
			node*p = new node();

			_phone[man_[size_]] = p;
		}
		else if (sure == 0)
			goto flag;
		else
			return ;
	}

	//��ʾ������ϵ����Ϣ
	void DisplayAllPhone()
	{
		for (int i = 0; i < _size; i++)
			_phone[i]->Print();
	}

	//���ͨѶ¼
	void EmptyPhone()
	{
		_size = _capacity = 0;
		_phone = nullptr;
	}
};


