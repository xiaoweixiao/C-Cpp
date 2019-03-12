//SlistNode.h
#ifndef _SListNode_h_
#define _SListNode_h_
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<Windows.h>
#include<assert.h>
typedef int DataType;

typedef struct SListNode
{
	struct SListNode* next;
	DataType data;
}SListNode;


SListNode* BuySListNode(DataType x)//创建链表结点
{
	SListNode*node = (SListNode*)malloc(sizeof(SListNode));
	assert(node);
	node->data = x;
	node->next = NULL;
	return node;
}


void SListPrint(SListNode* phead)//打印单链表
{
	SListNode*cur = phead;
	while (cur)
	{
		printf("%d->", cur->data);
		cur = cur->next;
	}
	printf("NULL\n");
}


void SListDestory(SListNode** pphead)//销毁单链表
{
	SListNode*cur = *pphead;
	while (cur)
	{
		SListNode*next = cur->next;
		free(cur);
		cur = next;
	}
	*pphead = NULL;
}

void SListPushBack(SListNode** pphead, DataType x)//尾部插入
{
	if (NULL == *pphead)
	{
		(*pphead) = BuySListNode(x);
	}
	else
	{
		SListNode*cur = *pphead;
		while (cur->next != NULL)
		{
			cur = cur->next;
		}
		cur->next = BuySListNode(x);
	}
}
void SListPopBack(SListNode** pphead)//尾部删除
{
	//节点一个，两个，多个，三种情况
	if (NULL == *pphead)
		return;
	else if ((*pphead)->next == NULL)
	{
		free(*pphead);
		*pphead = NULL;
	}
	else

	{
		SListNode*prev = NULL;
		SListNode*cur = *pphead;
		while (cur->next)
		{
			prev = cur;
			cur = cur->next;
		}
		free(cur);
		prev->next=NULL;
	}
}


void SListPushFront(SListNode** pphead, DataType x)//头部插入
{
	if (NULL == *pphead)
	{
		*pphead = BuySListNode(x);
		(*pphead)->next = NULL;
	}
	else
	{
		SListNode*node = BuySListNode(x);
		node->next = *pphead;
		(*pphead) = node;
	}
}
void SlistPopFront(SListNode**pphead)
{
	if (*pphead == NULL)
		return;
	else
	{
		SListNode*next = (*pphead)->next;
		free(*pphead);
		*pphead = next;
	}
}
SListNode* SListFind(SListNode* phead, DataType x)//SList中查找x
{
	SListNode*cur = phead;
	while (cur)
	{
		if (cur->data == x)
			return cur;
		cur = cur->next;
	}
	return NULL;
}
void SListInsest(SListNode** pphead, SListNode* pos, DataType x)//pos位置插入x
{
	assert(*pphead);

	if (*pphead == pos)
	{
		SListPushFront(pphead,x);
	}
	else
	{
		SListNode*node = BuySListNode(x);
		node->next = pos->next;
		pos->next = node;
	}
}
void SListErase(SListNode** pphead, SListNode* pos)//删除pos位置结点
{
	assert(*pphead);

	if (*pphead == pos)
	{
		free(*pphead);
		pphead = NULL;
	}
	else
	{
		SListNode*prev = *pphead;
		while (prev->next != pos)
			prev = prev->next;
		SListNode*next = pos->next;
		//prev   next
		prev->next = next;
		free(pos);
	}
}

void test1()
{
	SListNode*List = NULL;
	SListPushBack(&List, 0);
	SListPushBack(&List, 1);
	SListPushBack(&List, 2);
	SListPushBack(&List, 3);
	SListPushBack(&List, 4);
	SListPopBack(&List);
	SListPushFront(&List,20);
	SListFind(List, 0);
	SListPrint(List);
}
void test2()
{
	SListNode*List = NULL;
	SListPushBack(&List, 0);
	SListPushBack(&List, 1);
	SListPushBack(&List, 2);
	SListPushBack(&List, 3);
	SListPushBack(&List, 4);
	SlistPopFront(&List);	
	SListPrint(List);
	SListNode*pos = SListFind(List, 3);
	SListInsest(&List, pos, 100);
	SListPrint(List);
	SListErase(&List, pos);
	SListPrint(List);
}
#endif