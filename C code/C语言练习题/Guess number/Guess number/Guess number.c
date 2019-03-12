#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<windows.h>
#include<time.h>
void menu()
{
	printf("这是一个猜数字游戏，你所猜测的数字必须在1--100之间！！!\n");
	printf("********************************************\n");
	printf("****	 1.>play	  0.>exit	****\n");
	printf("********************************************\n");
}
void game()
{
	//产生随机数
	int input=0;
	int num=0;
	num=rand()%100+1;
	//判断所猜数字是否准确
	while(1)
	{
		printf("请输入你所猜测的数字>>>>");
		scanf("%d",&input);
		if(input==num)
		{
			printf("恭喜你！猜对了!\n");
			break;
		}
		else if(input>num)
		{
			printf("猜大了!\n");
		}
		else 
		{
			printf("猜小了\n");
		}
	}
}
int main()
{
	int input=0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("请选择>:");
		scanf("%d",&input);
		switch(input)
		{
		case 1:
			game();
			break;
		case 0:
			break;
		default:
			printf("选择错误，请重新输入！\n");
			break;
		}
	}while(input);
	return 0;
}
