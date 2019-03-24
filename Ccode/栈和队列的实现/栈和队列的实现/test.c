//#include"stack.h"
//
//void test();
//
//void test()
//{
//	Stack s;
//	StackInit(&s,30);
//	StackPush(&s, 0);
//	StackPush(&s, 1);
//	StackPush(&s, 2);
//	StackPush(&s, 3);
//	StackPush(&s, 4);
//	StackPrint(&s);
//	printf("\n");
//	printf("%d\n",StackEmpty(&s));
//	printf("%d\n", StackSize(&s));
//	printf("%d\n", StackTop(&s));
//}
//int main()
//{
//	test();
//	system("pause");
//	return 0;
//}

#include"queue.h"


void test()
{
	Queue q;
	QueueInit(&q);
	QueuePush(&q, 1);
	QueuePush(&q, 2);
	QueuePush(&q, 3);
	QueuePush(&q, 4);
	QueuePop(&q);
	QueuePrint(&q);
	printf("size:%d\n", QueueSize(&q));
}
int main()
{
	test();
	system("pause");
	return 0;
}