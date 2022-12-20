#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

int main()
{
	char c;
	while ((c = getchar()) != '\n')
	{
		if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		{
			c = c + 4;
			if (c >= 'Z' && c <= 'Z' + 4 || c >= 'z')
				c = c - 26;
		}
		putchar(c);
	}
	putchar('\n');
	return 0;
}