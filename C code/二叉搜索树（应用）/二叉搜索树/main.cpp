#include"BST.h"




void Test()
{
	BSTreeNode*node = NULL;
	BSTreeInsert(&node, "insert");
	BSTreeInsert(&node, "sort");
	BSTreeInsert(&node, "in");
	BSTreeInsert(&node, "sort");
}
int main()
{
	Test();
	system("pause");
	return 0;
}