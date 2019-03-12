#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

const int length = 10;  // 定义杨辉三角的大小

int main(void)
{
	int nums[10][10]={0};
    int i, j;
    /*计算杨辉三角*/ 
    for(i=0; i<length; i++)
    {
        nums[i][0] = 1;
        nums[i][i] = 1;
        for(j=1; j<i; j++)
            nums[i][j] = nums[i-1][j-1] + nums[i-1][j];
    }

    /*打印输出*/ 
    for(i=0; i<length; i++)
    {
        for(j=0; j<length-i-1; j++)
            printf("   ");
        for(j=0; j<=i; j++)
            printf("%-5d ", nums[i][j]);
        putchar('\n');
    }
    getchar();// 暂停 
    return EXIT_SUCCESS;
}