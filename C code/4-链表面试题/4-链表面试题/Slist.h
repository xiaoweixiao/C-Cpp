#pragma once
#include<stdio.h>
#include<Windows.h>
#include<assert.h>

#define  Datatype int
typedef struct SlistNode
{
	struct SlistNode*next;
	Datatype x;
}SlistNode;

SlistNode* BuySlist(Datatype x)
{
	SlistNode*node = (SlistNode*)malloc(sizeof(SlistNode));
	assert(node);
	node->x = x;
	node->next = NULL;
	return node;
}

void SlistPushBack(SlistNode**pphead,Datatype x)
{
	if (NULL == *pphead)
	{
		*pphead = BuySlist(x);
	}
	else
	{
		SlistNode*cur = *pphead;
		while (cur->next)
			cur = cur->next;
		cur ->next= BuySlist(x);
	}
}
void SlistPrint(SlistNode*phead)
{
	SlistNode*cur = phead;
	if (phead == NULL)
		return;
	while (cur)
	{
		printf("%d->", cur->x);
		cur = cur->next;
	}
	printf("NULL\n");
}
void SlistPrintTailToHead(SlistNode* phead)					//��β��ͷ��ӡ������ǵݹ�
{
	SlistNode*end = NULL;
	while (end != phead)
	{
		SlistNode*cur = phead;
		while (cur->next != end)
			cur = cur->next;
		printf("%d ", cur->x);
		end = cur;
	}
	printf("\n");
}

void PrintTailToHeadR(SlistNode* head)					//��β��ͷ��ӡ������ݹ鷨
{
	if (head == NULL)
		return;

	PrintTailToHeadR(head->next);
	printf("%d ", head->x);
}
SlistNode* SlistFind(SlistNode*ps,Datatype x)
{
	SlistNode*cur = ps;
	while (cur)
	{
		if (cur->x == x)
			return cur;
		cur = cur->next;
	}
	return NULL;
}

void SlistDelNonTailNode(SlistNode* pos)			//ɾ��һ����ͷ������ķ�β�ڵ㣨���ܱ�������
{
	//�滻��
	assert(pos&&pos->next);
	SlistNode*npos = pos->next;
	pos->x = npos->x;
	pos->next = npos->next;
	free(npos);
	npos = NULL;
}

void SlistInsertFront(SlistNode* pos, Datatype x)//����ͷ�������һ���ڵ�ǰ����һ���ڵ㣨���ܱ�������
{
	SlistNode*newnode = (SlistNode*)malloc(sizeof(SlistNode));
	assert(newnode&&pos);
	newnode->x = pos->x;
	newnode->next = pos->next;
	pos ->x=x;
	pos->next = newnode;
}

void SlistErase(SlistNode**phead,SlistNode*pos)
{
	SlistNode *cur = *phead;
	if ((*phead) == NULL || pos == NULL)
		;
	while (cur->next != pos)
		cur = cur->next;
	cur->next = pos->next;
	free(pos);
	pos = NULL;
}
SlistNode* SlistJosephCircle(SlistNode*phead, int k)//������ʵ��Լɪ��(JosephCircle)
{
	SlistNode*cur =phead;
	SlistNode*tail = phead;
	if (phead == NULL)
		return NULL;
	//���ɻ�
	while (tail->next != NULL)
		tail = tail->next;
	tail->next = phead;
	while (cur->next != cur)
	{
		SlistNode*next = cur->next;
		int count = k;

		while (--count)
			cur = cur->next;

		cur->x = next->x;
		cur->next = next->next;

		free(next);
	}
	return cur;
}


SlistNode* SlistReverse1(SlistNode* list)			//�͵����� / ��ת������
{
	SlistNode*n1, *n2, *n3;
	if (list == NULL || list->next == NULL)
		return list;
	n1= list;
	n2 = n1->next;
	n3 =n2->next;
	while (n2)
	{
		n2->next = n1;
		n1 = n2;
		n2 = n3;
		if (n3)
			n3 = n3->next;
	}
	//������n2Ϊ���ˣ�n1�������һ����㡣
	list->next = NULL;
	list = n1;
	return list;
}
SlistNode*SlistReverse2(SlistNode*s)		//ͷ��ʽ����
{
	SlistNode*list = NULL;
	SlistNode*cur = s;
	while (cur)
	{
		SlistNode*pre = cur;			//������s�ĵ�cur��������pre���
		cur = cur->next;
										
		pre->next = list;				//�������Ľ��ͷ�嵽list��
		list = pre;
	}
	return list;
}


void Swap(size_t *a,size_t *b)
{
	(*a) ^= *b;
	(*b) ^= *a;
	(*a) ^= *b;
}
void SlistBubbleSort(SlistNode* list)				//����������ð������&��������
{
	SlistNode*tail = NULL, *cur = list;
	if (list == NULL || list->next == NULL)
		return;
	while (tail != list)
	{
		int flag = 0;
		SlistNode*next = cur->next;
		while (next != NULL)
		{
			if (cur->x > next->x)
			{
				Swap(&cur->x, &next->x);
				flag = 1;
			}
			cur = cur->next;
			next = next->next;
		}
		if (flag == 0)
			break;
		tail = cur;
	}
}


SlistNode* SlistMerge(SlistNode* list1, SlistNode* list2)			// ���� //�ϲ�������������, �ϲ�����Ȼ����
{
	SlistNode*cur1 = list1;
	SlistNode*cur2 = list2;
	SlistNode*new =NULL;
	SlistNode*newtail = NULL;
	if (cur1 == NULL)
		return cur2;
	if (cur2 == NULL)
		return cur1;
	if (cur1->x < cur2->x)
	{
		new = cur1;
		cur1 = cur1->next;
	}
	else
	{
		new = cur2;
		cur2 = cur2->next;
	}
	newtail = new;
	while (cur1&&cur2)
	{
		if (cur1->x < cur2->x)
		{
			newtail->next = cur1;
			cur1 = cur1->next;
		}
		else
		{
			newtail->next = cur2;
			cur2 = cur2->next;
		}
		newtail = newtail->next;
	}
	if (cur1)
		newtail->next = cur1;
	if (cur2)
		newtail->next = cur2;
	return new;
}
SlistNode* SlistFindMidNode(SlistNode* list)//���ҵ�������м�ڵ㣬Ҫ��ֻ�ܱ���һ������
{
	SlistNode*slow = list, *fast = list->next->next;//fast����
	if (list == NULL||list->next==NULL)
		return list;
	
	while (fast)
	{
		slow = slow->next;
		fast = fast->next;
		if (fast)
			fast = fast->next;
	}
	return slow;
}


SlistNode* SlistFindTailKNode(SlistNode* list, int k)//���ҵ�����ĵ�����k���ڵ㣬Ҫ��ֻ�ܱ���һ������
{
	SlistNode*slow, *fast;
	slow = fast =list;
	while (k--)
	{
		if (fast == NULL)
			return NULL;
		fast = fast->next;
	}
	while (fast)
	{
		slow = slow->next;
		fast = fast->next;
	}
	return slow;
}



void DelTailK(SlistNode**p, int k)//ɾ������ĵ�����K�����
{
	SlistNode*tmp=SlistFindTailKNode(*p, k);
	SlistNode*prev = *p, *cur = prev->next;
	while (prev!=tmp)
	{
		prev = prev->next;
		cur = cur->next;
	}
	prev->next = cur->next;
	free(cur);
	cur = NULL;
}


SlistNode* SlistIsCycle(SlistNode* list)// ����������� //�жϵ������Ƿ������
{
	SlistNode*slow=list, *fast=list;
	while (fast&&fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;
		if (fast == slow)
			return fast;
	}
	return NULL;
}


SlistNode* SlistEntryNode(SlistNode* list, SlistNode* meet)//�󻷵���ڵ㣿
{
	while (list != meet)
	{
		list = list->next;
		meet = meet->next;
	}
	return meet;
}


int SlistCycleLen(SlistNode*entry,SlistNode* meet)//���������󻷵ĳ��ȣ�
{
	int len = 1;
	while (meet != entry)
	{
		entry = entry->next;
		len++;
	}
	entry = entry->next;
	while (meet != entry)
	{
		entry = entry->next;
		len++;
	}
	return len;
}



// �����ཻ���� 
int SlistIsCrossNode(SlistNode* list1, SlistNode* list2)//�ж����������Ƿ��ཻ
{
	SlistNode*cur1=list1, *cur2=list2;
	while (cur1->next)
		cur1 = cur1->next;
	while (cur2->next)
		cur2 = cur2->next;
	if (cur1 == cur2)
		return 1;
	else
		return 0;
}

SlistNode* SlistCrossNode(SlistNode* list1, SlistNode* list2)//���ཻ���󽻵㡣����������������
{
	int len1 = 0, len2 = 0, gap = 0;
	SlistNode*shortlist=list2, *longlist=list1;
	SlistNode*cur1 = list1, *cur2 = list2;
	while (cur1)
	{
		++len1;
		cur1 = cur1->next;
	}
	while (cur2)
	{
		++len2;
		cur2 = cur2->next;
	}
	
	
	if (len1 < len2)
	{
		longlist = list2;
		shortlist = list1;
	}
	gap = abs(len1 - len2);
	while (gap--)
		longlist = longlist->next;
	while (longlist != shortlist)
	{
		longlist = longlist->next;
		shortlist = shortlist->next;
	}
	return shortlist;
}


void UnionSet(SlistNode* list1, SlistNode* list2);//��������������������ͬ�����ݡ�
void UnionSet(SlistNode*list1, SlistNode*list2)
{
	assert(list1&&list2);
	SlistNode*cur1 = list1;
	SlistNode*cur2 = list2;
	while (cur1 && cur2)
	{
		if (cur1->x == cur2->x)
		{
			printf("%d\n", cur1->x);
			cur1 = cur1->next;
			cur2 = cur2->next;
		}
		else if (cur1->x < cur2->x)
			cur1 = cur1->next;
		else
			cur2 = cur2->next;
	}
}

// ���������� 
typedef struct ComplexListNode
{
	int data;
	struct ComplexListNode* next;
	struct ComplexListNode* random;
}ComplexListNode;


void ComplexListPrint(ComplexListNode*list)
{
	ComplexListNode*cur = list;
	while (cur)
	{
		if (cur->random==NULL)
		{
			printf("%d:NULL", cur->data);
			cur = cur->next;	
		}
		else
		{
			printf("%d:%d  ", cur->data,cur->random->data);
			cur = cur->next;
		}
	}
}
ComplexListNode* BuyComplexNode(int x)
{
	ComplexListNode*newnode = (ComplexListNode*)malloc(sizeof(ComplexListNode));
	assert(newnode);

	newnode->data = x;
	newnode->next = NULL;
	newnode->random = NULL;

	return newnode;
}
ComplexListNode* CopyComplexList(ComplexListNode* list);//��������ĸ��ơ�һ�������ÿ���ڵ㣬��һ��ָ��nextָ��ָ��
//��һ���ڵ㣬����һ��randomָ��ָ����������е�һ������ڵ����NULL������Ҫ��ʵ�ָ�������������ظ��ƺ��������
ComplexListNode* CopyComplexList(ComplexListNode*list)
{
	ComplexListNode*new = NULL, *tail = NULL;
	//1��������ƽ��
	ComplexListNode*cur = list;
	if (cur == NULL)
		return NULL;
	while (cur)
	{
		ComplexListNode*newnode = BuyComplexNode(cur->data);
		ComplexListNode*next = cur->next;
		
		cur->next = newnode;
		newnode->next=next;

		cur = newnode->next;
	}

	//2����random
	cur = list;
	while (cur)
	{
		ComplexListNode*copy = cur->next;
		if (cur->random == NULL)
		{
			copy->random = NULL;
			cur = cur->next->next;
		}
		else
		{
			copy->random = cur->random->next;
			cur = cur->next->next;
		}
	}
	//3����,�ֱ�������
	new = tail = list->next;
	list->next = new->next;
	cur = list->next;
	while (cur)
	{
		ComplexListNode*copy=cur->next;
		cur->next = copy->next;

		tail->next = copy;
		tail = copy;

		cur = cur->next;
	}
	return new;
}
