#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<Windows.h>
void*my_memmove(void*dest,const void*src,size_t count)
{
	char*ret = (char*)dest;
	if (dest <= src || (char*)dest >= (char*)src + count){
		while (count--){
			*(char*)dest = *(char*)src;
			dest = (char*)dest + 1;
			src = (char*)src + 1;
		}
	}
	else{
		dest = (char*)dest + count - 1;
		src = (char*)src + count - 1;
		while (count--){
			*(char*)dest =*(char*) src;
			dest = (char*)dest - 1;
			src = (char*)src - 1;
		}
	}
	return ret;
}
int main()
{
	int arr1[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int arr2[10] = { 0 };
	int i = 0;
	my_memmove(arr2,arr1,40);
	for (; i < 10; i++)
	{
		printf("%d,", arr2[i]);
	}
	printf("\n");
	system("pause");
	return 0;
}