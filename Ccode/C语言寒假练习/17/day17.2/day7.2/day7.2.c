#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <windows.h>

int bottle_num(int yuan)//����ˮ
{
    if (yuan)//��Ԫ������ƿ
    {
        while (1 != yuan)
        {
            if (yuan & 1)//���������ƿ
            {
                return yuan - 1 + bottle_num((yuan >> 1) + 1);
            }
            else//�����ż��ƿ
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
    printf("���������Ǯ����\n");
    scanf("%d",&num);
    printf("%dԪ���Ժ�%dƿ\n",num,bottle_num(num));
    system("pause");
}