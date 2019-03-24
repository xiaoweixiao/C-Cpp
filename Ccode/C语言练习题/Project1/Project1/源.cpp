#include<stdio.h>
#include<math.h>

int main()
{
	float x[13] = { 0, 0.3, 0.6, 0.9, 1.2, 1.5, 1.8, 2.1, 2.4, 2.7, 3.0, 3.3, 3.6 };
	float s[13] = { 101.2, 87.7, 85.6, 81.7, 77.2, 76.4, 75.5, 73.2, 75.9, 72.8, 70.3, 71.3, 69.6 };

	float b[13] = { 0 };
	for (int i = 0; i < 13; i++)
	{
		b[i] = s[13] / 101.2;
	}
	float w;
	for (int i = 0; i < 13; i++)
	{
		w = b[i] * x[i] * exp(-a*x[i]) - x[i] * exp(-2 * a*x[i]);
	}
}