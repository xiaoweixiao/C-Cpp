#include<stdio.h>
#include<assert.h>
#include<Windows.h>
#include<stdlib.h>


typedef int KeyType;
typedef int ValueType;

typedef struct HashNode{
	KeyType _key;
	ValueType _value;
	struct HashNode* _next;
}HashNode;

typedef struct HashTable{
	HashNode** _array;
	size_t _size;
	size_t _capacity;
}HashTable;

size_t HashFunc(KeyType key, size_t capacity);
size_t GetNextPrimeNum(size_t cur);
void HashInit(HashTable*ht, size_t capacity);
int HashInsert(HashTable*ht, KeyType key,ValueType value);
int HashRemove(HashTable*ht, KeyType key);
HashNode* HashFind(HashTable*ht, KeyType key);
void HashDectory(HashTable*ht);


size_t HashFunc(KeyType key, size_t capacity)
{
	return key%capacity;
}
size_t GetNextPrimeNum(size_t cur)
{
	const int _Primesize = 28;
	static const unsigned long _PrimeList[28]={

		53ul, 97ul, 193ul, 389ul, 769ul,
		1543ul, 3079ul, 6151ul, 12289ul, 24593ul,
		49157ul, 98317ul, 196613ul, 393241ul, 786433ul,
		1572869ul, 3145739ul, 6291469ul, 12582917ul, 25165843ul,
		50331653ul, 100663319ul, 201326611ul, 402653189ul, 805306457ul,
		1610612741ul, 3221225473ul, 4294967291ul
	};
	for (int i = 0; i < _Primesize; ++i)
	{
		if (_PrimeList[i]>cur)
			return _PrimeList[i];
	}
	return _PrimeList[_Primesize];
}
void HashInit(HashTable*ht, size_t capacity)
{
	assert(ht);
	ht->_array = (HashNode**)malloc(capacity*sizeof(HashNode*));
	assert(ht->_array);

	ht->_capacity = capacity;
	ht->_size = 0;
	for (size_t i = 0; i < ht->_capacity; ++i)
	{
		ht->_array[i] = NULL;
	}
}
void HashDectory(HashTable*ht)
{
	for (size_t i = 0; i < ht->_capacity; ++i)
	{
		HashNode*cur = ht->_array[i];
		while (cur)
		{
			HashNode* next = cur->_next;
			free(cur);
			cur = next;
		}
	}
	free(ht->_array);
	ht->_array = NULL;
	ht->_capacity = ht->_size = 0;
}

void CheckCapacity(HashTable*ht)
{
	//建新的哈希表用HashInsert()把原哈希表里的结点一一插入，再销毁原哈希表
	//缺点 需要重新一一构建结点，而原来的结点还要被释放掉，不划算
	/*if (ht->_size == ht->_capacity)
	{
		HashTable newht;
		HashInit(&newht, GetNextPrimeNum(ht->_capacity));
		for (size_t i = 0; i < ht->_capacity; ++i)
		{
			HashNode*cur = ht->_array[i];
			while (cur)
			{
				HashInsert(&newht, ht->_array[i]->_key, ht->_array[i]->_value);
				cur = cur->_next;
			}
		}
		HashDectory(ht);

		ht->_array = newht._array;
		ht->_capacity = newht._capacity;
		ht->_size = newht._size;
	}*/


	//改进方法，拿原来的结点直接来链到新的哈希表中
	if (ht->_size == ht->_capacity)
	{
		HashTable newht;
		HashInit(&newht, GetNextPrimeNum(ht->_capacity));
		for (size_t i = 0; i < ht->_capacity; ++i)
		{
			HashNode*cur = ht->_array[i];
			while (cur)
			{
				HashNode* next = cur->_next;
				size_t index=HashFunc(cur->_key, newht._capacity);

				cur->_next = newht._array[index];
				newht._array[index] = cur;

				cur = next;
			}
			ht->_array[i] = NULL;
		}
		HashDectory(ht);
		ht->_array = newht._array;
		ht->_capacity = newht._capacity;
		ht->_size = newht._size;
	}
}
int HashInsert(HashTable*ht, KeyType key, ValueType value)
{
	CheckCapacity(ht);
	size_t index = HashFunc(key, ht->_capacity);
	HashNode* cur = ht->_array[index];
	while (cur)
	{
		if (cur->_key == key)
			return -1;
		cur = cur->_next;
	}
	HashNode* newnode = (HashNode*)malloc(sizeof(HashNode));
	assert(newnode);
	newnode->_key = key;
	newnode->_value=value;

	newnode->_next = ht->_array[index];
	ht->_array[index] = newnode;

	ht->_size++;
	return 0;
}
int HashRemove(HashTable*ht, KeyType key)
{
	size_t index = HashFunc(key, ht->_capacity);
	HashNode*prev = ht->_array[index];
	HashNode*cur = prev->_next;
	if (prev->_key == key)
	{
		free(prev);

		ht->_array[index] = cur;
		return 0;
	}
	else
	{
		while (cur)
		{
			if (cur->_key == key)
			{
				prev->_next = cur->_next;
				free(cur);
				return 0;
			}
			cur = cur->_next;
			prev = cur;
		}
	}
	return -1;
}
HashNode* HashFind(HashTable*ht, KeyType key)
{
	size_t index = HashFunc(key, ht->_capacity);
	HashNode*cur = ht->_array[index];
	while (cur)
	{
		if (key == cur->_key)
			return cur;
		cur = cur->_next;
	}
	return NULL;
}
