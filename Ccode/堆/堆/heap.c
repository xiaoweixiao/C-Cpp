#include"heap.h"


void HeapPrint(Heap*hp)
{
	for (size_t i = 0; i < hp->_size; i++)
	{
		printf("%d ", hp->_a[i]);
	}
	printf("\n");
}
void TestHeap()
{
	int a[9] = { 99, 88, 777, 66, 5, 44, 3, 1, 2 };
	Heap hp;
	HeapInit(&hp, a, sizeof(a) /sizeof(int));
	//HeapPrint(&hp);
	HeapMake(&hp);
	//HeapPrint(&hp);
	//HeapPush(&hp, 4);
	//HeapPrint(&hp);
	//HeapPop(&hp);
	//HeapPrint(&hp);
	//HeapSort(&hp);
	//HeapPrint(&hp);

	HeapTopK(&hp, sizeof(a) / sizeof(int), 5);
}
int main()
{
	TestHeap();
	system("pause");
	return 0;
}