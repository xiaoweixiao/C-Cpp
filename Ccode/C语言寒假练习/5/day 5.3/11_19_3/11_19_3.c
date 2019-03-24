#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	int i=0;
	char passwd[10]={0};
	for(i=0;i<3;i++)
	{
		printf("请输入密码:>");
	    scanf("%s",passwd);
		if(strcmp(passwd,"999666")==0)
	    {
			printf("密码正确，登陆成功！\n");
			break;
		}
		else
		{
			printf("密码错误！请重新输入！\n");
		}
	}
	if(i==3)
	{
		printf("三次密码错误，退出系统！");
		exit(1);
	}
	system("pause");
	return 0;
}
