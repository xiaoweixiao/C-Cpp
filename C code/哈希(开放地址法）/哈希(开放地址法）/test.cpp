#include"hash.h"
#include<stdlib.h>
#include<time.h>

void HashTablePrint(HashTable*ht)
{
	for (int i = 0; i <(int)ht->_capacity; i++)
	{
		if (ht->_tables[i]._status == _EXITS)
			printf("EX:%d %d ", ht->_tables[i]._key, ht->_tables[i]._value);
		else if (ht->_tables[i]._status == _DELETE)
			printf("DEL:%d %d ", ht->_tables[i]._key, ht->_tables[i]._value);
		else
			printf("EM:       ");
		if (i>0 && i % 10 == 0)
			printf("\n");
	}
}
void TestHash()
{
	HashTable ht;
	HashTableInit(&ht,0);

	HashTableInsert(&ht, 4, 104);
	HashTableInsert(&ht, 5, 105);
	HashTableInsert(&ht, 7, 107);
	HashTableInsert(&ht, 6, 106);
	HashTableInsert(&ht, 32, 106);
	HashTableInsert(&ht, 58, 106);

	printf("%p \n", HashTableFind(&ht, 4)->_value);
	printf("%p \n", HashTableFind(&ht, 7)->_value);

	printf("%\n\n");
	HashTableRemove(&ht, 32);

	srand((unsigned)time(0));
	for (int i = 0; i < 53; ++i)
	{
		HashTableInsert(&ht, rand(),i);
	}
	HashTablePrint(&ht);
	HashTableDestory(&ht);
}


int main()
{
	TestHash();
	system("pause");
	return 0;
}