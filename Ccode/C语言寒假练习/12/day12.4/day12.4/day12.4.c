#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<Windows.h>
void reverse_all(char *star, char *end)
{
	while (star < end)
	{
		*star =*star^ *end;
		*end = *star^*end;
		*star = *star^*end;
		star++;
		end--;
	}
}

int main()
{
	char msg[] = "student a am i";
	printf("%s", msg);
	char *p = msg;
	char *q = p;
	reverse_all(msg, msg + strlen(msg) - 1);
	while (*p != '\0'&&*q != '\0')
	{
		if (*q == ' ')
		{
			reverse_all(p, q - 1);
			q++;
			p++;
		}
	}
	reverse_all(p, q - 1);
	printf("%s", msg);
	system("pause");
	return 0;
}