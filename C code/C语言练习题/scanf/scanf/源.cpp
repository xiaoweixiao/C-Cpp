#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
void swap(int *a, int *b)

{

	int t = *a;

	*a = *b;

	*b = t;

}

int main()

{

	int a = 0, b = 0, c = 0;

	printf("请输入三个数：");

	scanf("%d%d%d", &a, &b, &c);

	if (a < b)

	{

		swap(&a, &b);

	}

	if (a < c)

	{

		swap(&a, &c);

	}

	if (b < c)

	{

		swap(&b, &c);

	}

	printf("从大到小输出：%d %d %d\n", a, b, c);
	system("pause");
	return 0;

}
