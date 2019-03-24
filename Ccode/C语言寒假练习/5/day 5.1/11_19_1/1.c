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
	//1.生成随机值
	int num = 0;
	int input = 0;
	num = rand()%100+1;
	//2.猜数字
	while(1)
	{
		printf("请猜数字:>");
		scanf("%d", &input);
		if(input == num)
		{
			printf("恭喜你，猜对了\n");
			break;
		}
		else if(input>num)
		{
			printf("猜大了\n");
		}
		else
		{
			printf("猜小了\n");
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
		printf("请选择:>");
		scanf("%d", &input);
		switch(input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("选择错误\n");
			break;
		}
	}
	while(input);
	return 0;
}