#include"game.h"

extern char show[ROW][LIST];//������extern����game.h���show��mine,��game.h���show��mine����test.c�е�show��mine
extern char mine[ROW][LIST];//��֤�����ļ��е�show��mine��ͬһ����


int sum = 0;//ͳ��sum�����׵�λ����
void InitBoard()
{
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < LIST; j++)
		{
			show[i][j] = '*';
			mine[i][j] = '0';
		}
	}
}

void PrintBoard(char board[ROW][LIST])
{
	int k = ROW;
	for (int i = 0; i <LIST-1; i++)//��ӡ��һ�е�����
		printf(" %d |", i);
	printf("\n");
	for (int i = 0; i <LIST-1; i++)//��ӡ�ڶ��еķָ���
		printf("----");
	printf("\n");
	for (int i = 1; i < ROW-1; i++)//��ӡ����1--9������Χ����ӡ(�±��к���0��11��)
	{
		printf(" %d |", i);
		for (int j = 1; j < LIST-1; j++)
		{
			printf(" %c |", board[i][j]);
		}
		printf("\n");
		if(k)
		{
			for (int i = 0; i <LIST-1; i++)
				printf("----");
			printf("\n");
			k--;
		}
	}
	printf("\n\n\n");
}


void SetMine()
{
	srand((unsigned int)time(NULL));
	int x, y;
	int count = MINE;
	while (count)
	{
		x = (rand() % (ROW-2)) +1;//ROW==11,ROW-2=9,0---8,1---9
		y = (rand() % (LIST-2))+1;
		if (mine[x][y] == '0')
		{
			mine[x][y] = '1';
			count--;
		}		
	}
}


int CountMine(int x, int y)
{
	int count = 0;
	int i = x-1, j = y-1;
	for (i =x-1; i < x+2; i++)
	{
		for (j = y-1; j < y+2; j++)
		{
			if (!(i==x&&j==y))
			{
				if (mine[i][j] == '1')
					count++;
			}
		}
	}
	return count;
}
void SetShowMap(int x, int y)
{
	int i = x - 1, j = y - 1;
	for (i = x - 1; i < x + 2; i++)
	{
		for (j = y - 1; j < y + 2; j++)
		{
			if (i >0 && i < ROW-1&&j > 0 && j < LIST-1)
			{
				if (!(i == x&&j == y)&&show[i][j] == '*')//
				{
					if (mine[i][j] == '0')
					{
						sum++;
						show[i][j] = CountMine(i, j)+'0';
						SetShowMap(i, j);
					}
					else
					{
						return;
					}
				}
			}
		}
	}
}
void FirstNoDie(x, y)//��һ����������
{
	int i = 1,j = 1;
	mine[x][y] = '0';
	show[x][y] = CountMine(x, y) + '0';
	while (mine[i][j] != '0')
	{
		if (i < ROW - 1)
			i++;
		else
			j++;
	}
	mine[i][j] = '1';//������
	PrintBoard(mine);
	PrintBoard(show);
}

void ClearMine()
{
	int x, y;//count������ǲ����׵�λ����
	while (sum!=(ROW-2)*(LIST-2)-MINE)
	{
		printf("����������Ҫ�ų����������꣺>");
		scanf("%d%d", &x, &y);
		if (x > 0 && x <ROW-1 && y > 0 && y < LIST-1)//��������x,y����1<=x<=9,��������Ͷ�Ӧ����С��
		{
			if (mine[x][y] == '1')//�ȵ���
			{
				if (sum == 0)//����ų������׵�count��ֵ��0��˵���ǵ�һ�ξͲ����ˣ�
				{
					FirstNoDie(x,y);//��������
				}
				else
				{
					printf("�ܲ��ң��㱻ը����\n");
					PrintBoard(mine);
					break;
				}
			}
			else
			{
				//������
				sum++;
				show[x][y] = CountMine(x, y)+'0';
				SetShowMap(x, y);
				PrintBoard(show);
			}
		}
		else
		{
			printf("�������겻�Ϸ�\n");
		}
	}
	if (sum==(ROW-2)*(LIST-2)-MINE)
		printf("��ϲ�����׳ɹ���\n");
}
