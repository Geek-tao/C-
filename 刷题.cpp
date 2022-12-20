#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

int n = 0;
struct student
{
	char id[9];
	char name[8];
	float score;
	char remark[20];
}stu[40];

void input(struct student* stu)
{
	for (int i = 0; i < n; i++)
	{
		scanf("%s%s%f%s", stu[i].id, stu[i].name, &stu[i].score, stu[i].remark);
	}
}

void sort(struct student* stu)
{
	int flag = 1;
	for (int i = 0; i < n-1; i++)
	{
		for (int j = 0; j < n - 1 - i; j++)
		{
			if (stu[j].score < stu[j + 1].score)
			{
				struct student temp = stu[j];
				stu[j] = stu[j + 1];
				stu[j + 1] = temp;
				flag = 0;
			}

		}
		if (flag == 1)
			break;
	}
}

void print(struct student* stu)
{
	for (int i = 0; i < n; i++)
	{
		printf("%s %s %f %s", stu[i].id, stu[i].name, stu[i].score, stu[i].remark);
		printf("\n");
	}
}
int main()
{
	scanf("%d", &n);
	input(stu);
	sort(stu);
	print(stu);
	return 0;
}

