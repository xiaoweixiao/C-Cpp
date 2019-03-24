#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<Windows.h>
int main()
{
	int a, b, c;
	scanf("%d %d", &a, &b);
	//c = a > b ? b : a;
	//while (a%c != 0 || b%c != 0)//a,b同时被c整除时，不进行--
	//{
	//	c--;
	//}
	//printf("%d\n", c);


	/*while (a != b)
	{
		if (a > b)
		{
			b = a - b;
			a = a - b;
		}
		else
		{
			a = b - a;
			b = b - a;
		}
	}
	printf("%d\n",b);*/
	



	c = a%b;
	while(c!=0)
	{
		a = b;
		b = c;
		c = a%b;
	}
	printf("%d\n",b);

	system("pause");
	return 0;
}