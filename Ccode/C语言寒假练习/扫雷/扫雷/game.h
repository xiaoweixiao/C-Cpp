#ifndef __GAME_H__
#define __GAME_H__

#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<time.h>
#include<stdlib.h>


#define ROW 11
#define LIST 11

#define MINE 10

extern char show[ROW][LIST];
extern char mine[ROW][LIST];

void InitBoard();
void PrintBoard(char board[ROW][LIST]);
void SetMine();//��������
void ClearMine();//ɨ��

int CountMine(int x, int y);//ͳ��x,y��������
void SetShowMap(int x, int y);//ɨ��һ������������������show����

#endif//__GAME_H__
