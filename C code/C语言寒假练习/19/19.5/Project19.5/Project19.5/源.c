#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<Windows.h>
int my_strcmp(char*src, char*dest)
{
	int ret = 0;
	while (!(ret = *(unsigned char*)src - *(unsigned char*)dest) && *dest)
		++src , ++dest;

	if (ret < 0)
		ret = -1;
	else if (ret>0)
		ret = 1;
	return ret;
}
int main()
{
	char str1[12] = "I love zou!";
	char str2[13]= "I love zhou!";
	
	printf("%d\n", my_strcmp(&str1, &str2));
	system("pause");
	return 0;
}