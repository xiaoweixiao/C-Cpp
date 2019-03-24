#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <windows.h>

int bottle_num(int yuan)//喝汽水
{
    if (yuan)//零元返回零瓶
    {
        while (1 != yuan)
        {
            if (yuan & 1)//如果是奇数瓶
            {
                return yuan - 1 + bottle_num((yuan >> 1) + 1);
            }
            else//如果是偶数瓶
            {
                return yuan + bottle_num(yuan >> 1);
            }
        }
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    int num = 0;
    printf("请输入你的钱数：\n");
    scanf("%d",&num);
    printf("%d元可以喝%d瓶\n",num,bottle_num(num));
    system("pause");
}