//#define _CRT_SECURE_NO_WARNINGS
//# include<stdio.h> 
//#include<Windows.h>
//# include<stdio.h> 
//
//char FirstOnce(const char*str)
//{
//	int hash[26] = { 0 };
//
//	const char *s1 = str;
//	while (*s1)
//	{
//		hash[*s1 - 'a']++;
//		s1++;
//	}
//	s1 = str;
//	while (*s1)
//	{
//		if (hash[*s1 - 'a'] == 1)
//			return *s1;
//		s1++;
//	}
//	return -1;
//}
//void Test()
//{
//	char str[] = { "abcdefghijhfbca" };
//	FirstOnce(str);
//}
#define _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<stdio.h>
int Max(int a,int b,int c)
{
	int max = a;
	if (max > b)
	{
		if (max < c)
			max = c;
	}
	else
	{
		max = b;
		if (max < c)
			max = c;
	}
	return max;
}
void Test()
{
	int x, y, z, w;
	scanf("%d %d %d ", &x, &y, &z);
	w = Max(x, y, z);
	printf("max result:%d", w);
}