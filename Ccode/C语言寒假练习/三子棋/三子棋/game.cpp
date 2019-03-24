#include"game.h"

void Printboard(char board[ROW][LIST], int row, int list)
{
	for (int i = 0; i < row; i++)
	{
		printf("					 %c | %c | %c\n", board[i][0], board[i][1], board[i][2]);
			if (i < row - 1)
				printf("					---|---|---\n");
	}
}

void Initboard(char board[ROW][LIST], int row, int list)
{
	memset(board, ' ', row*list*sizeof(board[0][0]));
}


void PlayerMove(char board[ROW][LIST], int row, int list)
{
	int x, y;
	printf("请你输入你下子的坐标:>");
	scanf("%d%d", &x, &y);
	if (x > 0 && x<ROW + 1 && y>0 && y < LIST + 1)
	{
		if (board[x - 1][y - 1] == ' ')
			board[x - 1][y - 1] = 'W';
		else
			printf("你输入的位置有棋子，请输入合法坐标\n");
	}
	else
		printf("你输入的数据不合法,横坐标不大于%d,纵坐标不大于%d", ROW, LIST);
}

bool IsFull(char board[ROW][LIST], int row, int list)
{
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < LIST;j++)
		if (board[i][j] == ' ')
			return false;
	}
	return true;
}
char CheckWin(char board[ROW][LIST], int row, int list)
{
	int i = 0;
	for (i = 0; i < ROW; i++)
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][2] != ' ')
		return board[i][0];
	}

	for (i = 0; i < LIST; i++)
	{
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[2][i] != ' ')
		return board[0][i];
	}
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[2][2] != ' ')
		return board[0][0];
	if (board[2][0] == board[1][1] && board[1][1] == board[0][2] && board[1][1] != ' ')
		return board[1][1];
	if (IsFull(board,row,list))
	{
		return 'P';
	}
	return ' ';
}



void ComputerMove(char board[ROW][LIST], int row, int list)
{
	int x = rand() % ROW;
	int y = rand() % LIST;
	while (1)
	{
		if (board[x][y] == ' ')
		{
			board[x][y] = 'C';
			break;
		}
		else
		{
			x = rand() % ROW;
			y = rand() % LIST;
		}
	}
}