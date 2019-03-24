//2.实现一个通讯录；
//通讯录可以用来存储1000个人的信息，每个人的信息包括：
//姓名、性别、年龄、电话、住址
//
//提供方法：
//1.	添加联系人信息
//2.	删除指定联系人信息
//3.	查找指定联系人信息
//4.	修改指定联系人信息
//5.	显示所有联系人信息
//6.	清空所有联系人
#include<iostream>
#include<vector>

using namespace std;


struct node
{
	friend class  Phone;
private:
	char* _name;
	short _sex = -1;//0、保密	1、男	2、女	
	short _age;
	char* _phone_num;
	char* _addr;
public:
	node()//添加联系人
	{
		cout << "请输入联系人姓名：";
		cin >>_name;

		while (!(_sex <= 2 &&_sex >= 0))
		{
			char* sex=nullptr;
			cout << "请输入联系人性别(男、女或者保密)：";
			cin >> sex;
			if (strcmp(sex, "男") == 0)_sex = 1;
			else if (strcmp(sex, "女") == 0)_sex = 2;
			else if (strcmp(sex, "保密") == 0)_sex = 0;
			else
				cout << "输入错误,";
		}

		cout << "请联系人输入年龄：";
		cin >> _age;

		cout << "请输入联系人电话";
		cin >> _phone_num;

		cout << "请输入联系人地址" << endl;
		cin >>_addr;
	}
public:
	void Print() const
	{
		cout << "姓名：" << _name << endl;
		switch (_sex)
		{
		case 0:
			cout <<"性别"<< "保密" << endl;
			break;
		case 1:
			cout << "性别" << "男" << endl;
			break;
		case 2:
			cout << "性别" << "女" << endl;
			break;
		default:
			break;
		}
		cout << "年龄：" << _age << endl;
		cout << "电话：" << _phone_num << endl;
		cout << "地址：" << _addr << endl;
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

	void Add()//增
	{
		if (_size == _capacity)
		{
			//Exand();
		}
		node* man = new node();

		_phone[_size] = man;
		_size++;
	}
	//查
	vector<int> Find() const
	{
		vector<int> ret;
		int i = 0;//标记数组下标
		int in = -1;
		cout << "1、姓名查找			2、手机号查找			3、家庭住址查找			4、年龄查找" << endl;
		cout << "请输入选择";
		cin >> in;
		switch (in)
		{
		case 1:
		{
				  char* name = nullptr;
				  cout << "请输入姓名：";
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
				  cout << "请输入手机号：";
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
				  cout << "请输入家庭住址：";
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
				cout << "请输入年龄：";
				cin >> age_;
				for (i = 0; i < _size; i++)
				{
					if (age_ == _phone[i]->_age)
						ret.push_back(i);
				}
				break;
			}
		default:
			cout << "输入错误" << endl;
			break;
		}
		return ret;
	}
	//删
	void Erase()
	{
		bool sure;
		cout << "你删除联系，要查找联系人：" << endl;
		vector<int> man_ = Find();
		
		
		for (size_t i = 0; i < man_.size(); i++)
		{
			cout << i<<"、";
			_phone[man_[i]]->Print();
		}

		int size_;
		cout << "请输入要删除的联系人编号：";
		cin >> size_;
		_phone[man_[size_]]->Print();

		cout << "确认要删除该联系人信息吗？" << endl << "1、确认删除		0、退出系统" << endl;
		cin >> sure;

		if (sure)
		{
			for (int i = man_[size_]; i < _size - 1; i++)
			{
				_phone[i] = _phone[i + 1];
				_size--;
			}

			cout << "删除成功" << endl;
		}
		else
			return;
	}

	//改
	void Change()
	{
		int sure = -1;
flag:
		cout << "你要修改联系人，需要先找到联系人：" << endl;
		vector<int> man_ = Find();

		for (size_t i = 0; i < man_.size(); i++)
		{
			cout << i << "、";
			_phone[man_[i]]->Print();
		}


		int size_;
		cout << "请输入要删除的联系人编号：";
		cin >> size_;
		_phone[man_[size_]]->Print();

		cout << "你确认要修改这个联系人的信息吗？" << endl << "0、重新查找			1、确认联系人		2、退出系统" << endl;
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

	//显示所有联系人信息
	void DisplayAllPhone()
	{
		for (int i = 0; i < _size; i++)
			_phone[i]->Print();
	}

	//清空通讯录
	void EmptyPhone()
	{
		_size = _capacity = 0;
		_phone = nullptr;
	}
};


