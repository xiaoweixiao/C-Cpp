//Ssqlist.h
#ifndef Seqlist_h_
#define Seqlist_h_

//ʵ�ֶ�̬˳���
#include<stdio.h>
#include<windows.h>
#include<assert.h>

typedef int DataType;

typedef struct SeqList
{
	DataType* a;
	size_t size; // ��Ч���ݸ������൱�������е��±ꡣ 
	size_t capacity; // ���� 
}SeqList;

void SeqPrint(SeqList* pSeq);
void SeqInit(SeqList* pSeq,size_t capacity);//��ʼ��˳���
void SeqDestory(SeqList* pSeq);//����˳���

void checkcapa(SeqList*pSeq);//��̬��������ֹԽ����ʡ�
void SeqPushBack(SeqList* pSeq, DataType x);//β��
void SeqPopBack(SeqList* pSeq);//βɾ
void SeqPushFront(SeqList* pSeq, DataType x);//ͷ��
void SeqPopFront(SeqList* pSeq);//ͷɾ

void SeqInsert(SeqList* pSeq, size_t pos, DataType x);//posλ�ò���x
void SeqErase(SeqList* pSeq, size_t pos);//

int SeqFind(SeqList* pSeq, DataType x);//����x
void SeqAt(SeqList* pSeq, size_t pos, DataType x);//�޸�poswλ�õ�����

void BubbleSort(SeqList* pSeq);//ð������
void SelectSort(SeqList* pSeq);//ѡ������
int BinarySearch(SeqList* pSeq,DataType x);//���ֲ���
void test();
#endif