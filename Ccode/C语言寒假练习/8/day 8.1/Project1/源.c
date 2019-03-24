#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int a = 1;
	int b = 1;
	int c = 1;
	int d = 1;
	int e = 1;
	for (; a <= 5; a++){
		for (b = 1; b <= 5; b++){
			for (c = 1; c <= 5; c++){
				for (d = 1; d <= 5; d++){
					for (e = 1; e <= 5; e++){
						if (((b == 2) + (a == 3) == 1)\
							&& ((b == 2) + (e == 4) == 1)\
							&& ((c == 1) + (d == 2) == 1)\
							&& ((c == 5) + (d == 3) == 1)\
							&& ((e == 4) + (a == 1) == 1)\
							&&(a!=b)&&(a!=c)&&(a!=d)&&(a!=e)\
							&&(b!=c)&&(b!=d)&&(b!=e)&&(c!=d)&&(c!=e)&&(d!=e)){
							printf("final result:a=%d,b=%d,c=%d,d=%d,e=%d\n", \
								a, b, c, d, e);
									}
							    }
							}
						}
					}
				}
	system("pause");
	return 0;
}
