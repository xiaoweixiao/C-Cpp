#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<windows.h>
#include<time.h>
void menu()
{
	printf("����һ����������Ϸ�������²�����ֱ�����1--100֮�䣡��!\n");
	printf("********************************************\n");
	printf("****	 1.>play	  0.>exit	****\n");
	printf("********************************************\n");
}
void game()
{
	//���������
	int input=0;
	int num=0;
	num=rand()%100+1;
	//�ж����������Ƿ�׼ȷ
	while(1)
	{
		printf("�����������²������>>>>");
		scanf("%d",&input);
		if(input==num)
		{
			printf("��ϲ�㣡�¶���!\n");
			break;
		}
		else if(input>num)
		{
			printf("�´���!\n");
		}
		else 
		{
			printf("��С��\n");
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
		printf("��ѡ��>:");
		scanf("%d",&input);
		switch(input)
		{
		case 1:
			game();
			break;
		case 0:
			break;
		default:
			printf("ѡ��������������룡\n");
			break;
		}
	}while(input);
	return 0;
}
