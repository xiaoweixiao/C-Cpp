//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<stdlib.h>
//int main()
//{
//	int n=0;
//	int i=0;
//	int count=0;
//	scanf("%d",&n);
//	for(i=0;i<32;i++)
//	{
//		if(((n>>i)&1)==1)
//			count ++;
//	}
//	printf("%d",count);
//	system("pause");
//	return 0;
//}



#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int n=0;
	int count=0;
	scanf("%d",&n);
	while(n)
	{
		n=n&(n-1);
		count ++;
	}
	printf("%d\n",count);
	system("pause");
	return 0;
			//1101--n
		 	//1100
		 	//1100--n
		 	//1011
		 	//1000--n
		 	//0111
		 	//0000--n
}
