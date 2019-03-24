//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<windows.h>
//#include<stdarg.h>
//#include<assert.h>
//
//void My_Print(char*type, ...)
//{
//	va_list value;
//	va_start(value, type);
//
//	while (*type != '\0')
//	{
//		if (*type == 's')
//			puts(va_arg(value, char*));
//
//		else if (*type == 'c')
//			putchar(va_arg(value, char));
//
//		else if (*type == 'd')
//		{
//			int tmp = va_arg(value, int);
//			printf("%d\n", tmp);
//		}
//		type++;
//	}
//
//	va_end(value);
//}
//int main()
//{
//	My_Print("s s d", "hello", "World!", 100);
//	system("pause");
//	return 0;
//}

//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//void bubbleSort(char *arr, int begin, int length);
//void swap(char *a, char *b);
//void Permulation(char *arr, int k, int length);
//
//int main(){
//	char arr[10];
//	int length;
//	int i;
//	while (gets(arr)){
//		length = strlen(arr);
//		bubbleSort(arr, 0, length);
//		Permulation(arr, 0, length);
//	}
//	return 0;
//}
//void Permulation(char *arr, int k, int length){
//	int i;
//	if (k == length){
//		for (i = 0; i<length; i++)
//			printf("%c", arr[i]);
//		printf("\n");
//	}
//	else{
//		for (i = k; i<length; i++){
//			if (k != i && arr[k] == arr[i])
//				continue;
//			swap(&arr[k], &arr[i]);
//			bubbleSort(arr, k + 1, length);
//			Permulation(arr, k + 1, length);
//			bubbleSort(arr, k + 1, length);
//		}
//	}
//}
//void swap(char *a, char *b){
//	char c;
//	c = *b;
//	*b = *a;
//	*a = c;
//}
//void bubbleSort(char *arr, int begin, int length){
//	int i, j;
//	for (i = begin; i<length; i++){
//		for (j = i + 1; j<length; j++){
//			if (arr[i]>arr[j]){
//				swap(&arr[i], &arr[j]);
//			}
//		}
//	}
//}
#include<iostream>
int main()
{
	std::cout << sizeof("a=10&b=20");
	system("pause");
}
