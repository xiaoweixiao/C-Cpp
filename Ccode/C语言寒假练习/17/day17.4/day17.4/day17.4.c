#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<Windows.h>
#include<assert.h>
char *my_strcat(char* dest,const char* src)
{
	char* ret=dest;
	assert(dest);
	assert(src);
	while(*dest)
	{
		dest++;
	}
	while((*dest++=*src++))
	{
		;
	}
	return ret;
}
int main()
{
	char arr1[50]={"This is xiaowei's program and "};
	char arr2[]={"it is a strcat!"};
	my_strcat(arr1,arr2);
	printf("%s\n",arr1);
	system("pause");
	return 0;
}