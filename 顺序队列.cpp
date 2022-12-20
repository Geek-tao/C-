#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#define MaxSize 10//���������Ԫ�ص�������
typedef struct
{
	ElemType date[MaxSize];//�þ�̬�����Ŷ���Ԫ��
	int front, rear;//��ͷָ��Ͷ�βָ��
}SqQueue;//����˳����е�����

//��ʼ������
void InitQueue(SqQueue& Q)
{
	Q.front = Q.rear = 0;//��ʼʱ ��ͷ����βָ��ָ��0
}

//���
bool EnQueue(SqQueue& Q, ElemType x)
{
	if ((Q.rear + 1) % MaxSize == Q.front)//�����򱨴�
		return false;
	Q.date[Q.rear] = x;
	Q.rear = (Q.rear + 1) % MaxSize;//��ģ���㽫�洢�ռ����߼��ϱ�ɻ�״
	return true;
}

//���ӣ�ɾ��һ����ͷԪ�أ�����x���أ�
bool DeQueue(SqQueue& Q, ElemType& x)
{
	if (Q.front == Q.rear)//�ӿ��򱨴�
		return false;
	x = Q.date[Q.front];
	Q.front = (Q.front + 1) % MaxSize;//��ͷָ��ѭ����1
	return true;
}


void testQueue()
{
	SqQueue Q;//����һ�����У�˳��洢��
	InitQueue(Q);
}