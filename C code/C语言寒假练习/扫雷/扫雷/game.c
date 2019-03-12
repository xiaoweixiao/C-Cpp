#include"game.h"

extern char show[ROW][LIST];//这里用extern引入game.h里的show和mine,而game.h里的show和mine引用test.c中的show和mine
extern char mine[ROW][LIST];//保证三个文件中的show和mine是同一个。


int sum = 0;//统计sum不是雷的位置数
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
	for (int i = 0; i <LIST-1; i++)//打印第一行的坐标
		printf(" %d |", i);
	printf("\n");
	for (int i = 0; i <LIST-1; i++)//打印第二行的分割线
		printf("----");
	printf("\n");
	for (int i = 1; i < ROW-1; i++)//打印数组1--9，最外围不打印(下标中含有0和11的)
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
void FirstNoDie(x, y)//第一次免死金牌
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
	mine[i][j] = '1';//替死鬼
	PrintBoard(mine);
	PrintBoard(show);
}

void ClearMine()
{
	int x, y;//count用来标记不是雷的位置数
	while (sum!=(ROW-2)*(LIST-2)-MINE)
	{
		printf("请输入你想要排除的雷区坐标：>");
		scanf("%d%d", &x, &y);
		if (x > 0 && x <ROW-1 && y > 0 && y < LIST-1)//输入坐标x,y满足1<=x<=9,输入坐标就对应数组小标
		{
			if (mine[x][y] == '1')//踩到雷
			{
				if (sum == 0)//如果排除不是雷的count数值是0，说明是第一次就踩雷了，
				{
					FirstNoDie(x,y);//免死金牌
				}
				else
				{
					printf("很不幸，你被炸死了\n");
					PrintBoard(mine);
					break;
				}
			}
			else
			{
				//不是雷
				sum++;
				show[x][y] = CountMine(x, y)+'0';
				SetShowMap(x, y);
				PrintBoard(show);
			}
		}
		else
		{
			printf("输入坐标不合法\n");
		}
	}
	if (sum==(ROW-2)*(LIST-2)-MINE)
		printf("恭喜你排雷成功！\n");
}
