//源.c

#include"Seqlist.h"

void SeqPrint(SeqList*pSeq)
{
	printf("输出的顺序表有%d个元素\n", pSeq->size);
	for (size_t i = 0; i<pSeq->size; i++)
	{
		printf("%d ", pSeq->a[i]);
	}
	printf("\n");
}
void SeqInit(SeqList* pSeq,size_t capacity)
{
	assert(pSeq&&capacity>0);
	pSeq->a = (DataType*)malloc(capacity*sizeof(DataType));
	assert(pSeq->a);

	pSeq->capacity = capacity;
	pSeq->size = 0;
}

void checkcapa(SeqList*pSeq)
{
	if (pSeq->size >= pSeq->capacity)
	{
		DataType*a = (DataType*)realloc(pSeq, sizeof(DataType)* 2 * pSeq->capacity);
		assert(a);
		pSeq->a = a;
		pSeq->capacity *= 2;
	}
}
void SeqPushBack(SeqList* pSeq, DataType x)
{
	
	assert(pSeq);
	
	checkcapa(pSeq);
	pSeq->a[pSeq->size] = x;
	pSeq->size++;

}
void SeqPopBack(SeqList* pSeq)
{
	assert(pSeq);
	pSeq->a[pSeq->size - 1] = 0;
	pSeq->size--;
}
void SeqPushFront(SeqList* pSeq, DataType x)
{
	assert(pSeq);
	checkcapa(pSeq);
	for (size_t i =pSeq->size; i >0; i--)
	{
		pSeq->a[i] = pSeq->a[i-1]; 
	}
	pSeq->a[0] = x;
	pSeq->size++;
}
void SeqPopFront(SeqList* pSeq)
{
	size_t tmp=1;
	assert(pSeq);
	while (tmp<pSeq->size)
	{
		pSeq->a[tmp -1] = pSeq->a[tmp];
		tmp++;
	}
	pSeq->size--;
}
void SeqDestory(SeqList* pSeq)
{
	assert(pSeq);
	free(pSeq->a);
	pSeq->a = NULL;
	pSeq->size = pSeq->capacity = 0;
}

void SeqInsert(SeqList* pSeq, size_t pos, DataType x)//pos后插入x
{
	assert(pSeq);
	assert(pos < pSeq->size);
	checkcapa(pSeq);

	for (size_t i = pSeq->size - 1; i>pos; i--)
	{
		pSeq->a[i + 1] = pSeq->a[i];
	}
	pSeq->a[pos + 1] = x;
	pSeq->size++;
}
void SeqErase(SeqList* pSeq, size_t pos)//删除pos位置的元素
{
	assert(pSeq&&pos<pSeq->size);
	for (size_t i = pos; i < pSeq->size; i++)
	{
		pSeq->a[i - 1] = pSeq->a[i];
	}
	pSeq->size--;
}
int SeqFind(SeqList* pSeq, DataType x)//在顺序表中找x
{
	size_t i = 0;
	assert(pSeq);
	while (i < pSeq->size)
	{
		if (pSeq->a[i] == x)
			return x;
		i++;
	}
	return -1;
}
void SeqAt(SeqList* pSeq, size_t pos, DataType x)//修改pos位置的数据
{
	assert(pSeq&&pos<pSeq->size);
	pSeq->a[pos] = x;
}
void Swap(DataType* a, DataType* b)
{
	*a ^=* b;
	*b ^= *a;
	*a ^= *b;
}
void BubbleSort(SeqList* pSeq)//冒泡排序
{
	assert(pSeq);
	for (size_t i = 0; i < pSeq->size - 1; i++)
	{
		int flag = 0;
		for (size_t j = 0; j < pSeq->size - i - 1; j++)
		{
			if (pSeq->a[j]>pSeq->a[j + 1])
			{
				Swap(&pSeq->a[j], &pSeq->a[j + 1]);
				flag = 1;
			}
		}
		if (flag == 0)
			break;
	}
}	
void SelectSort(SeqList* pSeq)
{
	size_t left = 0, right = pSeq->size-1;
	while (left < right)
	{
		size_t max=left, min=left;
		size_t i = left;
		while (i <= right)
		{
			if (pSeq->a[i] > pSeq->a[max])
				max = i;

			if (pSeq->a[i] < pSeq->a[min])
				min = i;

			++i;
		}
		
		Swap(&pSeq->a[left], &pSeq->a[min]);
		if (left == max)
			max = min;

		Swap(&pSeq->a[right], &pSeq->a[max]);
		if (right==min)
			min=max;
		++left;
		--right;
	}
}




int BinarySearch(SeqList* pSeq,DataType x)//二分查找
{
	assert(pSeq);
	size_t head = 0, tail = pSeq->size - 1;
	if (x == pSeq->a[head])
		return pSeq->a[head];
	else if (x == pSeq->a[tail])
		return pSeq->a[tail];
	else
	{
		size_t mid = head + ((tail - head) >> 1);
		if (x < pSeq->a[mid])
			tail = mid - 1;
		else if (x>pSeq->a[mid])
			head = mid + 1;
		else
			return pSeq->a[mid];
	}
	return -1;
}
void test1()
{
	SeqList s;
	SeqInit(&s, 20);
	SeqPushBack(&s, 0);
	SeqPushBack(&s, 1);
	SeqPushBack(&s, 2);
	SeqPushBack(&s, 3);
	SeqPushBack(&s, 4);
	SeqErase(&s, 0);
	SeqPopBack(&s);
	SeqPopBack(&s);
	SeqInsert(&s, 0, 9);
	SeqPrint(&s);
}
void test2()
{
	SeqList s;
	SeqInit(&s, 20);
	SeqPushBack(&s, 0);
	SeqPushBack(&s, 1);
	SeqPushBack(&s, 2);
	SeqPushFront(&s, 10);
	SeqPushFront(&s, 20);
	SeqPushFront(&s, 30);
	SeqAt(&s,0,50);
	SeqPrint(&s);
}
void test3()
{
	SeqList s;
	SeqInit(&s, 20);
	SeqPushBack(&s, 0);
	SeqPushBack(&s, 1);
	SeqPushBack(&s, 2);
	SeqPushBack(&s, 3);
	SeqPopFront(&s);
	SeqPopFront(&s);
	SeqPrint(&s);
}

void test4()
{
	SeqList s;
	SeqInit(&s, 20);
	SeqPushBack(&s, 0);
	SeqPushBack(&s, 1);
	printf("%d\n", SeqFind(&s, 0));
	printf("%d\n", SeqFind(&s, 1));
	printf("%d\n", SeqFind(&s, 2));
}

void test5()
{
	SeqList s;
	SeqInit(&s, 20);
	SeqPushBack(&s, 10);
	SeqPushBack(&s, 1);
	SeqPushBack(&s, 5);
	SeqPushBack(&s, 3);
	SeqPushBack(&s, 99);
	SeqPrint(&s);
	printf("%d\n", BinarySearch(&s, 5));
	printf("%d\n", BinarySearch(&s, 2));
	SeqPrint(&s);
	//BubbleSort(&s);
	SelectSort(&s);
	SeqPrint(&s);
}
int main()
{
	test1();
	//test2();
	//test3();
	//test4();
	//test5();
	system("pause");
	return 0;
}