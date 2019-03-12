#include"BT.h"

void TestBinaryTree()
{
	int a[] = { 1, 2, 3, '#', '#', 4, '#', '#', 5, 6, '#', '#', '#' };
	size_t index = 0;
	BTNode* tree = CreateBTree(a, &index, '#');
	BTreePrevOrder(tree);
	printf("\n");
	BTreePrevOrderNonR(tree);
	BTreeInOrder(tree);
	printf("\n");
	BTreeInOrderNonR(tree);
	BTreePostOrder(tree);
	printf("\n");
	BTreePostOrderNonR(tree);

	printf("BTreeSize?%d\n", BTreeSize(tree));
	printf("BTreeLeafSize?%d\n", BTreeLeafSize(tree));
	printf("BTreeKLevelSize?%d\n", BTreeKLevelSize(tree, 2));
	printf("BTreeDepth?%d\n", BTreeDepth(tree));
	printf("IsCompleteBTree?%d\n", IsCompleteBTree1(tree));
	BTreeLevelOrder(tree);

	printf("%d\n", BTreeFind(tree, 4)->_data);
}
int main()
{
	TestBinaryTree();
	system("pause");
	return 0;
}