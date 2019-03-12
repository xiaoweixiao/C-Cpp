#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int a = 24;
    int b = 18;
	int tmp = 0;
while(a%b)
	{
			tmp = a%b;
             a = b;
		     b = tmp;	 
	}
	printf("%d\n",b);
	system("pause");
	return 0;
}