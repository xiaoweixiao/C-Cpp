#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int ch=0;
	while((ch=getchar())!=EOF)
	{
		if(ch>'a'&&ch<'z')
		{
			putchar(ch-32);
		}
		else if(ch>'A'&&ch<'Z')
		{
			putchar(ch+32);
		}	
	}
	printf("\n");
	system("pause");
	return 0;
}
