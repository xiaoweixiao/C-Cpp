#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<Windows.h>
#include<stdarg.h>
int Max(int n,...)
{
	int max=0;
	int i=0;
	va_list arg;
	va_start(arg,n);
	for(i=0;i<n;i++)
	{
		int val=va_arg(arg,int);
		//�겻ͬ�ں����������з���ֵ��ֱ�Ӵ�ӡ����ֵ������붨��һ�����������ܺ����ɲ���
		if(val>max)
		{
			max=val;
		}
	}
	va_end(arg);
	return max;
}
int main()
{
	printf("Max==%d\n",Max(10,99,88,77,66,55,4,3,2,1,20));
	system("pause");
	return 0;
}