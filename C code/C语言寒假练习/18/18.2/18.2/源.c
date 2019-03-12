#include<stdio.h>
#include<Windows.h>
#include<string.h>
int my_strcmp(const void*x, const void*y)
{
	return *(int*)x > *(int*)y;
}
void Bubble_sort_str(char*str[], int sz)
{
	for (int i = 0; i < sz - 1; i++)
	{
		for (int j = 0; j < sz - i - 1; j++)
		{
			if (my_strcmp(*(str + j), *(str + j + 1))>0)
			{
				char*tmp = *(str + j);
				*(str + j) = *(str + j + 1);
				*(str + j + 1) = tmp;
			}
		}
	}
}
int main()
{
	int i = 0;
	char *str[] = { "HSDF", "abcde", "abc"};
	int sz = sizeof(str) / sizeof(*str);
	Bubble_sort_str(str, sz);
	for (i = 0; i < sz; i++)
	{
		printf("%s\n", *(str + i));
	}
	system("pause");
	return 0;
}



