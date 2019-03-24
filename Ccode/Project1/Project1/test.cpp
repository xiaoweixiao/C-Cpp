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
//void printf_a(char*tmp, ...)//tmp是"s ccc d.\n"的地址
//{
//	va_list str;//给可变参数定义了一个变量来接收"s ccc d.\n"，"hello", 'b', 'i', 't', 100)的地址
//	va_start(str, tmp);//str指向了"hello"
//
//	while (*tmp != '\0')//'\0'是字符串结束标志
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
//		tmp++;//打印完一段，这里指向非可变参数变量，需要跳过
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
//void print(char *tmp, ...)   //实现可变形参  
//{
//	va_list arg;        //声明va_list类型的变量arg，用于访问参数列表的未确定部分  
//	va_start(arg, tmp); //调用va_start来初始化。初始化过程把arg变量设置为指向可变参数部分的第一个参数。  
//	while (*tmp != '\0')//它的第一个参数是va_list的变量名，第2个参数是省略号前最后一个有名字的参数。  
//	{
//		if (*tmp == 'c')
//		{
//			putchar(va_arg(arg, char));//定义va_arg来访问参数，这个宏接受两个参数：va_list变量和参数列表中下一个参数的类型。  
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
//	va_end(arg);     //当访问完最后一个可变参数之后，我们需要调用va_end。  
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
//		//计算第i个数是几位的
//		int tmp = i;
//		int count = 1;//count表示i的位数
//		
//		while (tmp>9)
//		{
//			count++;
//			tmp = tmp / 10;
//		}
//
//		//计算第i个数的各个位的count次方的和sum
//		tmp = i;
//		int sum = 0;
//		while (tmp)
//		{
//			sum = sum + pow((float)(tmp % 10), count);//tmp%10,取得最低位的数值
//			tmp = tmp / 10;//去掉最低位
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
