#include<stdio.h>
void huhuan(int *, int *);
int main()
{
	int a, b;
	printf("����������������\n");
	scanf("%d%d", &a, &b);
	huhuan(&a, &b);
	printf("a = %d,b = %d\n", a, b);
	return 0;
}
void huhuan(int * p, int * q)
{
	int t;
	t = *p;
	*p = *q;
	*q = t;
	return;
}