#include"phone.h"

void Menu()
{
	cout << "----------------------------------------------------------------------------------" << endl;
	cout << "0���˳�ϵͳ							 1�������ϵ����Ϣ					    	" << endl;
	cout << "2��ɾ��ָ����ϵ����Ϣ					 3��������ϵ��			" << endl;
	cout << "4���޸���ϵ��							 5����ʾͨѶ¼������ϵ����Ϣ		" << endl;
	cout << "6�����ͨѶ¼												" << endl;
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