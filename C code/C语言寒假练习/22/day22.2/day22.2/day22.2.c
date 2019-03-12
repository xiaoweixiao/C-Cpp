#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<windows.h>
#include<assert.h>
char* my_strncat(char* dest,const char* src,size_t num)
{
	char* ret=dest;
	unsigned int i=0;
	assert(dest);
	assert(src);
	while(*dest)
	{
		dest++;
	}
	for(i=0;i<num;i++)
	{
		*dest++=*src++;
	}
	return ret;
}
int main()
{
	char s1[100]="I don't want to break!!!";
	char s2[]="But the vacation is coming!!!";
	my_strncat(s1,s2,50);
	system("pause");
	return 0;
}