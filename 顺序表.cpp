#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#define MaxSize 10
typedef struct
{
	int date[MaxSize];//用静态的数组存放数据元素
	int length;
}SqList;//顺序表的类型定义

//初始化一个顺序表
void InitList(SqList &L)
{
	for (int i = 0; i < MaxSize; i++)
		L.date[i] = 0;
	L.length = 0;//顺序表初始长度为0
}

//在L的第i的位置插入元素e
bool ListInsert(SqList& L, int i, int e)
{
	if (i<1 || i>L.length + 1)//判断i的范围是否有效
		return false;
	if (L.length >= MaxSize)//当前顺序表存储空间已满，不能插入
		return false;
	for (int j = L.length; j >= i; j--)
	{
		L.date[j] = L.date[j - 1];//将顺序表第i个及以后的元素往后移
	}
	L.date[i - 1] = e;//第i个位置放入e
	L.length += 1;//顺序表当前长度加1
	return true;
}

bool ListDelete(SqList& L, int i, int& e)
{
	if (i<1 || i>L.length)//判断i的范围是否有效
		return false;
	e = L.date[i - 1];//将要删除的元素赋值给e
	for (int j = i; j < L.length; j++)//将第i个位置及以后的元素前移
		L.date[j - 1] = L.date[j];
	L.length--;//线性表长度减1
	return true;
}

int main()
{
	SqList L;//声明一个顺序表，静态分配存储空间
	InitList(L);
	//......此处省略一些代码，插入几个元素
	ListInsert(L, 3, 3);
	int e = -1;//用变量e把删除的元素带回来
	if (ListDelete(L, 3, e))
		printf("已删除第三个元素，删除元素值为%d\n", e);
	else
		printf("位序i不合法，删除失败\n");
	return 0;
}


typedef struct
{
	int* date;//指示动态分配数组的指针
	int MaxSize;//顺序表的最大容量
	int length;//顺序表的当前长度
}SeqList;

void InitList(SeqList& L)
{
	L.date = (int*)malloc(sizeof(int) * MaxSize);
	L.length = 0;
	L.MaxSize = MaxSize;
}

//增加动态数组的长度
void IncreaseSize(SeqList& L, int len)
{
	int* p = L.date;
	L.date = (int*)malloc(sizeof(int) * (L.MaxSize + len));//重新申请一片新区域
	for (int i = 0; i < L.length; i++)
	{
		L.date[i] = p[i];//将数据复制到新区域
	}
	L.length = L.length + len;
	L.MaxSize = L.MaxSize + len;
	free(p);
}


int main()
{
	SeqList L;//声明一个顺序表
	InitList(L);//初始化顺序表
	//往顺序表中插入值......
	IncreaseSize(L, 5);
	return 0;
}
