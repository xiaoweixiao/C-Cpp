typedef int DataType;

typedef struct DlistNode
{
	struct DlistNode* _next;
	struct DlistNode* _prev;
	DataType _data;
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

void DListPrint(DlistNode* head)
DlistNode* DListInit();

void TestDList1()
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
	DListPopBack(list);
	DListPopBack(list);
	DListPopBack(list);
	DListPrint(list);
}

void TestDList2()
{
	DlistNode* list = DListInit();
	DListPushFront(list, 1);
	DListPushFront(list, 2);
	DListPushFront(list, 3);
	DListPushFront(list, 4);
	DListPushFront(list, 5);
	DListPrint(list);

	DListPopFront(list);
	DListPopFront(list);
	DListPopFront(list);
	DListPopFront(list);
	DListPopFront(list);
	DListPrint(list);
}