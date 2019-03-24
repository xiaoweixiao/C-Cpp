
#include"stack.h"
#include"queue.h"
//ʵ��һ��ջ��Ҫ��ʵ��Push(��ջ)��Pop(��ջ)��Min(������Сֵ)��ʱ��
//���Ӷ�ΪO(1)
typedef struct MinStack
{
	Stack _data;
	Stack _min;
}MinStack;

void InitMinStack(MinStack*ms, size_t end);
void MinStackPush(MinStack*ms, SDataType x);
void MinStackPop(MinStack*ms);
SDataType Minstackmin(MinStack*s);
int MinStackEmpty(MinStack*ms);
SDataType MinStackTop(MinStack*ms);

SDataType MinStackTop(MinStack*ms)
{
	return StackTop(&(ms->_data));
}

void InitMinStack(MinStack*ms,size_t end)
{
	assert(ms);
	StackInit(&(ms->_data), end);
	StackInit(&(ms->_min), end);
}

void MinStackPush(MinStack*ms, SDataType x)
{
	CheckStack(&(ms->_data));
	CheckStack(&(ms->_min));
	
	StackPush(&(ms->_data), x);
	if ((StackEmpty(&(ms->_min))) == 0
		|| (StackTop(&(ms->_min))> x))
	{
		StackPush(&(ms->_min),x);
	}
}

void MinStackPop(MinStack*s)
{
	assert(s);
	if (StackTop(&(s->_min)) == StackTop(&(s->_data)))
		StackPop(&(s->_min));

	StackPop(&(s->_data));
}

SDataType Minstackmin(MinStack*s)
{
	assert(s);
	return StackTop(&(s->_min));
}

int MinStackEmpty(MinStack*ms)
{
	if ((&(ms->_data))->_top == 0)
		return 0;
	else
		return 1;
}

//ʹ������ջʵ��һ������
typedef struct QueueByTwoStack{
	Stack _s1;
	Stack _s2;
}QueueByTwoStack;

void QueueByTwoStackInit(QueueByTwoStack*q);
void QueueByTwoStackPush(QueueByTwoStack*q, QDataType x);
void QueueByTwoStackPop(QueueByTwoStack*q);
int QueueByTwoStackEmpty(QueueByTwoStack*q);
QDataType QueueTwoStackFront(QueueByTwoStack*q);

void QueueByTwoStackInit(QueueByTwoStack*q)
{
	assert(q);
	StackInit(&(q->_s1), 10);
	StackInit(&(q->_s2), 10);
}
void QueueByTwoStackPush(QueueByTwoStack*q,QDataType x)
{
	assert(q);

	StackPush(&(q->_s1), x);
}
void QueueByTwoStackPop(QueueByTwoStack*q)
{
	if ((StackEmpty(&(q->_s2))) == 0){
		while (StackEmpty(&(q->_s1))){
			StackPush(&(q->_s2), StackTop(&(q->_s1)));
			StackPop(&(q->_s1));
		}
	}
	StackPop(&(q->_s2));
}
int QueueByTwoStackEmpty(QueueByTwoStack*q)
{
	return StackEmpty(&(q->_s1)) + StackEmpty(&(q->_s2));
}
QDataType QueueTwoStackFront(QueueByTwoStack*q)
{
	if (StackEmpty(&(q->_s2)) == 0)
	{
		while (StackEmpty(&(q->_s1)))
		{
			StackPush(&(q->_s2), StackTop(&(q->_s1)));
			StackPop(&(q->_s1));
		}
	}
	return StackTop(&(q->_s2));
}
//ʹ����������ʵ��һ��ջ
typedef struct StackByTwoQueue{
	Queue _q1;
	Queue _q2;
}StackByTwoQueue;

void StackByTwoQueueInit(StackByTwoQueue*s);
void StackByTwoQueuePush(StackByTwoQueue*s,SDataType x);
void StackByTwoQueuePop(StackByTwoQueue*s);
SDataType StackByTwoQueueTop(StackByTwoQueue*s);
int StackByTwoQueueEmpty(StackByTwoQueue*s);

void StackByTwoQueueInit(StackByTwoQueue*s)
{
	assert(s);
	QueueInit(&(s->_q1));
	QueueInit(&(s->_q2));
}
int StackByTwoQueueEmpty(StackByTwoQueue*s)
{
	return QueueEmpty(&(s->_q1)) + QueueEmpty(&(s->_q2));
}
void StackByTwoQueuePush(StackByTwoQueue*s, SDataType x)
{
	assert(s);
	if (QueueEmpty(&(s->_q1)))
	{
		QueuePush(&(s->_q1), x);
	}
	else
	{
		QueuePush(&(s->_q2), x);
	}	
}
int SizeStackByQueue(StackByTwoQueue* s)
{
	return QueueSize(&s->_q1) + QueueSize(&s->_q2);
}
void StackByTwoQueuePop(StackByTwoQueue*s)
{
	assert(s);

	if (QueueEmpty(&(s->_q1)))
	{
		while (QueueSize(&s->_q1)>1)
		{
			QueuePush(&(s->_q2), QueueFront(&(s->_q1)));
			QueuePop(&(s->_q1));
		}
		QueuePop(&(s->_q1));
	}
	else
	{
		while (QueueSize(&s->_q2)>1)
		{
			QueuePush(&(s->_q1), QueueFront(&(s->_q2)));
			QueuePop(&(s->_q2));
		}
		QueuePop(&(s->_q2));
	}
}
SDataType StackByTwoQueueTop(StackByTwoQueue*s)
{
	assert(s);
	if (QueueEmpty(&(s->_q2)))
		return QueueBack(&(s->_q2));
	else 
		return QueueBack(&(s->_q1));
}




//Ԫ�س�ջ����ջ˳��ĺϷ��ԡ�����ջ������(1, 2, 3, 4, 5)����ջ����Ϊ
//(4, 5, 3, 2, 1)
int IsInvalidStackOrder(int* in, int* out, int n);
int IsInvalidStackOrder(int* in, int* out, int n)
{
	int index = 0, outdex = 0;
	Stack s;
	StackInit(&s,30);

	while (index < n)
	{
		if (in[index] != out[outdex])
		{
			StackPush(&s, in[index]);
			index++;
		}
		else
		{
			index++;
			outdex++;
		}
		while (StackEmpty(&s) != 0&&StackTop(&s)==out[outdex])
		{
			outdex++;
			StackPop(&s);
		}
	}
	while (outdex < n)
	{
		if (StackTop(&s) != out[outdex])
			return -1;
		else
		{
			outdex++;
			StackPop(&s);
		}
	}
	return 0;
}

//һ������ʵ������ջ(����ջ)
typedef struct TwoStack{
	SDataType* _a;
	size_t _top1;
	size_t _top2;
	size_t _capacity;
}TwoStack;
void TwoStackInit(TwoStack* s, size_t capacity);
void TwoStackPush(TwoStack* s, SDataType x, int which);
void TwoStackPop(TwoStack* s, int which);
int TwoStackSize(TwoStack* s, int which);
int TwoStackEmpty(TwoStack* s, int which);
SDataType TwoStackTop(TwoStack* s, int which);

void TwoStackInit(TwoStack* s, size_t capacity)
{
	s->_a = (SDataType*)malloc(capacity*sizeof(SDataType));
	assert(s->_a);
	
	s->_capacity = capacity;
	s->_top1 = 0;
	s->_top2 = capacity - 1;
}
void CheckTwoStackcapacity(TwoStack*s)
{
	if (s->_top2 - s->_top1 == 1)
	{
		SDataType*_a = (SDataType*)malloc(2 * s->_capacity*sizeof(SDataType));
		assert(_a);

		for (size_t i = 0; i < s->_top1; i++)
		{
			_a[i] = s->_a[i];
		}
		for (size_t i = s->_capacity - 1; i>s->_top2; i--)
		{
			for (size_t j = 2 * s->_capacity - 1; j > s->_top2; j--)
				_a[j] = s->_a[i];
		}
		s->_a = _a;
		s->_top2 = s->_top2 + s->_capacity;
		s->_capacity = 2 * s->_capacity;
	}
}
void TwoStackPush(TwoStack* s, SDataType x, int which)
{
	assert(s);
	CheckTwoStackcapacity(s);
	if (which == 1)
	{
		s->_a[s->_top1] = x;
		s->_top1++;
	}
	else if (which == 2)
	{
		s->_a[s->_top2] = x;
		s->_top2--;
	}
	else
		assert(0);
}
void TwoStackPop(TwoStack* s, int which)
{
	if (which == 1)
	{
		s->_top1--;
	}
	else if (which == 2)
	{
		s->_top2++;
	}
	else
		assert(0);
}
int TwoStackSize(TwoStack* s, int which)
{
	if (which == 1)
		return s->_top1 + 1;
	else if (which == 2)
		return s->_capacity - s->_top2;
	else
		return 0;
}
int TwoStackEmpty(TwoStack* s, int which)
{
	if (TwoStackSize(s, which) > 0)
		return 1;
	else
		return 0;
}
SDataType TwoStackTop(TwoStack* s, int which)
{
	if (which == 1)
		return s->_a[s->_top1 - 1];
	else if (which == 2)
		return s->_a[s->_top2 + 1];
	else
		return 0;
}
