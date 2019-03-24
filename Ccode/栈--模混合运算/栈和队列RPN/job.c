//typedef enum RPN_TYPE
//{
//	OP_NUM,
//	OP_SYMBOL,
//	OP_ADD,
//	OP_SUB,
//	OP_MUL,
//	OP_DIV,
//}RPN_TYPE;
//
//typedef struct Cell
//{
//	RPN_TYPE _type;
//	int value;
//}Cell;
//
//int CountRPN(Cell* rpn, size_t n);




#include"RPN.h"


void test()
{
	int n = 0;
	Cell rpn[] = {
		{ OP_NUM, 38 },
		{ OP_NUM, 6 },
		{ OP_NUM, 4 },
		{ OP_SYMBOL, OP_MUL },
		{ OP_SYMBOL, OP_ADD },
		{ OP_NUM, 25 },
		{ OP_SYMBOL, OP_SUB },

	};
	n = sizeof(rpn) / sizeof(rpn[0]);
	printf("¼ÆËã½á¹û£º%d\n", CountRPN(rpn, n));

}
int main()
{
	test();
	system("pause");
	return 0;
}