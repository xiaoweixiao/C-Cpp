#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>  
#include<stdlib.h>  
  
unsigned int revease_bit(unsigned int val)  
{  
    int i;  
    unsigned int ret=0;  
    for(i=0;i<32;i++)  
    {  
        ret<<=1;//for中两个语句不能互换  
        ret|=((val>>i)&1);  
        /*val右移i位，和“1”进行与运算取出二进制每一位的值，再和ret或运算，最后移位，使其逆序排列。也可以用下面写法：（加头文件#include<math.h>） 
        ret += ((num >> i) & 1)*pow(2, 31 - i); 
        */  
    }  
    return ret;  
}  
int main()  
{  
    unsigned int val;  
    scanf("%u",&val);  
    printf("%u\n",revease_bit(val));//%u为以无符号十进制输出  
    system("pause");  
    return 0;  
}  