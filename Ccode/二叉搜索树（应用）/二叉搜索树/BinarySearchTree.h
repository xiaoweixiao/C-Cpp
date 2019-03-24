//1. 判断一个单词是否拼写正确
//2. 请模拟实现一个简单的中英互译的字典
//3. log文件中有许多异常重复的IP地址，请统计出每个异常IP出现了多少
//次？
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

	BSTreeInsertR(&tree, "tree", "树");
	BSTreeInsertR(&tree, "sort", "排序");
	BSTreeInsertR(&tree, "binary", "二分");
	BSTreeInsertR(&tree, "return", "返回");
	BSTreeInsertR(&tree, "hash", "哈希");
	BSTreeInsertR(&tree, "list", "链表");

	printf("%s\n", BSTreeFindR(tree, "tree")->_value);
	printf("%s\n", BSTreeFindR(tree, "return")->_value);
	printf("%s\n", BSTreeFindR(tree, "hash")->_value);
	printf("%s\n", BSTreeFindR(tree, "list")->_value);
};