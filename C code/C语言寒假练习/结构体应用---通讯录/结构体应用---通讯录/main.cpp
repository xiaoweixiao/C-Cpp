#include"phone.h"

void Menu()
{
	cout << "----------------------------------------------------------------------------------" << endl;
	cout << "0、退出系统							 1、添加联系人信息					    	" << endl;
	cout << "2、删除指定联系人信息					 3、查找联系人			" << endl;
	cout << "4、修改联系人							 5、显示通讯录所有联系人信息		" << endl;
	cout << "6、清空通讯录												" << endl;
	cout << "----------------------------------------------------------------------------------" << endl;
}
void Test()
{
	int choose = -1;
	Menu();
	Phone p;
	cin >> choose;
	switch (choose)
	{
	case 0:
		break;
	case 1:
		p.Add();
		break;
	case 2:
		p.Erase();
		break;
	case 3:	
	{
			  node** phone = p.GetPhone();
			  vector<int> fd = p.Find();

			  for (size_t i = 0; i < fd.size(); i++)
			  {
				  phone[fd[i]]->Print();
			  }
			  break;
	}
	case 4:
		p.Change();
		break;
	case 5:
		p.DisplayAllPhone();
		break;
	case 6:
		p.EmptyPhone();
		break;
	default:
		break;
	}
}
int main()
{
	Test();
	system("pause");
	return 0;
}