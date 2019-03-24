#include"hash.h"
#include<stdio.h>
#include<time.h>


void HashPrint(HashTable*ht)
{
	for (size_t i = 0; i < ht->_capacity; ++i)
	{
		HashNode*cur = ht->_array[i];
		while (cur)
		{
			printf("%d->", cur->_key);
			cur = cur->_next;
		}
		printf("NULL\n");
	}
}
void Test2()
{
	HashTable ht;
	HashInit(&ht,53);
	HashInsert(&ht, 11, 595);
	HashInsert(&ht, 64, 595);
	HashInsert(&ht, 65, 595);
	HashPrint(&ht);

	printf("\n\n\n");
	srand((unsigned int)time(0));
	for (size_t i = 0; i < 99; ++i)
	{
		HashInsert(&ht, rand(), i);
	}
	HashPrint(&ht);
	HashNode*del=HashFind(&ht, 11);
	printf("del:%d\n", del->_key);
	HashRemove(&ht, 11);
	HashPrint(&ht);
}
int main()
{
	Test2();
	system("pause");
	return 0;
}
