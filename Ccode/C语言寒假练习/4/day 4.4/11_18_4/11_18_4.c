#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main()
{
	int ch = 0;
	int count = 0;
	/*{}{}}{
	}{
	}}{{
	{{{}}}}{
	{{}}*/

	while((ch=getchar()) != EOF)
	{
		if(ch == '{')
			count++;
		else if(ch == '}' && count==0)
		{
			printf("��ƥ��\n");
			return 0;
		}
		else if(ch == '}')
		{
			count--;
		}
	}
	if(count == 0)
	{
		printf("ƥ��\n");
	}
	else
	{
		printf("��ƥ��\n");
	}
	return 0;
}