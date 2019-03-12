#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<windows.h>
int main()
{
	/*int arr[]={1,2,3,4,5,6,7,8,9,0};
	printf("%p\n",arr);
	printf("%d\n",*arr);*/



	/*int a[10]={0};
	int i=0;
	for(i=0;i<10;i++)
	{
		a[i]=i;	
	}

	for(i=0;i<10;i++)
	{
		printf("%d	",a[i]);
		printf("%p\n",&a[i]);
	}*/



	/*int arr[10]={0};
	int i=0;
	int *p=arr;
	for(i=0;i<sizeof(arr)/sizeof(arr[0]);++i)
	{
		*(p+i)=i;
	}
	for(i=0;i<sizeof(arr)/sizeof(arr[0]);++i)
	{
		printf("&arr[%d]=%p	",i,&arr[i]);
		printf("%d\n",*(p+i));
		printf("%p\n",arr+i);
	}*/


	int a[]={1,2,3,4};
	printf("%d\n",sizeof(a));
	printf("%d\n",sizeof(a+0));
	printf("%d\n",sizeof(*a));
	printf("%d\n",sizeof(a+1));
	printf("%d\n",sizeof(a[1]));
	printf("%d\n",sizeof(&a));


	printf("%d\n",sizeof(&a+1));
	printf("%d\n",sizeof(&a[0]));
	printf("%d\n",sizeof(&a[0]+1));
	system("pause");
return 0;
}