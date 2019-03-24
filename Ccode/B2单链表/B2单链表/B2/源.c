
#include"SListNode.h"

void TestDestory();
void TestDestory()
{
	SListNode*list = NULL;
	SListPushBack(&list, 9);
	SListPushBack(&list, 1);
	SListPushBack(&list, 2);
	SListPushBack(&list, 3);
	SListPushBack(&list, 4);
	SListPrint(list);
	SListDestory(&list);
	SListPrint(list);
}
int main()
{
	//test1();
	//test2();
	TestDestory();
	system("pause");
	return 0;
}