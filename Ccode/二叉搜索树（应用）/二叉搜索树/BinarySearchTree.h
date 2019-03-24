//1. �ж�һ�������Ƿ�ƴд��ȷ
//2. ��ģ��ʵ��һ���򵥵���Ӣ������ֵ�
//3. log�ļ���������쳣�ظ���IP��ַ����ͳ�Ƴ�ÿ���쳣IP�����˶���
//�Σ�
#include<stdio.h>

typedef char* KeyType;
typedef char* ValueType;

typedef struct BSTreeNode
{
	struct BSTreeNode* _left;
	struct BSTreeNode* _right;

	const KeyType _key;
	ValueType _value;

}BSTreeNode;

BSTreeNode* BuyBSTreeNode(KeyType key, ValueType value);
int BSTreeInsertR(BSTreeNode** tree, KeyType key, ValueType value);
BSTreeNode* BSTreeFindR(BSTreeNode* tree, KeyType key);
int BSTreeRemoveR(BSTreeNode** tree, KeyType key);

void TestBSTree()
{
	BSTreeNode* tree = NULL;

	BSTreeInsertR(&tree, "tree", "��");
	BSTreeInsertR(&tree, "sort", "����");
	BSTreeInsertR(&tree, "binary", "����");
	BSTreeInsertR(&tree, "return", "����");
	BSTreeInsertR(&tree, "hash", "��ϣ");
	BSTreeInsertR(&tree, "list", "����");

	printf("%s\n", BSTreeFindR(tree, "tree")->_value);
	printf("%s\n", BSTreeFindR(tree, "return")->_value);
	printf("%s\n", BSTreeFindR(tree, "hash")->_value);
	printf("%s\n", BSTreeFindR(tree, "list")->_value);
};