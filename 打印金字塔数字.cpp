#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main()
{
	int i, j, a, k, m;

	for (i = 1; i <= 11; i++)
	{
		for (k = 11-i; k >= 0; k--)
		{
			printf("   ");
		}
		for (j = 0,a = 1; j < i; j++)
		{

			printf("%2d ", a);
			a += 2;
		}
		for (m = 1,a = a-4; m < i; m++)
		{
			printf("%2d ", a);
			a -= 2;
		}
		printf("\n");
	}
	return 0;
}