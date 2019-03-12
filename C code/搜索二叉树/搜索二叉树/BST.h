#pragma once 
#include<stdio.h>
#include<Windows.h>
#include<assert.h>

typedef int DataType;

typedef struct BSTreeNode
{
	struct BSTreeNode* _left;
	struct BSTreeNode* _right;

	DataType _data;
}BSTreeNode;
// �ǵݹ� 
BSTreeNode* BuyBSTreeNode(DataType x);
int BSTreeInsert(BSTreeNode** tree, DataType x);
const BSTreeNode* BSTreeFind(BSTreeNode* tree, DataType x);
int BSTreeRemove(BSTreeNode** tree, DataType x);
void BSTreeDestory(BSTreeNode* tree);
// �ݹ� 
int BSTreeInsertR(BSTreeNode** tree, DataType x);
const BSTreeNode* BSTreeFindR(BSTreeNode* tree, DataType x);
int BSTreeRemoveR(BSTreeNode** tree, DataType x);

// �ǵݹ� 
BSTreeNode* BuyBSTreeNode(DataType x)
{
	BSTreeNode*node = (BSTreeNode*)malloc(sizeof(BSTreeNode));
	assert(node);
	node->_data = x;
	node->_left = NULL;
	node->_right = NULL;
	return node;
}
int BSTreeInsert(BSTreeNode** tree, DataType x)
{
	BSTreeNode*cur = *tree;
	BSTreeNode*parent = NULL;
	if (*tree == NULL)
	{
		*tree=BuyBSTreeNode(x);
		return 0;
	}
	while (cur)
	{
		if (x < cur->_data)
		{
			parent = cur;
			cur = cur->_left;
		}
		else if (x>cur->_data)
		{
			parent = cur;
			cur = cur->_right;
		}
		else
			return -1;
	}
	if (x > parent->_data)
		parent->_right = BuyBSTreeNode(x);
	else
		parent->_left = BuyBSTreeNode(x);
	return 0;
}
const BSTreeNode* BSTreeFind(BSTreeNode* tree, DataType x)
{
	BSTreeNode*cur = tree;
	if (tree == NULL)
		return NULL;
	if (x == cur->_data)
		return cur;
	else
	{
		while (cur)
		{
			if (x < cur->_data)
				cur = cur->_left;
			else if (x>cur->_data)
				cur = cur->_right;
			else
				return cur;
		}
	}
	return NULL;
}
int BSTreeRemove(BSTreeNode** tree, DataType x)
{
	BSTreeNode*cur = *tree;
	BSTreeNode*parent = cur;
	//����Ҫɾ���Ľڵ�λ��cur
	while (cur)
	{
		if (x < cur->_data)
		{
			parent = cur;
			cur = cur->_left;
		}
		else if (x>cur->_data)
		{
			parent = cur;
			cur = cur->_right;
		}
		else
			break;
	}
	if (cur == NULL)
		return -1;
	//�滻��ɾ����cur�����Һ��Ӷ���Ϊ�գ�cur�����������ҽ���ֵ����cur->_data,
	if (cur->_left&&cur->_right)
	{
		if (parent == NULL)
		{
			parent = cur;
		}
		BSTreeNode*subright = cur->_left;
		while (subright->_right)
		{
			parent = subright;
			subright = subright->_right;
		}
		cur->_data = subright->_data; 
		if (subright == cur->_left)
			parent = cur;
		cur = subright;
	}
	if (cur->_left == NULL)//cur����Ϊ�ջ������Ҷ�Ϊ��
	{
		if (cur == parent->_left)
			parent->_left = cur->_right;
		else
			parent->_right = cur->_right;
		free(cur);
		cur = NULL;
	}
	else//cur����Ϊ�ջ������Ҷ�Ϊ��
	{
		if (cur == parent->_left)
			parent->_left = cur->_left;
		else
			parent->_right = cur->_left;
		free(cur);
		cur = NULL;
	}
	return 0;
}
void BSTreeDestory(BSTreeNode* tree)
{
	if (tree->_left)
		BSTreeDestory(tree->_left);
	if (tree->_right)
		BSTreeDestory(tree->_right);
	if (tree->_left == NULL && tree->_right == NULL)
	{
		free(tree);
		tree = NULL;
	}
}
 //�ݹ� 
int BSTreeInsertR(BSTreeNode** tree, DataType x)
{
	if (*tree == NULL)
	{
		*tree = BuyBSTreeNode(x);
		return 0;
	}
	else if (x < (*tree)->_data)
		BSTreeInsertR(&(*tree)->_left, x);
	else if (x>(*tree)->_data)
		BSTreeInsertR(&(*tree)->_right, x);
	else
		return -1;
	return -1;
}
const BSTreeNode* BSTreeFindR(BSTreeNode* tree, DataType x)
{
	if (x == tree->_data)
		return tree;

	if (x>tree->_data)
		return BSTreeFindR(tree->_right, x);
	else
		return BSTreeFindR(tree->_left, x);
}
int BSTreeRemoveR(BSTreeNode** tree, DataType x)
{
	if (*tree == NULL)
		return -1;
	if (x < (*tree)->_data)
		return BSTreeRemoveR(&(*tree)->_left, x);
	else if (x>(*tree)->_data)
		return BSTreeRemoveR(&(*tree)->_right, x);
	else
	{
		BSTreeNode*parent = *tree;
		//ɾ�����
		//�������������������滻ɾ��
		if ((*tree)->_left && (*tree)->_right)
		{
			BSTreeNode*sub = (*tree)->_right;
			while (sub->_left)
			{
				parent = sub;
				sub = sub->_left;
			}
			(*tree)->_data = sub->_data;
			*tree = sub;
		}

		if ((*tree)->_left == NULL)
		{
			if (parent->_left == (*tree))
				parent->_left = (*tree)->_right;
			else
				parent->_right = (*tree)->_right;
			free(*tree);
			*tree = NULL;
			return 0;
		}
		else
		{
			if (parent->_left == (*tree))
				parent->_left = (*tree)->_left;
			else
				parent->_right = (*tree)->_left;

			free(*tree);
			*tree = NULL;
		}
	}
	return -1;
}