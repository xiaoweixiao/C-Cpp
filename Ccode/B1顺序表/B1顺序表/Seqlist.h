//Ssqlist.h
#ifndef Seqlist_h_
#define Seqlist_h_

//实现动态顺序表
#include<stdio.h>
#include<windows.h>
#include<assert.h>

typedef int DataType;

typedef struct SeqList
{
	DataType* a;
	size_t size; // 有效数据个数，相当于数组中的下标。 
	size_t capacity; // 容量 
}SeqList;

void SeqPrint(SeqList* pSeq);
void SeqInit(SeqList* pSeq,size_t capacity);//初始化顺序表
void SeqDestory(SeqList* pSeq);//销毁顺序表

void checkcapa(SeqList*pSeq);//动态特征，防止越界访问。
void SeqPushBack(SeqList* pSeq, DataType x);//尾插
void SeqPopBack(SeqList* pSeq);//尾删
void SeqPushFront(SeqList* pSeq, DataType x);//头插
void SeqPopFront(SeqList* pSeq);//头删

void SeqInsert(SeqList* pSeq, size_t pos, DataType x);//pos位置插入x
void SeqErase(SeqList* pSeq, size_t pos);//

int SeqFind(SeqList* pSeq, DataType x);//查找x
void SeqAt(SeqList* pSeq, size_t pos, DataType x);//修改posw位置的数据

void BubbleSort(SeqList* pSeq);//冒泡排序
void SelectSort(SeqList* pSeq);//选择排序
int BinarySearch(SeqList* pSeq,DataType x);//二分查找
void test();
#endif