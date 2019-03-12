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
void SlistPrintTailToHead(SlistNode* phead)					//从尾到头打印单链表非递归
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

void PrintTailToHeadR(SlistNode* head)					//从尾到头打印单链表递归法
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

void SlistDelNonTailNode(SlistNode* pos)			//删除一个无头单链表的非尾节点（不能遍历链表）
{
	//替换法
	assert(pos&&pos->next);
	SlistNode*npos = pos->next;
	pos->x = npos->x;
	pos->next = npos->next;
	free(npos);
	npos = NULL;
}

void SlistInsertFront(SlistNode* pos, Datatype x)//在无头单链表的一个节点前插入一个节点（不能遍历链表）
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
SlistNode* SlistJosephCircle(SlistNode*phead, int k)//单链表实现约瑟夫环(JosephCircle)
{
	SlistNode*cur =phead;
	SlistNode*tail = phead;
	if (phead == NULL)
		return NULL;
	//构成环
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


SlistNode* SlistReverse1(SlistNode* list)			//就地逆置 / 反转单链表
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
	//到这里n2为空了，n1成了最后一个结点。
	list->next = NULL;
	list = n1;
	return list;
}
SlistNode*SlistReverse2(SlistNode*s)		//头插式逆置
{
	SlistNode*list = NULL;
	SlistNode*cur = s;
	while (cur)
	{
		SlistNode*pre = cur;			//拿来了s的第cur个结点放在pre结点
		cur = cur->next;
										
		pre->next = list;				//把拿来的结点头插到list里
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
void SlistBubbleSort(SlistNode* list)				//单链表排序（冒泡排序&快速排序）
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


SlistNode* SlistMerge(SlistNode* list1, SlistNode* list2)			// 升序 //合并两个有序链表, 合并后依然有序
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
SlistNode* SlistFindMidNode(SlistNode* list)//查找单链表的中间节点，要求只能遍历一次链表
{
	SlistNode*slow = list, *fast = list->next->next;//fast先走
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


SlistNode* SlistFindTailKNode(SlistNode* list, int k)//查找单链表的倒数第k个节点，要求只能遍历一次链表
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



void DelTailK(SlistNode**p, int k)//删除链表的倒数第K个结点
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


SlistNode* SlistIsCycle(SlistNode* list)// 链表带环问题 //判断单链表是否带环？
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


SlistNode* SlistEntryNode(SlistNode* list, SlistNode* meet)//求环的入口点？
{
	while (list != meet)
	{
		list = list->next;
		meet = meet->next;
	}
	return meet;
}


int SlistCycleLen(SlistNode*entry,SlistNode* meet)//若带环，求环的长度？
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



// 链表相交问题 
int SlistIsCrossNode(SlistNode* list1, SlistNode* list2)//判断两个链表是否相交
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

SlistNode* SlistCrossNode(SlistNode* list1, SlistNode* list2)//若相交，求交点。（假设链表不带环）
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


void UnionSet(SlistNode* list1, SlistNode* list2);//求两个已排序单链表中相同的数据。
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

// 复杂链表复制 
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
ComplexListNode* CopyComplexList(ComplexListNode* list);//复杂链表的复制。一个链表的每个节点，有一个指向next指针指向
//下一个节点，还有一个random指针指向这个链表中的一个随机节点或者NULL，现在要求实现复制这个链表，返回复制后的新链表。
ComplexListNode* CopyComplexList(ComplexListNode*list)
{
	ComplexListNode*new = NULL, *tail = NULL;
	//1、逐个复制结点
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

	//2、置random
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
	//3、拆开,分别链起来
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
