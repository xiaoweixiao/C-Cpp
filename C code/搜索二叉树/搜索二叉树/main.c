#include"BST.h"

void PrevOrder(BSTreeNode*tree)
{
	if (tree == NULL)
		return;
	printf("%d ", tree->_data);
	PrevOrder(tree->_left);
	PrevOrder(tree->_right);
}
void TestBSTree()
{
	BSTreeNode* tree = NULL;
	/*BSTreeInsert(&tree, 4); 
	BSTreeInsert(&tree, 2); 
	BSTreeInsert(&tree, 1); 
	BSTreeInsert(&tree, 3); 
	BSTreeInsert(&tree, 8); 
	BSTreeInsert(&tree, 14);
	BSTreeInsert(&tree, 12);
	BSTreeInsert(&tree, 11);
	BSTreeInsert(&tree,13);
	BSTreeInsert(&tree, 12);
	BSTreeInsert(&tree, 5);
	BSTreeInsert(&tree, 6);
	BSTreeInsert(&tree, 7);*/
	BSTreeInsertR(&tree, 8);
	BSTreeInsertR(&tree, 14);
	BSTreeInsertR(&tree, 12);
	BSTreeInsertR(&tree, 11);
	BSTreeInsertR(&tree, 13);
	BSTreeInsertR(&tree, 12);
	PrevOrder(tree);
	printf("\n");
	const BSTreeNode* node = BSTreeFindR(tree, 12); 
	printf("Find?:%d\n", node->_data);
	/*BSTreeRemove(&tree, 2);
	BSTreeRemove(&tree, 1);
	BSTreeRemove(&tree, 3);
	BSTreeRemove(&tree, 8);
	BSTreeRemove(&tree, 6);
	BSTreeRemove(&tree, 7);
	BSTreeRemove(&tree, 5);
	BSTreeRemove(&tree, 9);
	BSTreeRemove(&tree, 11);
	BSTreeRemove(&tree, 13);
	BSTreeRemove(&tree, 14);
	BSTreeRemove(&tree, 12);
	BSTreeRemove(&tree, 4);*/
	//BSTreeDestory(tree);
	BSTreeRemoveR(&tree, 9);
	BSTreeRemoveR(&tree, 11);
	BSTreeRemoveR(&tree, 13);
	BSTreeRemoveR(&tree, 14);
	PrevOrder(tree);
	printf("\n");
	//BSTreeDestory(tree);
	//PrevOrder(tree);
	//printf("\n");
};
int main()
{
	TestBSTree();
	system("pause");
	return 0;
}