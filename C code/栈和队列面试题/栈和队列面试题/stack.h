#ifndef stack_h
#define stack_h

#include<stdio.h>
#include<Windows.h>
#include<malloc.h>
#include<assert.h>


typedef int SDataType;

typedef struct Stack
{
	SDataType* _array;
	size_t _top; //栈顶 
	size_t _end;
}Stack;

// 栈的实现接口 
void StackInit(Stack* s,size_t end);
void StackPush(Stack* s, SDataType x);
void StackPop(Stack* s);
SDataType StackTop(Stack* s);
size_t StackSize(Stack* s);
int StackEmpty(Stack* s);


void StackInit(Stack* s,size_t end)
{
	assert(s&&end);
	s->_array =(SDataType*)malloc(end*sizeof(SDataType));
	assert(s->_array);
	s->_end = end;
	s->_top = 0;
}
void CheckStack(Stack*s)
{
	assert(s);
	if (s->_top >= s->_end)
	{
		s->_array = (SDataType*)realloc(s, 2 * s->_end*sizeof(SDataType));
		s->_end = s->_end * 2;
	}
}
void StackPush(Stack* s, SDataType x)
{
	assert(s);
	CheckStack(s);
	s->_array[s->_top] = x;
	s->_top++;
}
void StackPrint(Stack* s)
{
	for (size_t n = 0; n < s->_top; n++)
	{
		printf("%d ", s->_array[n]);
	}
}
void StackPop(Stack* s)
{
	s->_array[s->_top-1]=0;
	s->_top--;
}
SDataType StackTop(Stack* s)
{
	return s->_array[s->_top-1];
}
size_t StackSize(Stack* s)
{
	return s->_top;
}
int StackEmpty(Stack* s)
{
	if (s->_top == 0)
		return 0;
	else
		return 1;
}
#endif


