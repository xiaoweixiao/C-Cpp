#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<Windows.h>
#include<assert.h>
char * my_strcpy(char* dest, char* src)
{
	char* ret = dest;
	assert(dest);
	assert(src);
	while ((*dest++ = *src++))
	{
		;
	}
	return ret;
}
int main()
{
	char a1[50];
	char a2[] = { "���������������Ǵ�ɵ�ƣ�������������" };
	my_strcpy(a1, a2);
	printf("%s\n", a1);
	system("pause");
	return 0;
}