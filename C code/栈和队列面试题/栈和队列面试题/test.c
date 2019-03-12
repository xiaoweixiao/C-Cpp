#include"test.h"
#include"stack.h"
void MinStackTest()
{
	MinStack s;
	InitMinStack(&s,30);
	MinStackPush(&s, 98);
	MinStackPush(&s, 12); 
	MinStackPush(&s, 32);
	MinStackPush(&s, 37);
	MinStackPush(&s, 45);
	while (MinStackEmpty(&s))
	{
		SDataType top = MinStackTop(&s);
		SDataType min = Minstackmin(&s);
		printf("top:%d min:%d\n ", top, min);
		MinStackPop(&s);
	}	
}

void QueueByTwoStackTest()
{
	QueueByTwoStack s;
	QueueByTwoStackInit(&s);
	QueueByTwoStackPush(&s, 1);
	QueueByTwoStackPush(&s, 2);
	QueueByTwoStackPush(&s, 3);
	QueueByTwoStackPush(&s, 4);
	QueueByTwoStackPush(&s, 5);

	while (QueueByTwoStackEmpty(&s))
	{
		printf("%d ", QueueTwoStackFront(&s));
		QueueByTwoStackPop(&s);
	}
}

void TwoStackTest()
{
	TwoStack s;
	TwoStack*ps = &s;
	TwoStackInit(&s, 3);

	TwoStackPush(&s, 20, 1);
	TwoStackPush(&s, 30, 2);
	TwoStackPush(&s, 40, 1);
	TwoStackPush(&s, 60, 1);
	TwoStackPush(&s, 80, 2);
	for (size_t i = 0; i < ps->_top1; i++)
		printf("%d ", ps->_a[i]);
	for (size_t i = ps->_top2 + 1; i < ps->_capacity; i++)
		printf("%d ", ps->_a[i]);
	printf("\n");
	TwoStackPop(ps, 1);
	TwoStackPop(ps, 2);
	for (size_t i = 0; i < ps->_top1; i++)
		printf("%d ", ps->_a[i]);
	for (size_t i = ps->_top2 + 1; i < ps->_capacity; i++)
		printf("%d ", ps->_a[i]);
}
void TestIsInvalidStackOrder()
{
	int in[5] = { 1, 2, 3, 4, 5 };
	int out[5] = { 4, 5, 3, 2, 1 };
	printf("ºÏ·¨ÐÔ£º%d\n", IsInvalidStackOrder(in, out, sizeof(in) / sizeof(int)));
}
void TestStackByTwoQueue()
{
	StackByTwoQueue s;
	StackByTwoQueueInit(&s);

	StackByTwoQueuePush(&s, 1);
	StackByTwoQueuePush(&s, 2);
	StackByTwoQueuePush(&s, 3);
	StackByTwoQueuePush(&s, 4);
	StackByTwoQueuePush(&s, 5);
	printf("size = %d\n", SizeStackByQueue(&s));
	printf("top = %d\n", StackByTwoQueueTop(&s));
	while (StackByTwoQueueEmpty(&s)!=0)
	{
		printf("%d ", StackByTwoQueueTop(&s));
		StackByTwoQueuePop(&s);
	}
}
int main()
{
	//MinStackTest();
	//QueueByTwoStackTest();
	TwoStackTest();
	//TestIsInvalidStackOrder();
	//TestStackByTwoQueue();
	system("pause");
	return 0;
}