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
		printf("����������:>");
	    scanf("%s",passwd);
		if(strcmp(passwd,"999666")==0)
	    {
			printf("������ȷ����½�ɹ���\n");
			break;
		}
		else
		{
			printf("����������������룡\n");
		}
	}
	if(i==3)
	{
		printf("������������˳�ϵͳ��");
		exit(1);
	}
	system("pause");
	return 0;
}
