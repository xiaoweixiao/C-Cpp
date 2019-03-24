#pragma once
#include<stdio.h>
#include<assert.h>
#include<Windows.h>
typedef int KeyType;
typedef int ValueType;

typedef enum Status
{
	_EMPTY,
	_EXITS,
	_DELETE,
};

typedef struct HashNode
{
	KeyType _key;
	ValueType _value;
	Status _status;
}HashNode;

typedef struct HashTable
{
	HashNode* _tables;
	size_t _size;
	size_t _capacity;
}HashTable;

size_t GetNextPrimeNum(size_t curPrime)
{
	int const _PrimeSize = 28;
	static const unsigned long _PrimeList[28] =
	{
		53ul, 97ul, 193ul, 389ul, 769ul,
		1543ul, 3079ul, 6151ul, 12289ul, 24593ul,
		49157ul, 98317ul, 196613ul, 393241ul, 786433ul,
		1572869ul, 3145739ul, 6291469ul, 12582917ul, 25165843ul,
		50331653ul, 100663319ul, 201326611ul, 402653189ul, 805306457ul,
		1610612741ul, 3221225473ul, 4294967291ul
	};
	for (int i = 0; i < _PrimeSize; i++)
	{
		if (_PrimeList[i]>curPrime)
			return _PrimeList[i];
	}
	return _PrimeList[_PrimeSize];
}
void HashTableInit(HashTable* ht,size_t capacity);
int HashTableInsert(HashTable* ht, KeyType key, ValueType value);
HashNode* HashTableFind(HashTable* ht, KeyType key);
int HashTableRemove(HashTable* ht, KeyType key);
int HashTableDestory(HashTable* ht);


void HashTableInit(HashTable* ht,size_t capacity)
{
	assert(ht);
	ht->_capacity = GetNextPrimeNum(capacity);
	ht->_tables = (HashNode*)malloc(sizeof(HashNode)*ht->_capacity);
	assert(ht->_tables);

	ht->_size = 0;
	for (int i = 0; i < (int)ht->_capacity; i++)
		ht->_tables[i]._status = _EMPTY;
}
void CheckCapacity(HashTable*ht)
{
	if (ht->_size * 10 / ht->_capacity>7)
	{
		HashTable newht;
		HashTableInit(&newht, ht->_capacity);
		for (size_t i = 0; i < ht->_capacity; i++)
		{
			if (ht->_tables[i]._status == _EXITS)
				HashTableInsert(&newht, ht->_tables[i]._key, ht->_tables[i]._value);
		}
		HashTableDestory(ht);
		ht->_capacity = newht._capacity;
		ht->_size = newht._size;
		ht->_tables = newht._tables;
	}
}
size_t HashFunc(const HashTable*ht,const KeyType key)
{
	return key%ht->_capacity;
}
int HashTableInsert(HashTable* ht, KeyType key, ValueType value)
{
	CheckCapacity(ht);
	int i = 1;
	size_t start = HashFunc(ht, key);
	size_t index = start;
	while (ht->_tables[index]._status == _EXITS)
	{
		if (ht->_tables[index]._key == key)
			return -1;
		/*index++;
		if (index == ht->_capacity)
			index = 0;*/
		
		index = start+i*i;
		i++;
		index %= ht->_capacity;
	}
	ht->_tables[index]._key = key;
	ht->_tables[index]._value = value;
	ht->_tables[index]._status = _EXITS;
	ht->_size++;
	return 0;
}
HashNode* HashTableFind(HashTable* ht, KeyType key)
{
	//如果index位置的哈希结点被删除，那么其后就不会再有key对应的哈希结点
	size_t start = HashFunc(ht, key);
	size_t index = start;
	int i = 1;
	while (ht->_tables[index]._status != _EMPTY)
	{
		if (ht->_tables[index]._status == _EXITS)
		{
			if (ht->_tables[index]._key == key)
				return &(ht->_tables[index]);
			/*index++;
			if (index == ht->_capacity)
				index = 0;*/

			index = start+i*i;
			i++;
			index %= ht->_capacity;
		}
		return NULL;
	}
	return NULL;
}
int HashTableRemove(HashTable* ht, KeyType key)
{
	assert(ht);
	HashNode*del=HashTableFind(ht, key);
	if (del == NULL)
		return -1;
	del->_status = _DELETE;
	ht->_size--;
	return 0;
}
int HashTableDestory(HashTable* ht)
{
	free(ht->_tables);
	ht->_capacity = ht->_size = 0;
	ht->_tables = NULL;
	return 0;
}