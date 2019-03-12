
#include<stdio.h>
#include<assert.h>
#include<Windows.h>

typedef int DataType;

typedef struct DlistNode
{
	struct DlistNode* next;
	struct DlistNode* prev;
	DataType data;
}DlistNode;


DlistNode* BuyDlistNode(DataType x);
DlistNode* DListInit();
void DListDestory(DlistNode* head);
void DListPrint(DlistNode* head);

void DListPushBack(DlistNode* head, DataType x);
void DListPushFront(DlistNode* head, DataType x);
void DListPopBack(DlistNode* head);
void DListPopFront(DlistNode* head);

DlistNode* DListFind(DlistNode* head, DataType x);
void DListInsert(DlistNode* pos, DataType x);
void DListErase(DlistNode* pos);

void DListPrint(DlistNode* head);
DlistNode* DListInit();

void test1();
void test2();

DlistNode* BuyDlistNode(DataType x)
{
	DlistNode*new = (DlistNode*)malloc(sizeof(DlistNode));
	assert(new);

	new->data = x;
	new->next = NULL;
	new->prev = NULL;
	return new;
}
DlistNode* DListInit()
{
	DataType x = 10;
	DlistNode*list = BuyDlistNode(x);

	list->next = list;
	list->prev = list;

	return list;
}
void DListDestory(DlistNode*head)
{
	DlistNode*cur = head->next;
	while (cur!=head)
	{
		DlistNode*next = cur->next;
		free(cur);
		cur = next;
	}
	free(head);
	head = NULL;
}
void DListPrint(DlistNode* head)
{
	DlistNode*cur = head->next;
	while (cur != head)
	{
		printf("%d ", cur->data);
		cur = cur->next;
	}
	printf("head\n");
}

void DListPushBack(DlistNode* head, DataType x)
{
	/*assert(head);
	DlistNode*tail = head->prev;
	DlistNode* newnode = BuyDlistNode(x);
	tail->next = newnode;
	newnode->prev = tail;

	newnode->next = head;
	head->prev = newnode;*/
	DListInsert(head->prev, x);
}

void DListPopBack(DlistNode* head)
{
	/*assert(head);
	DlistNode*tail = head->prev;
	DlistNode*prev = tail->prev;
	if (head->next == NULL)
		return;

	free(tail);
	tail = NULL;

	prev->next = head;
	head->prev = prev;*/
	DListErase(head->prev);
}

void DListPushFront(DlistNode* head, DataType x)
{
	/*assert(head);
	DlistNode*next = head->next;
	DlistNode*newnode = BuyDlistNode(x);

	head->next = newnode;
	newnode->prev = head;

	newnode->next = next;
	next->prev = newnode;*/
	DListInsert(head, x);
}

void DListPopFront(DlistNode* head)
{
	/*assert(head);
	DlistNode*next = head->next;
	DlistNode*newnext = next->next;
	free(next);
	next = NULL;

	head->next = newnext;
	newnext->prev = head;*/
	
	DListErase(head->next);
}

DlistNode* DListFind(DlistNode* head, DataType x)
{
	assert(head);
	DlistNode*cur = head->next;
	if (x == cur->data)
		return cur;
	while (cur != head)
	{
		if (x == cur->data)
			return cur;
		cur = cur->next;
	}
	return NULL;
}

void DListInsert(DlistNode* pos, DataType x)
{
	DlistNode*newnode = BuyDlistNode(x);
	DlistNode*next = pos->next;
	//pos newnode next
	pos->next = newnode;
	newnode->prev = pos;

	newnode->next = next;
	next->prev = newnode;
}
void DListErase(DlistNode* pos)
{
	DlistNode*prev = pos->prev;
	DlistNode*next = pos->next;
	free(pos);
	pos = NULL;
	prev->next = next;
	next->prev = prev;
}

void test1()
{
	DlistNode* list = DListInit();
	DListPushBack(list, 1);
	DListPushBack(list, 2);
	DListPushBack(list, 3);
	DListPushBack(list, 4);
	DListPushBack(list, 5);
	DListPrint(list);

	DListPopBack(list);
	DListPopBack(list);
	DListPrint(list);
}

void test2()
{
	DlistNode* list = DListInit();
	DListPushFront(list, 1);
	DListPushFront(list, 2);
	DListPushFront(list, 3);
	DListPushFront(list, 4);
	DListPushFront(list, 5);
	DListPrint(list);
	printf("%d\n", DListFind(list, 3)->data);

	DListPopFront(list);
	DListPopFront(list);
	DListPrint(list);
}
