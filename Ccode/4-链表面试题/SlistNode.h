//SlistNode.h
#ifndef _SlistNode_h_
#define _SlistNode_h_
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<Windows.h>
#include<assert.h>
typedef int DataType;

typedef struct SlistNode
{
	struct SlistNode* next;
	DataType data;
}SlistNode;


SlistNode* BuySlistNode(DataType x)//����������
{
	SlistNode*node = (SlistNode*)malloc(sizeof(SlistNode));
	assert(node);
	node->data = x;
	node->next = NULL;
	return node;
}


void SlistPrint(SlistNode* phead)//��ӡ������
{
	SlistNode*cur = phead;
	while (cur)
	{
		printf("%d->", cur->data);
		cur = cur->next;
	}
	printf("NULL\n");
}


void SlistDestory(SlistNode** pphead)//���ٵ�����
{
	SlistNode*cur = *pphead;
	while (cur)
	{
		free(cur);
		cur = cur->next;
	}
	*pphead = NULL;
}

void SlistPushBack(SlistNode** pphead, DataType x)//β������
{
	if (NULL == *pphead)
	{
		(*pphead) = BuySlistNode(x);
	}
	else
	{
		SlistNode*cur = *pphead;
		while (cur->next != NULL)
		{
			cur = cur->next;
		}
		cur->next = BuySlistNode(x);
		cur = cur->next;
	}
}
void SlistPopBack(SlistNode** pphead)//β��ɾ��
{
	//�ڵ�һ����������������������
	if (NULL == *pphead)
		return;
	else if ((*pphead)->next == NULL)
	{
		free(*pphead);
		*pphead = NULL;
	}
	else

	{
		SlistNode*prev = NULL;
		SlistNode*cur = *pphead;
		while (cur->next)
		{
			prev = cur;
			cur = cur->next;
		}
		free(cur);
		prev->next = NULL;
	}
}


void SlistPushFront(SlistNode** pphead, DataType x)//ͷ������
{
	if (NULL == *pphead)
	{
		*pphead = BuySlistNode(x);
		(*pphead)->next = NULL;
	}
	else
	{
		SlistNode*node = BuySlistNode(x);
		node->next = *pphead;
		(*pphead) = node;
	}
}
void SlistPopFront(SlistNode**pphead)
{
	if (*pphead == NULL)
		return;
	else
	{
		SlistNode*next = (*pphead)->next;
		free(*pphead);
		*pphead = next;
	}
}
SlistNode* SlistFind(SlistNode* phead, DataType x)//Slist�в���x
{
	SlistNode*cur = phead;
	while (cur)
	{
		if (cur->data == x)
			return cur;
		cur = cur->next;
	}
	return NULL;
}
void SlistInsest(SlistNode** pphead, SlistNode* pos, DataType x)//posλ�ò���x
{
	assert(*pphead);

	if (*pphead == pos)
	{
		SlistPushFront(pphead, x);
	}
	else
	{
		SlistNode*node = BuySlistNode(x);
		node->next = pos->next;
		pos->next = node;
	}
}
void SlistErase(SlistNode** pphead, SlistNode* pos)//ɾ��posλ�ý��
{
	assert(*pphead);

	if (*pphead == pos)
	{
		free(*pphead);
		pphead = NULL;
	}
	else
	{
		SlistNode*prev = *pphead;
		while (prev->next != pos)
			prev = prev->next;
		SlistNode*next = pos->next;
		//prev   next
		prev->next = next;
		free(pos);
	}
}
#endif