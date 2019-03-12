#include"game.h"

void menu()
{
	printf("\n\n\n");
	printf("		*******************************************\n");
	printf("		1、play game			0、exit	 \n");
	printf("		*******************************************\n");
}
void game()
{
	char win=' ';
	char board[ROW][LIST] = { 0 };
	srand((unsigned int)time(nullptr));
	Initboard(board, ROW, LIST);
	Printboard(board,ROW,LIST);
	while (1)
	{
		PlayerMove(board, ROW, LIST);
		Printboard(board, ROW, LIST);
		win = CheckWin(board, ROW, LIST);
		if (win != ' ')
			break;
		ComputerMove(board, ROW, LIST);
		Printboard(board, ROW, LIST);
		win = CheckWin(board, ROW, LIST);
		if (win != ' ')
			break;
	}
	if (win == 'P')
		printf("很好，你已经和电脑达成了平手！\n");
	else if (win == 'W')
		printf("恭喜你，玩家赢了！\n");
	else
		printf("很遗憾，电脑赢取了比赛！\n");
}
void Test()
{
	int input;
	do
	{
		menu();
		printf("\n\n请输入选择>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			break;
		default:
			printf("输入错误，请重新选择\n");
			break;
		}
	} while (input);
}
int main()
{
	Test();
	return 0;
}