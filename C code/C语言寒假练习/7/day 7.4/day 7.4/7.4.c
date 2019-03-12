#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
 void Init(int arr[], int sz, int set)
 {
 	int i = 0;
 	for(i=0; i<sz; i++)
 	{
 		arr[i] = set;
 	}
 }
void Print(int arr[], int sz)
 {
 	int i = 0;
 	for(i=0; i<sz; i++)
 	{
 		printf("%d ", arr[i]);
 	}
 	printf("\n");
 }
 
 void Empty(int arr[], int sz)
 {
 	int i = 0;
 	for(i=0; i<sz; i++)
 	{
 		arr[i] = 0;
 	}
 }
 
 void Reverse(int arr[], int sz)
 {
 	int left = 0;
 	int right = sz-1;
 
 	while(left<right)
 	{
 		int tmp = arr[left];
 		arr[left] = arr[right];
 		arr[right] = tmp;
 		left++;
 		right--;
 	}
 }
 int main()
 {
 	int arr[10] = {1,2,3,4,5,6,7,8,9,10};
 	int arr2[20] = {0};
 	int sz = sizeof(arr)/sizeof(arr[0]);
 	Print(arr, sz);
	Reverse(arr, sz);
	Print(arr, sz);
	Init(arr, sz, 4);
	Print(arr, sz);
	system("pause");
 	return 0;
 }
