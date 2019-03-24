#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
int main()
{
    double sum=0.0;
	int i=0;
	//int flag=1;
	for(i=1;i<=100;i++)
	{
       /*sum=sum+flag*1.0/i;
		flag=-flag;*/
		if(i%2==0)
		{
			sum=sum-1.0/i;
		}
		else
		{
			sum=sum+1.0/i;
		}
	}
	printf("%f\n",sum);
	system("pause");
	return 0;
}