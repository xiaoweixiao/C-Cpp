#ifndef RPN_h
#define RPN_h

#include"stack.h"

typedef enum RPN_TYPE
{
	OP_NUM,
	OP_SYMBOL,
	OP_ADD,
	OP_SUB,
	OP_MUL,
	OP_DIV,
}RPN_TYPE;

typedef struct Cell
{
	RPN_TYPE _type;
	int value;
}Cell;

int CountRPN(Cell *rpn, size_t n)//¼ÆËãº¯Êý
{
	assert(rpn);
	Stack s;
	StackInit(&s, 30);
	for (size_t i = 0; i < n; i++)
	{
		if (rpn[i]._type == OP_NUM)
			StackPush(&s, rpn[i].value);
		else
		{
			int right = 0, left = 0;
			right = StackTop(&s);
			StackPop(&s);
			left = StackTop(&s);
			StackPop(&s);
			switch (rpn[i].value)
			{
			case OP_ADD:
				StackPush(&s, left + right);
				break;
			case OP_SUB:
				StackPush(&s, left - right);
				break;
			case OP_MUL:
				StackPush(&s, left * right);
				break;
			case OP_DIV:
				StackPush(&s, left / right);
				break;
			default:
				printf("ÊäÈë´íÎó£¡");
				break;
			}
		}
	}
	return StackTop(&s);
}
#endif