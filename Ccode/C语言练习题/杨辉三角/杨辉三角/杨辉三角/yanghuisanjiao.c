#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

const int length = 10;  // ����������ǵĴ�С

int main(void)
{
	int nums[10][10]={0};
    int i, j;
    /*�����������*/ 
    for(i=0; i<length; i++)
    {
        nums[i][0] = 1;
        nums[i][i] = 1;
        for(j=1; j<i; j++)
            nums[i][j] = nums[i-1][j-1] + nums[i-1][j];
    }

    /*��ӡ���*/ 
    for(i=0; i<length; i++)
    {
        for(j=0; j<length-i-1; j++)
            printf("   ");
        for(j=0; j<=i; j++)
            printf("%-5d ", nums[i][j]);
        putchar('\n');
    }
    getchar();// ��ͣ 
    return EXIT_SUCCESS;
}