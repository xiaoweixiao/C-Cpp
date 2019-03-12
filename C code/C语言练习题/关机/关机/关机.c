#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<Windows.h>
int main()
{
	int start=0;
	int end=0;
	char input[10]={0};
flag:
	printf("请输入：我是猪，否则电脑将在一分钟内关机");
	system("shutdown -s -t 60");
	scanf("%s",input);
	start=GetTickCount();
	if(strcmp(input,"我是猪")==0)
	{
		system("shutdown -a");
	}
	else
	{
		goto flag;
	}
	end=GetTickCount();
	printf("%d",end-start);
	system("pause");
	return 0;
}
