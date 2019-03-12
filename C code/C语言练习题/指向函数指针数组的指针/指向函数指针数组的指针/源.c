#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<Windows.h>
void test(const char*str)
{
	printf("%s\n", str);
}
int main( )
{
	void(*pfun)(const char*) = test;
	void(*pfunArr[5])(const char*str);
	pfunArr[0] = test;
	void(*(*ppfunArr)[10])(const char*) = &pfunArr;
	system("pause");
	return 0;
}