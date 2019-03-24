#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
//void swap(int *a,int *b)
//{
//	int t;
//	t=*a;
//	*a=*b;
//	*b=t;
//};
int main()
{
	int arr1[10]={0,1,2,3,4,5,6,7,8,9};
	int arr2[10]={10,11,12,13,14,15,16,17,18,19};
	int i=0;
	printf("arr1=");
	for(i=0;i<sizeof(arr1)/sizeof(arr1[0]);i++)
	{
		printf("%d ",arr1[i]);
	};
	printf("\narr2=");
	for(i=0;i<sizeof(arr2)/sizeof(arr2[0]);i++)
	{
		printf("%d ",arr2[i]);
	};
	printf("\n________________________________________________\n");
	for(i=0;i<sizeof(arr1)/sizeof(arr1[0]);i++)
		{
			int tmp=arr1[i];
			arr1[i]=arr2[i];
			arr2[i]=tmp;/*swap(&arr1[i],&arr2[i]);*/
	};
	printf("arr1=");
	for(i=0;i<sizeof(arr1)/sizeof(arr1[0]);i++)
	{
		printf("%d ",arr1[i]);
	};
	printf("\narr2=");
	for(i=0;i<sizeof(arr2)/sizeof(arr2[0]);i++)
	{
		printf("%d ",arr2[i]);
	};
	printf("\n");
	system("pause");
	return 0;
}