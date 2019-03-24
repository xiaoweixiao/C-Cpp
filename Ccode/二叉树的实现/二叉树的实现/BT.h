#pragma once 

typedef int BTDataType;

typedef struct BinaryTreeNode
{
	struct BinaryTreeNode* _left;
	struct BinaryTreeNode* _right;
	BTDataType _data;
}BTNode;

#include "Queue.h" 
#include "Stack.h" 

BTNode* BuyBTNode(BTDataType x);
// 创建二叉树 
BTNode* CreateBTree(BTDataType* a, size_t* pIndex, BTDataType invalid);
void BTreePrevOrder(BTNode* root);
void BTreeInOrder(BTNode* root);
void BTreePostOrder(BTNode* root);

size_t BTreeSize(BTNode* root);
size_t BTreeLeafSize(BTNode* root);
size_t BTreeKLevelSize(BTNode* root, size_t k);
size_t BTreeDepth(BTNode* root);
BTNode* BTreeFind(BTNode* root, BTDataType x);
void BTreeLevelOrder(BTNode* root);
// 判断完全二叉树 
int IsCompleteBTree(BTNode* root);
int IsCompleteBTree1(BTNode* root);// flag的方式判断 
// 非递归遍历 
void BTreePrevOrderNonR(BTNode* root);
void BTreeInOrderNonR(BTNode* root);
void BTreePostOrderNonR(BTNode* root);


BTNode* BuyBTNode(BTDataType x)
{
	BTNode* node = (BTNode*)malloc(sizeof(BTNode));
	assert(node);

	node->_data = x;
	node->_left = NULL;
	node->_right = NULL;
	return node;
}
BTNode* CreateBTree(BTDataType* a, size_t* pIndex, BTDataType invalid)
{
	assert(a);

	BTNode*tree=NULL;
	if (a[*pIndex] == invalid)
		tree=NULL;
	else
	{
		tree = BuyBTNode(a[*pIndex]);
		(*pIndex)++;
		tree->_left = CreateBTree(a, pIndex, invalid);

		(*pIndex)++;
		tree->_right = CreateBTree(a, pIndex, invalid);
	}
	return tree;
}
void BTreePrevOrder(BTNode* root)
{
	if (root == NULL)
		return;
	
	printf("%d ", root->_data);
	BTreePrevOrder(root->_left);
	BTreePrevOrder(root->_right);
}
void BTreeInOrder(BTNode* root)
{
	if (root == NULL)
		return;
	
	BTreeInOrder(root->_left);
	printf("%d ", root->_data);
	BTreeInOrder(root->_right);
}
void BTreePostOrder(BTNode* root)
{
	if (root == NULL)
		return;

	BTreePostOrder(root->_left);
	BTreePostOrder(root->_right);
	printf("%d ", root->_data);
}

size_t BTreeSize(BTNode* root)
{
	if (root == NULL)
		return 0;
	else
		return 1+BTreeSize(root->_left) + BTreeSize(root->_right);
}
size_t BTreeLeafSize(BTNode* root)
{
	if (root == NULL)
		return 0;
	else if (root->_left == NULL&&root->_right == NULL)
		return 1;
	else
		return BTreeLeafSize(root->_left) + BTreeLeafSize(root->_right);
}
size_t BTreeKLevelSize(BTNode* root, size_t k)
{
	if (root == NULL)
		return 0;
	else if (k == 1)
		return 1;
	else
		return BTreeKLevelSize(root->_left, k - 1) + BTreeKLevelSize(root->_right, k - 1);
}
size_t BTreeDepth(BTNode* root)
{
	size_t depthleft = 0, depthright = 0;
	if (root == NULL)
		return 0;
	depthleft = BTreeDepth(root->_left);
	depthright = BTreeDepth(root->_right);
		return depthleft > depthright ?  (1+depthleft):(1+depthright);
}

BTNode* BTreeFind(BTNode* root, BTDataType x)
{
	BTNode*key = NULL;
	if (root == NULL)
		return NULL;
	
	if (root->_data == x)
		key=root;
	else
	{
		key = BTreeFind(root->_left, x);
		if (key==NULL)
			key = BTreeFind(root->_right, x);
	}
	return key;
}
void BTreeLevelOrder(BTNode* root)
{
	Queue q;
	BTNode*cur = root;
	QueueInit(&q);
	if (cur != NULL)
	{
		QueuePush(&q, cur);
	}
	while (QueueEmpty(&q))
	{
		cur = QueueFront(&q);
		printf("%d ", cur->_data);
		QueuePop(&q);
		if (cur->_left)
			QueuePush(&q, cur->_left);
		if (cur->_right)
			QueuePush(&q, cur->_right);
	}
	printf("\n");
}
int IsCompleteBTree(BTNode* root)
{
	Queue q;
	BTNode*cur = root;
	QueueInit(&q);
	if (cur != NULL)
	{
		QueuePush(&q, cur);
	}
	while (QueueEmpty(&q))
	{
		cur = QueueFront(&q);
		QueuePop(&q);
		if (cur == NULL)
			break;
		else
		{
			QueuePush(&q, cur->_left);
			QueuePush(&q, cur->_right);
		}
	}
	while (QueueEmpty(&q))
	{
		cur = QueueFront(&q);
		if (cur != NULL)
			return -1;
		QueuePop(&q);
	}
	return 0;
}
int IsCompleteBTree1(BTNode* root)// flag的方式判断 
{
	Queue q;
	int flag = 0;
	BTNode*cur = root;
	QueueInit(&q);
	if (cur != NULL)
		QueuePush(&q, cur);
	while (QueueEmpty(&q))
	{
		cur = QueueFront(&q);
		QueuePop(&q);
		if (cur == NULL)
			break;
		else
		{
			if (cur->_left == NULL)
				flag = -1;
			else 
				QueuePush(&q, cur->_left);
			if (cur->_right == NULL)
				flag = -1;
			else
			{
				if (flag != 0)
					return -1;
				QueuePush(&q, cur->_left);
			}
		}
	}
	return 0;
}
void BTreePrevOrderNonR(BTNode* root)
{
	BTNode*cur = root;
	Stack s;
	StackInit(&s, 10);
	if (root == NULL)
		return;
	//访问左树
	while (cur || StackEmpty(&s))
	{
		while (cur)
		{
			printf("%d ", cur->_data);
			StackPush(&s, cur);
			cur = cur->_left;
		}
		BTNode* top = StackTop(&s);
		StackPop(&s);
		//访问右树，子问题
		cur = top->_right;
	}
	printf("\n");
}
void BTreeInOrderNonR(BTNode* root)
{
	BTNode*cur = root;
	Stack s;
	StackInit(&s, 10);
	if (root == NULL)
		return;
	while (cur || StackEmpty(&s))
	{
		while (cur)
		{
			StackPush(&s, cur);
			cur = cur->_left;
		}
		BTNode*top = StackTop(&s);
		printf("%d ", top->_data);//访问根节点，左树已经访问完了。
		StackPop(&s);
		//访问右树，子问题
		cur = top->_right;
	}
	printf("\n");
}
void BTreePostOrderNonR(BTNode* root)
{
	BTNode*cur = root;
	BTNode*prev = NULL;
	Stack s;
	StackInit(&s,10);
	while (cur || StackEmpty(&s))
	{
		while (cur)
		{
			StackPush(&s, cur);
			cur = cur->_left;
		}
		BTNode*top = StackTop(&s);
		if (top->_right == NULL||top->_right==prev)
		{
			printf("%d ", top->_data);
			StackPop(&s);
			prev = top;
		}
		else
		{
			cur = top->_right;
		}
	}
	printf("\n");
}

