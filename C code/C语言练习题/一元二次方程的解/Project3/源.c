#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>
#include<stdlib.h>

#define ZERO 0.00000000001

int main()
{
	double a, b, c;
	printf("请依次输入一元二次方程的参数>\n");
	while (scanf("%lf%lf%lf", &a, &b, &c))
	{
		if ((a > -ZERO) && (a < ZERO))
			printf("%lf\n", -b / c);
		else
		{
			double z = pow(b,2) - 4 * a*c;
			if ((z>-ZERO) && (z < ZERO))
				printf("%lf\n", (-b) / (2 * a));
			else if (z - ZERO>0)
				printf("%lf\n%lf\n", (-b + sqrt(z))/2*a, (-b - sqrt(z))/2*a);
			else
				printf("此题无实数解\n");
		}
	}
	
	system("pause");
	return 0;
}