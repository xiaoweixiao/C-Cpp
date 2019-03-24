#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int arr[10]={0,1,2,3,4,5,6,7,8,9};
	int max=arr[0];
	int i=0;
	for(i=1;i<sizeof(arr)/sizeof(arr[0]);i++)
	{
		if(arr[i]>max)
			max=arr[i];
	}
	printf("max=%d\n",max);
	system("pause");
	return 0;
}