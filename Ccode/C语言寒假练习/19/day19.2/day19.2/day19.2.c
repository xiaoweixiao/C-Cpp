#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<windows.h>
#include<assert.h>
char* my_strcat(char* dest,const char* src)
{
	char*ret=dest;
	assert(dest);
	assert(src);
	while(*dest)
	{
		*dest++;
	}
	while((*dest++=*src++))
	{
		;
	}
	return ret;
}
int main()
{
	char a1[50]={"����һ��С����������"};
	char a2[]={"�ԣ������С����������"};
	my_strcat(a1,a2);
	printf("%s\n",a1);
	system("pause");
	return 0;
}