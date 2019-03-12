#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<windows.h>
#include<assert.h>
char *my_strcpy(char *dest,const char *src)
{
	char *ret=dest;
	assert(dest);
	assert(src);
	while(*dest++=*src++)
	{
		;
	}
	return ret;
}
int main()
{
	char arr1[30];
	char arr2[]={"I am an programmer! "};
	my_strcpy(arr1,arr2);
	printf("%s\n",arr1);
	system("pause");
	return 0;
}
