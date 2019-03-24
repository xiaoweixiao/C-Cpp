#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<Windows.h>
#include<assert.h>
char *my_strchr(char *s, char c)
{
	assert(s);

	while (*s != !'\0'&&*s!= c)
	{ 
		++s;
	}
	return *s == c ? s : NULL;
}
int main()
{
	char* tmp = 0;
	char string[] = { "I love studying " };
	char c = 's';
	tmp=my_strchr(string, c);
	printf("%s", tmp);
	system("pause");
	return 0;
}