#include"game.h"

char show[ROW][LIST] = { 0 };
char mine[ROW][LIST] = { 0 };

void menu()
{
	printf("\n\n\n");
	printf("		*******************************************\n");
	printf("		1��play game			0��exit	 \n");
	printf("		*******************************************\n");
}
void game()
{
	InitBoard();
	//PrintBoard(mine);
	PrintBoard(show);
	SetMine();
	PrintBoard(mine);
	//PrintBoard(show);
	ClearMine();
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
