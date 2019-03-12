#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
int main()
{
	char arr[]={'b','e','a','u','t','i','f','u','l','\0'};//字符串后隐藏\0,strlen统计字符串长度时，\0不列入计算,\0是字符串结束的标志
	printf("beautiful\n");
	printf("%s\n",arr);
	 system("pause");
	return 0;
}




