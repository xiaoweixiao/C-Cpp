#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>  
#include<stdlib.h>  
  
unsigned int revease_bit(unsigned int val)  
{  
    int i;  
    unsigned int ret=0;  
    for(i=0;i<32;i++)  
    {  
        ret<<=1;//for��������䲻�ܻ���  
        ret|=((val>>i)&1);  
        /*val����iλ���͡�1������������ȡ��������ÿһλ��ֵ���ٺ�ret�����㣬�����λ��ʹ���������С�Ҳ����������д��������ͷ�ļ�#include<math.h>�� 
        ret += ((num >> i) & 1)*pow(2, 31 - i); 
        */  
    }  
    return ret;  
}  
int main()  
{  
    unsigned int val;  
    scanf("%u",&val);  
    printf("%u\n",revease_bit(val));//%uΪ���޷���ʮ�������  
    system("pause");  
    return 0;  
}  