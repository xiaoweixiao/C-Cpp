#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<Windows.h>
void* my_memcpy(void* dest, const void* src, size_t count)
{
	void *ret = dest;


	while (count--)
	{
		*(char*)dest = *(char*)src;
		dest = (char*)dest + 1;
		src = (char*)src + 1;
	}
	return ret;
}
int main()
{
	char mem1[30] = { "This a memcpy test!" };
	char mem2[30] = { 0 };
	int i = 0;
	my_memcpy(mem2, mem1, 20);
	for (i=0; i < 30; i++)
	{
		printf("%c", mem2[i]);
	}
	system("pause");
	return 0;
}