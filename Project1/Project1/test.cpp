//#include<stdio.h>  
//#include<stdlib.h>  
//unsigned int  reverse_bit(unsigned int value)
//{
//	unsigned sum = 0;
//	int i = 0;
//	for (i = 0; i<32; i++)
//	{
//		sum += ((value >> i) & 1) << (31 - i);
//	}
//	return sum;
//}
//int main()
//{
//	unsigned int n;
//	scanf("%d", &n);
//	unsigned c = reverse_bit(n);
//	printf("%u", c);
//	system("pause");
//	return 0;
//}


//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<Windows.h>

//void left_mov(char s[], int k, int len)
//{
//	k = k%len;
//	char *p = (char *)malloc((2 * len + 1)*sizeof(char));
//	strcpy(p, s);
//	strcat(p, s);
//	strncpy(s, p + k, len - 1);
//	free(p);
//}
//��������
//void left_mov(char str[], int left, int sz)
//{
//	int i = 0;
//	left = left%sz;
//	for (i = 0; i < left; i++)
//	{
//		char tmp = str[0];
//		int j = 0;
//		for (j = 0; j < sz - 1; j++)
//		{
//			str[j] = str[j + 1];
//		}
//		str[j] = tmp;
//	}
//}
//int main()
//{
//	char str[] = { "ABCDEF" };
//	int left = 1;
//	int sz = sizeof(str) / sizeof(str[0]);
//	printf("����֮ǰ���ַ����ǣ�%s\n", str);
//	left_mov(str, left, sz);
//	printf("����֮����ַ����ǣ�%s\n", str);
//	system("pause");
//	return 0;
//}

//��������
//void Reverse(char*start, char*end)
//{
//  while (start < end)
//  {
//      *start ^= *end;
//      *end ^= *start;
//      *start ^= *end;
//      start++;
//      end--;
//  }
//}
//void left_mov(char str[], int left, int sz)
//{
//  left = left%sz;
//  Reverse(str, str + left - 1);
//  Reverse(str + left, str + sz-1);
//  Reverse(str, str + sz-1);
//}
//#include<iostream>
//using namespace std;
//class AAA{
//	int _a;
//public:
//	AAA(int a = 30)
//		:_a(a)
//	{
//		cout << "construct" << endl;
//	}
//	~AAA()
//	{
//
//	}
//};
//int main()
//{
//	int*p = new int[3];
//	return 0;
//}




//int main()
//{
//	struct node
//	{
//		unsigned int a : 4;     //λ��a��ռ4λ
//		unsigned int : 0;     //����λ�Σ�ռ0λ
//		unsigned int b : 4;     //λ��b��ռ4λ
//		int c : 32;             //λ��c��ռ32λ
//		int : 6;              //����λ�Σ�ռ6λ
//	};
//	printf("%d", sizeof(node));
//	system("pause");
//}
