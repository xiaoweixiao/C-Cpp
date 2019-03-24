
#include <stdio.h>
#define pragma warning:4996
#include<Windows.h>
#include<assert.h>



const char *my_strstr(const char*str1, const char *str2)
{
	assert(str1);
	assert(str2);
	const char*cp = (char*)str1;
	const char*substr = (char*)str2;
	const char*s1 = NULL;
	if (*str2 == '\0')
		return NULL;
	while (*cp)
	{
		s1 = cp;
		substr = str2;
		while (*s1&&*substr && (*s1 == *substr))
		{
			s1++;
			substr++;
		}
		if (*substr == '\0')
			return cp;
		cp++;
	}
		return NULL;
}
//const char *my_strstr(const char *str, const char *sub_str)
//{
//	for (int i = 0; str[i] != '\0'; i++)
//	{
//		int tem = i; //tem保留主串中的起始判断下标位置 
//		int j = 0;
//		while (str[i++] == sub_str[j++])
//		{
//			if (sub_str[j] == '\0')
//			{
//				return &str[tem];
//			}
//		}
//		i = tem;
//	}
//
//	return NULL;
//}





int main()
{
	char *s = "1233345hello";
	char *sub = "345";
	printf("%s\n", my_strstr(s, sub));
	system("pause");
	return 0;
}