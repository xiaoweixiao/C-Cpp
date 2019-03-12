#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<Windows.h>
#include<assert.h>
int my_strncmp(char*s1, char*s2, size_t n )
{
	assert(s1);
	assert(s2);

	int tmp=0;
	int count=0;
	tmp = ((*((int*)s1) - *((int*)s2)) && (s1++) && (s2++)&&((count++)<((int*)n)));
	if (tmp>0)
		return 1;
	else if (tmp < 0)
		return -1;
	else
		return 0;
}
int main()
{
	int tmp;
	char str1[] = { "This a test for strncmp!" };
	char str2[] = { "This a test for strcmp!" };
	tmp=my_strncmp(str1, str2, 10);
	printf("%d\n", tmp);
	system("pause");
	return 0;
}