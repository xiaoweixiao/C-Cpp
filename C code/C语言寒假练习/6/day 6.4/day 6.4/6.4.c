#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
int count_one_bits(int n)
{
	int i=0;
	int count = 0;
	for(i=0; i<32; i++)
 	{
 		if(((n>>i)&1) == 1)
 			count++;
 	}
	return count;
}
 
int main()
{
	int m = 2299;
	int n = 1999;
	int tmp = m^n;
	int count = count_one_bits(tmp);
	printf("count = %d\n", count);
	system("pause");
	return 0;
}