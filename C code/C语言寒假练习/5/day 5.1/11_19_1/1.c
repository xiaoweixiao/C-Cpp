#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>
void menu()
{
	printf("*******************************\n");
	printf("**    1.play       0.exit    **\n");
	printf("*******************************\n");
}
void game()
{
	//1.�������ֵ
	int num = 0;
	int input = 0;
	num = rand()%100+1;
	//2.������
	while(1)
	{
		printf("�������:>");
		scanf("%d", &input);
		if(input == num)
		{
			printf("��ϲ�㣬�¶���\n");
			break;
		}
		else if(input>num)
		{
			printf("�´���\n");
		}
		else
		{
			printf("��С��\n");
		}
	}
}
int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("��ѡ��:>");
		scanf("%d", &input);
		switch(input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("ѡ�����\n");
			break;
		}
	}
	while(input);
	return 0;
}