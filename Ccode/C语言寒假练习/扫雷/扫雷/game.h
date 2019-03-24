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
void SetMine();//生成雷区
void ClearMine();//扫雷

int CountMine(int x, int y);//统计x,y附近的雷
void SetShowMap(int x, int y);//扫除一个非雷区，进行重置show数组

#endif//__GAME_H__
