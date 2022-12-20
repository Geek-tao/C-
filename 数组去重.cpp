#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

//void Delete(int* a, int m, int n)
//{
//	if (m == n)
//		return;
//	for (int i = m+1; i < n; i++)
//	{
//		a[i - 1] = a[i];
//	}
//}
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	int con = n;
//	int a[1000];
//	for (int i = 0; i < n; i++)
//	{
//		scanf("%d", &a[i]);
//	}
//	for (int i = 0; i < n - 1; i++)
//	{
//		for (int j = i + 1; j < n; j++)
//		{
//			if (a[i] == a[j])
//			{
//				Delete(a, j, n);
//				con--;
//			}
//		}
//	}
//	for (int i = 0; i < con; i++)
//	{
//		printf("%d ", a[i]);
//	}
//	return 0;
//}
