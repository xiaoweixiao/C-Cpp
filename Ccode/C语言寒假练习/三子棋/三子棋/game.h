#ifndef __GAME_H__
#define __GAME_H__
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<time.h>
#include<cstdlib>


#define ROW 3
#define LIST 3


void Printboard(char board[ROW][LIST], int row, int list);
void Initboard(char board[ROW][LIST], int row, int list);
void PlayerMove(char board[ROW][LIST], int row, int list);
char CheckWin(char board[ROW][LIST], int row, int list);
void ComputerMove(char board[ROW][LIST], int row, int list);

#endif//__GAME_H__
