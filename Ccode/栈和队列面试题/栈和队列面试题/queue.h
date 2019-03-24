#ifndef queue_h
#define queue_h

#include<stdio.h>
#include<Windows.h>
#include<assert.h>
typedef int QDataType;

typedef struct QueueNode
{
	QDataType _data;
	struct QueueNode* _next;
}QueueNode;

typedef struct Queue
{
	QueueNode* _head;
	QueueNode* _tail;
}Queue;

void QueueInit(Queue* q);
QueueNode*BuyQueueNode(Queue*q, QDataType x);
void QueuePush(Queue* q, QDataType x);
void QueuePrint(Queue*q);
void QueuePop(Queue* q);
QDataType QueueFront(Queue* q);
QDataType QueueBack(Queue* q);
size_t QueueSize(Queue* q);
int QueueEmpty(Queue* q);


QueueNode* BuyQueueNode(Queue*q, QDataType x)
{
	QueueNode*newnode = (QueueNode*)malloc(sizeof(QueueNode));
	assert(newnode);

	newnode->_data = x;
	newnode->_next = NULL;

	return newnode;
}
void QueueInit(Queue* q)
{
	assert(q);
	q->_tail = NULL;
	q->_head = NULL;
}
void QueuePush(Queue* q, QDataType x)
{
	if (q->_head == NULL)
	{
		q->_head = q->_tail = BuyQueueNode(q, x);
	}
	else
	{
		q->_tail->_next = BuyQueueNode(q, x);
		q->_tail = q->_tail->_next;
	}
}
void QueuePrint(Queue*q)
{
	QueueNode*cur = q->_head;
	while (cur != q->_tail)
	{
		printf("%d ", cur->_data);
		cur = cur->_next;
	}
	printf("%d\n", q->_tail->_data);
}
void QueuePop(Queue* q)
{
	QueueNode*next = q->_head->_next;
	if (q->_head == NULL)
		return;
	else
	{
		free(q->_head);
		q->_head = next;
		if (q->_head == NULL)
			q->_tail = NULL;
	}
}
QDataType QueueFront(Queue* q)
{
	assert(q&&q->_head != NULL);
		return q->_head->_data;
}
QDataType QueueBack(Queue* q)
{
	assert(q&&q->_tail != NULL);
		return q->_tail->_data;
}
size_t QueueSize(Queue* q)
{
	if (q->_head == NULL)
		return 0;
	else{
		QueueNode*cur = q->_head;
		int count = 1;
		while (cur != q->_tail)
		{
			count++;
			cur = cur->_next;
		}
		return count;
	}
}
int QueueEmpty(Queue* q)
{
	if (q->_head == NULL)
		return 0;
	else
		return 1;
}

#endif