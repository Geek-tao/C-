#include<stdio.h>
	int main()
	{
		int year, leap;
		do
		{
			printf("请输入年份：");
			scanf("%d", &year);
			if (year % 4 == 0)
			{
				if (year % 100 == 0)
				{
					if (year % 400 == 0)
						leap = 1;
					else
						leap = 0;
				}
				else
					leap = 1;
			}
			else
				leap = 0;
			if (leap)
				printf("%d is a leap year\n", year);
			else
				printf("%d is not a leap year\n", year);
			printf("你是否需要继续(0/1):\n");
			int i;
			scanf("%d", &i);
			if (i == 1)
				;
			else
				break;

		} while (1);
		return 0;
	}
