#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>  
#include<windows.h>
void Find_Num(int arr[], int sz, int * num1, int *num2)
{
	int i = 0;
	int ret = 0;
	int pos = 0;
	int temp = 0;
	*num1 = 0;
	*num2 = 0;
	for (i = 0; i < sz; i++)
	{
		ret ^= arr[i];//0与数组中元素依次亦或，
		//最终得到两个不唯一的数的亦或值，其余的数在亦或过程中消掉了。  
	}
	temp = ret;
	while (ret)
	{
		if (ret % 2 == 1)
		{
			break;
		}
		pos++; //第pos位为1  
		ret /= 2;
	}
	for (i = 0; i < sz; i++)
	{
		if ((arr[i] >> pos) & 1)//取出第pos位的值  
		{
			*num1 ^= arr[i];
		}
	}
	*num2 = temp^*num1;
}
int main()
{
	int num1 = 0;
	int num2 = 0;
	int arr[] = { 1, 2, 3, 4, 5, 1, 2, 3, 4, 8 };
	int sz = sizeof (arr) / sizeof(arr[0]);
	Find_Num(arr, sz, &num1, &num2);
	printf("%d,%d\n", num1, num2);
	system("pause");
	return 0;
}
//一个数组中只有两个数字是出现一次，其他所有数字都出现了两次。找出这两个数字，编程实现。 
//本题思路：
//1.将0与数组每个元素依次亦或的结果就是两个只出现一次的元素亦或的值，相同元素的二进制位是相同的，亦或的值为0
//2.将数组分为两组，每一组包含一个只出现一次的数，分组的思路是：两个唯一的数是不相同的，那么在他们的二进制序列中必然有一位是不相同的，找出这一位，以这一位为标志，将其余数进行分组。
//3.将两个数组分别与0进行亦或，最终得到两个只出现一次的数。