#include"test.h"

int main()
{
	Test();
	system("pause");
	return 0;
}


//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<windows.h>
//#include<stdarg.h>
//#include<assert.h>
//
//void printf_a(char*tmp, ...)//tmp��"s ccc d.\n"�ĵ�ַ
//{
//	va_list str;//���ɱ����������һ������������"s ccc d.\n"��"hello", 'b', 'i', 't', 100)�ĵ�ַ
//	va_start(str, tmp);//strָ����"hello"
//
//	while (*tmp != '\0')//'\0'���ַ���������־
//	{
//		if (*tmp == 's')
//			puts(va_arg(str, char*));
//
//		else if (*tmp == 'c')
//			putchar(va_arg(str, char));
//
//		else if (*tmp == 'd')
//		{
//			int val = va_arg(str, int);
//			printf("%d", val);
//		}
//
//		tmp++;//��ӡ��һ�Σ�����ָ��ǿɱ������������Ҫ����
//	}
//
//	va_end(str);
//}
//int main()
//{
//	printf_a("s ccc d.\n", "hello", 'b', 'i', 't', 100);
//	system("pause");
//	return 0;
//}
//#define _CRT_SECURE_NO_WARNINGS  
//#include<stdio.h>  
//#include<stdlib.h>  
//#include<stdarg.h>  
//void print(char *tmp, ...)   //ʵ�ֿɱ��β�  
//{
//	va_list arg;        //����va_list���͵ı���arg�����ڷ��ʲ����б��δȷ������  
//	va_start(arg, tmp); //����va_start����ʼ������ʼ�����̰�arg��������Ϊָ��ɱ�������ֵĵ�һ��������  
//	while (*tmp != '\0')//���ĵ�һ��������va_list�ı���������2��������ʡ�Ժ�ǰ���һ�������ֵĲ�����  
//	{
//		if (*tmp == 'c')
//		{
//			putchar(va_arg(arg, char));//����va_arg�����ʲ�����������������������va_list�����Ͳ����б�����һ�����������͡�  
//		}
//		else if (*tmp == 's')
//		{
//			puts(va_arg(arg, char*));
//		}
//		else if (*tmp == 'd')
//		{
//			int d = va_arg(arg, int);
//			printf("%d\n", d);
//		}
//		tmp++;
//	}
//	va_end(arg);     //�����������һ���ɱ����֮��������Ҫ����va_end��  
//}
//int main()
//{
//	print("s ccc d.\n", "hello", 'b', 'i', 't', 100);
//	system("pause");
//	return 0;
//}
//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<stdlib.h>
//int main()
//{
//	char killer = 0;
//	for (killer = 'A'; killer <= 'D'; killer++)
//	{
//		if (((killer != 'A') + (killer == 'C') + (killer == 'D') + (killer != 'D')) == 3)
//		{
//			printf("%c\n", killer);
//			break;
//		}
//	}
//	system("pause");
//	return 0;
//}
//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<stdlib.h>
//#include<math.h>
//int main()
//{
//	for (int i = 0; i<1000; i++)
//	{
//		//�����i�����Ǽ�λ��
//		int tmp = i;
//		int count = 1;//count��ʾi��λ��
//		
//		while (tmp>9)
//		{
//			count++;
//			tmp = tmp / 10;
//		}
//
//		//�����i�����ĸ���λ��count�η��ĺ�sum
//		tmp = i;
//		int sum = 0;
//		while (tmp)
//		{
//			sum = sum + pow((float)(tmp % 10), count);//tmp%10,ȡ�����λ����ֵ
//			tmp = tmp / 10;//ȥ�����λ
//		}
//
//		if (sum == i)
//			printf("%d ", i);
//	}
//
//	printf("\n");
//	system("pause");
//	return 0;
//}
//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<stdlib.h>
//#include<time.h>
//#include<math.h>
//int main()
//{
//	srand((unsigned int)time(NULL));
//	for (int i = 0; i < 50; ++i)
//		printf("%d ", rand());
//	system("pause");
//	return 0;
//}
//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<stdlib.h>
//int main()
//{
//	int n = 0;
//	int count = 0;
//	scanf("%d", &n);
//	while (n)
//	{
//		n = n&(n - 1);
//		count++;
//	}
//	printf("%d\n", count);
//	system("pause");
//	return 0;
//	//1101--n
//	//1100
//	//1100--n
//	//1011
//	//1000--n
//	//0111
//	//0000--n
//}
