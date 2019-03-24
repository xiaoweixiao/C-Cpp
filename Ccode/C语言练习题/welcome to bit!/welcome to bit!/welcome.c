#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
int main()
{
	
	char arr1[]={"***************"};
	char arr2[]={"welcome to bit!"};
	int left=0;
	int right=strlen(arr1)-1;//sizeof(arr1)/sizeof(arr1[0])-2
	printf("%s\n",arr1);
	while(left<=right)
	{
		Sleep(1000);
		arr1[left]=arr2[left];
		arr1[right]=arr2[right];
		left++;
		right--;
		printf("%s\n",arr1);
	}
	system("pause");
	return 0;
}
