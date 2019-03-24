#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<Windows.h>
#include<math.h>
int main()
{
	int i = 0;
	int count = 0;
	for (i = 2; i <=100; i++)
	{
		int n = 0;
		for (n = 2; n <sqrt(i); n++)
		{
			if(i%n == 0)
			{
				break;
			}		
		}
		if (n>sqrt(i))
		{
			printf("%d ",i);
			count++;
		}
	}
	printf("\n%d\n",count);
	system("pause");
	return 0;
}