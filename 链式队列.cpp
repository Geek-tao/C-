#define _CRT_SECURE_NO_WARNINGS 1
#include<stdlib.h>
typedef struct QNode//��ʽ���н��
{
	ElemType date;
	struct QNode* next;
}QNode;
typedef struct//������ʽ����
{
	QNode* front, * rear;//ָ����ʽ���н��Ķ�ͷ�Ͷ�βָ��
}LinkQueue;

//��ʼ������
void InitQueue(LinkQueue& Q)
{
	//��ʼʱ front��rear ָ�붼ָ��ͷ���
	Q.front = Q.rear = (QNode*)malloc(sizeof(QNode));
	Q.front->next = NULL;
}

//��Ԫ��x���(��ͷ���)
bool EnQueue(LinkQueue& Q, ElemType x)
{
	QNode* s = (QNode*)malloc(sizeof(QNode));//����һ����㣬����ָ��sָ��������
	s->date = x;
	s->next = NULL;
	Q.rear->next = s;//�½�����rear֮��
	Q.rear = s;//�޸ı�βָ��
	return true;
}

//��Ԫ��x��ӣ�����ͷ��㣩
bool EnQueue(LinkQueue& Q, ElemType x)
{
	QNode* s = (QNode*)malloc(sizeof(QNode));
	s->date = x;
	if (Q.front == NULL)//�ڿն��в����һ��Ԫ��
	{
		Q.front = s;
		Q.rear = s;
	}
	else
	{
		s->next = NULL;
		Q.rear->next = s;//�½����뵽rearָ��֮��
		Q.rear = s;//�޸�rearָ��
	}
	return true;
}

//��ͷԪ�س��ӣ���ͷ��㣩
bool DeQueue(Queue& Q, ElemType& x)
{
	if (Q.front == Q.rear)//�ӿ�
		return false;
	QNode* p = Q.front->next;//ָ��pָ��ͷ������һ����㣨���ӵĽ�㣩
	x = p->date;
	Q.front->next = p->next;
	if (p == Q.rear)//���һ��������
		Q.rear = Q.front;//�޸Ķ�βָ��
	free(p);
	return true;
}

//��ͷԪ�س��ӣ�����ͷ��㣩
bool DeQueue(LinkQueue& Q, ElemType& x)
{
	if (Q.front == NULL)//�ӿ�
		return false;
	QNode* p = Q.front;//ָ��pָ����ӽ��
	x = p->date;
	Q.front = p->next;
	if (p = Q.rear)//���һ��������
	{
		Q.front = NULL;
		Q.rear = NULL;
	}
	free(p);
	return false;
}


void testLinkQueue()
{
   LinkQueue Q;//����һ������
   InitQueue(Q);//��ʼ������

}