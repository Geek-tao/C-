#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#define MaxSize 10
typedef struct
{
	int date[MaxSize];//�þ�̬������������Ԫ��
	int length;
}SqList;//˳�������Ͷ���

//��ʼ��һ��˳���
void InitList(SqList &L)
{
	for (int i = 0; i < MaxSize; i++)
		L.date[i] = 0;
	L.length = 0;//˳����ʼ����Ϊ0
}

//��L�ĵ�i��λ�ò���Ԫ��e
bool ListInsert(SqList& L, int i, int e)
{
	if (i<1 || i>L.length + 1)//�ж�i�ķ�Χ�Ƿ���Ч
		return false;
	if (L.length >= MaxSize)//��ǰ˳���洢�ռ����������ܲ���
		return false;
	for (int j = L.length; j >= i; j--)
	{
		L.date[j] = L.date[j - 1];//��˳����i�����Ժ��Ԫ��������
	}
	L.date[i - 1] = e;//��i��λ�÷���e
	L.length += 1;//˳���ǰ���ȼ�1
	return true;
}

bool ListDelete(SqList& L, int i, int& e)
{
	if (i<1 || i>L.length)//�ж�i�ķ�Χ�Ƿ���Ч
		return false;
	e = L.date[i - 1];//��Ҫɾ����Ԫ�ظ�ֵ��e
	for (int j = i; j < L.length; j++)//����i��λ�ü��Ժ��Ԫ��ǰ��
		L.date[j - 1] = L.date[j];
	L.length--;//���Ա��ȼ�1
	return true;
}

int main()
{
	SqList L;//����һ��˳�����̬����洢�ռ�
	InitList(L);
	//......�˴�ʡ��һЩ���룬���뼸��Ԫ��
	ListInsert(L, 3, 3);
	int e = -1;//�ñ���e��ɾ����Ԫ�ش�����
	if (ListDelete(L, 3, e))
		printf("��ɾ��������Ԫ�أ�ɾ��Ԫ��ֵΪ%d\n", e);
	else
		printf("λ��i���Ϸ���ɾ��ʧ��\n");
	return 0;
}


typedef struct
{
	int* date;//ָʾ��̬���������ָ��
	int MaxSize;//˳�����������
	int length;//˳���ĵ�ǰ����
}SeqList;

void InitList(SeqList& L)
{
	L.date = (int*)malloc(sizeof(int) * MaxSize);
	L.length = 0;
	L.MaxSize = MaxSize;
}

//���Ӷ�̬����ĳ���
void IncreaseSize(SeqList& L, int len)
{
	int* p = L.date;
	L.date = (int*)malloc(sizeof(int) * (L.MaxSize + len));//��������һƬ������
	for (int i = 0; i < L.length; i++)
	{
		L.date[i] = p[i];//�����ݸ��Ƶ�������
	}
	L.length = L.length + len;
	L.MaxSize = L.MaxSize + len;
	free(p);
}


int main()
{
	SeqList L;//����һ��˳���
	InitList(L);//��ʼ��˳���
	//��˳����в���ֵ......
	IncreaseSize(L, 5);
	return 0;
}
