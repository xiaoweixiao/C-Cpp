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
		ret ^= arr[i];//0��������Ԫ���������
		//���յõ�������Ψһ���������ֵ������������������������ˡ�  
	}
	temp = ret;
	while (ret)
	{
		if (ret % 2 == 1)
		{
			break;
		}
		pos++; //��posλΪ1  
		ret /= 2;
	}
	for (i = 0; i < sz; i++)
	{
		if ((arr[i] >> pos) & 1)//ȡ����posλ��ֵ  
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
//һ��������ֻ�����������ǳ���һ�Σ������������ֶ����������Ρ��ҳ����������֣����ʵ�֡� 
//����˼·��
//1.��0������ÿ��Ԫ���������Ľ����������ֻ����һ�ε�Ԫ������ֵ����ͬԪ�صĶ�����λ����ͬ�ģ�����ֵΪ0
//2.�������Ϊ���飬ÿһ�����һ��ֻ����һ�ε����������˼·�ǣ�����Ψһ�����ǲ���ͬ�ģ���ô�����ǵĶ����������б�Ȼ��һλ�ǲ���ͬ�ģ��ҳ���һλ������һλΪ��־�������������з��顣
//3.����������ֱ���0����������յõ�����ֻ����һ�ε�����