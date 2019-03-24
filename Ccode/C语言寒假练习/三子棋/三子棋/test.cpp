#include"game.h"

void menu()
{
	printf("\n\n\n");
	printf("		*******************************************\n");
	printf("		1��play game			0��exit	 \n");
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
		printf("�ܺã����Ѿ��͵��Դ����ƽ�֣�\n");
	else if (win == 'W')
		printf("��ϲ�㣬���Ӯ�ˣ�\n");
	else
		printf("���ź�������Ӯȡ�˱�����\n");
}
void Test()
{
	int input;
	do
	{
		menu();
		printf("\n\n������ѡ��>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			break;
		default:
			printf("�������������ѡ��\n");
			break;
		}
	} while (input);
}
int main()
{
	Test();
	return 0;
}