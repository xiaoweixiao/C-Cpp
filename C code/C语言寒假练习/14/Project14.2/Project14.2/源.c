#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<Windows.h>
int find_dest(char* src, char* dest)
{
	int len = strlen(src);
	char*tmp = (char*)malloc(2*len+1);
	if (len == strlen(dest))
	{
		strcpy(tmp, src);
		strcat(tmp, src);
		if (strstr(tmp, dest) != NULL)
		{
			return 1;
		}
	}
	free(tmp);
	return 0;
}
int main()
{
	int ret = 0;
	char S1[] = { "ABCD" };
	char S2 []= { "BCDA" };
	ret = find_dest(S1, S2);
	if (ret == 1)
		printf("S2是由S1左旋得到的\n");
	else
		printf("S2不是由S1左旋得到的\n");
	system("pause");
	return 0;
}