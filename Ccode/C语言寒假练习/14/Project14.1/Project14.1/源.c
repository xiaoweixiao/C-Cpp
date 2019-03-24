#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<Windows.h>

void left_mov(char s[], int k, int len)
{
	k = k%len;
	char *p = (char *)malloc((2 * len + 1)*sizeof(char));
	strcpy(p, s);
	strcpy(p, s);
	strncpy(s,p+k,len);
	free(p);
}


//void Reverse(char*start, char*end)
//{
//	while (start < end)
//	{
//		*start ^= *end;
//		*end ^= *start;
//		*start ^= *end;
//		start++;
//		end--;
//	}
//}
//void left_mov(char str[], int left, int sz)
//{
//	left = left%sz;
//	Reverse(str, str + left - 1);
//	Reverse(str + left, str + sz-1);
//	Reverse(str, str + sz-1);
//}



//void left_mov(char str[], int left, int sz)
//{
//	int i = 0;
//	char tmp = str[0];
//	left = left%sz;
//	for (i = 0; i < left; i++)
//	{
//		int j = 0;
//		for (j = 0; j < sz-1; j++)
//		{
//			str[j] = str[j + 1];
//		}
//		str[j] = tmp;
//	}
//}


int main()
{
	char str[] = { "ABCDEF" };
	int left = 1;
	int sz = sizeof(str) / sizeof(str[0]);
	printf("左旋之前的字符串是：%s\n", str);
	left_mov(str, left, sz);
	printf("左旋之后的字符串是：%s\n", str);
	system("pause");
	return 0;
}