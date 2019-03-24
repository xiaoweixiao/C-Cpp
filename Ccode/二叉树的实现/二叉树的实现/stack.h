#include<stdio.h>
#include<Windows.h>
#include<assert.h>

typedef BTNode* DataType;

typedef struct Stack
{
	DataType* _array;
	size_t _top; //栈顶 
	size_t _end;
}Stack;

// 栈的实现接口 
void StackInit(Stack*s,size_t top);
void StackPush(Stack* s, DataType x);
void StackPop(Stack* s);
DataType StackTop(Stack* s);
size_t StackSize(Stack* s);
int StackEmpty(Stack* s);
void Stackcheck(Stack*s);
void StackPrint(Stack*s);

void StackPrint(Stack*s)
{
	size_t i = 0;
	while (i < s->_top)
	{
		printf("%d ", s->_array[i]);
		i++;
	}
}
void Stackcheck(Stack*s)
{
	if (s->_top >= s->_end)
	{
		DataType*array = (DataType*)realloc(s,sizeof(DataType)*2);
		assert(array);
		s->_array = array;
		s->_end = s->_end * 2;
	}
}
void StackInit(Stack*s,size_t end)
{
	assert(s&&end > 0);
	s->_array = (DataType*)malloc(end*sizeof(DataType));
	assert(s->_array);

	s->_top = 0;
	s->_end = end;
}

void StackPush(Stack* s, DataType x)
{
	Stackcheck(s);
	s->_array[s->_top] = x;
	s->_top++;
}

void StackPop(Stack* s)
{
	s->_array[s->_top - 1] = 0;
	s->_top--;
}

DataType StackTop(Stack* s)
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

