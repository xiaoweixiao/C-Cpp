#include<stdio.h>
#include<Windows.h>
#include<assert.h>
#include<stdlib.h>

typedef int HeapDataType;

typedef struct Heap
{
	HeapDataType* _a;
	size_t _size;
	size_t _capacity;
}Heap;

void HeapInit(Heap* hp, HeapDataType* a, size_t n);
void HeapMake(Heap* hp);
void HeapPush(Heap* hp, HeapDataType x);
void HeapPop(Heap* hp);
size_t HeapSize1(Heap* hp);
size_t HeapEmpty(Heap* hp);
HeapDataType HeapTop(Heap* hp);
void HeapSort(Heap* hp);
void HeapAdjustDown(Heap* hp, int root);
void HeapAdjustUp(Heap* hp, int child);

void Swap(HeapDataType*a, HeapDataType*b)
{
	HeapDataType tmp = *a;
	*a = *b;
	*b = tmp;
}
void HeapAdjustDown(Heap* hp, int root)//小堆
{
	assert(hp);
	int parent = root;
	int child = parent * 2 + 1;
	while (child<(int)hp->_size&&child>0)
	{
		if (child + 1 < (int)hp->_size && hp->_a[child] > hp->_a[child + 1])
			child++;
		if (hp->_a[parent] > hp->_a[child])
		{
			Swap(&hp->_a[child],&hp->_a[parent]);

			parent = child;
			child = parent * 2 + 1;
		}
		else
			break;
	}
}
void HeapAdjustUp(Heap* hp, int child)//小堆
{
	int parent = (child - 1) >> 1;
	while (child > 0)
	{
		if (hp->_a[child] < hp->_a[parent])
		{
			Swap(&hp->_a[child], &hp->_a[parent]);

			child = parent;
			parent = (child - 1) >> 1;
		}
		else
			break;
	}
}
void HeapInit(Heap* hp, HeapDataType* a, size_t n)
{
	assert(hp&&a);
	hp->_capacity = 30;
	hp->_size = 0;
	hp->_a = (HeapDataType*)malloc(hp->_capacity*sizeof(HeapDataType));
	assert(hp->_a);
	for (size_t i = 0; i < n; i++)
	{
		hp->_a[i] = a[i];
		hp->_size++;
	}
}
void HeapMake(Heap* hp)//建小堆
{
	assert(hp);

	for (int i = (hp->_size-2)>>1; i>=0; i--)//(hp->_size-2)>>1是最后一个非叶子结点
	{
		HeapAdjustDown(hp, i);
	}
}
void HeapPush(Heap* hp, HeapDataType x)
{
	assert(hp);
	if (hp->_size == hp->_capacity)
	{
		hp->_capacity *= 2;
		hp->_a = (HeapDataType*)realloc(hp->_a, hp->_capacity*sizeof(HeapDataType));
		assert(hp->_a);
	}

	hp->_a[hp->_size] = x;
	hp->_size++;
	HeapAdjustUp(hp, hp->_size - 1);
}
void HeapPop(Heap* hp)
{
	assert(hp);

	Swap(&hp->_a[0], &hp->_a[hp->_size - 1]);
	hp->_size--;
	HeapAdjustDown(hp, 0);
}
size_t HeapSize1(Heap* hp)
{
	assert(hp);
	return hp->_size;
}
size_t HeapEmpty(Heap* hp)
{
	assert(hp);
	if (hp->_size == 0)
		return 0;
	else
		return 1;
}
HeapDataType HeapTop(Heap* hp)
{
	assert(hp);
	return hp->_a[0];
}
void HeapSort(Heap* hp)//排序
{
	assert(hp);
	int n = hp->_size;
	HeapMake(hp);


	while (HeapEmpty(hp))
	{
		HeapPop(hp);
	}
	hp->_size = n;
}
//最大的前K个数
void HeapTopK(int*a, int n, int k)
{
	Heap hp;
	HeapInit(&hp, a, k);
	HeapMake(&hp);

	for (int i = k; i < n; i++)
	{
		if (a[i]>(&hp)->_a[0])
		{
			(&hp)->_a[0] = a[i];
			HeapAdjustDown(&hp, 0);
		}
	}
	for (int i = 0; i < k; i++)
		printf("%d ", (&hp)->_a[i]);
}