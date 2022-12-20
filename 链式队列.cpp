#define _CRT_SECURE_NO_WARNINGS 1
#include<stdlib.h>
typedef struct QNode//链式队列结点
{
	ElemType date;
	struct QNode* next;
}QNode;
typedef struct//定义链式队列
{
	QNode* front, * rear;//指向链式队列结点的队头和队尾指针
}LinkQueue;

//初始化队列
void InitQueue(LinkQueue& Q)
{
	//初始时 front、rear 指针都指向头结点
	Q.front = Q.rear = (QNode*)malloc(sizeof(QNode));
	Q.front->next = NULL;
}

//新元素x入队(带头结点)
bool EnQueue(LinkQueue& Q, ElemType x)
{
	QNode* s = (QNode*)malloc(sizeof(QNode));//分配一个结点，并用指针s指向这个结点
	s->date = x;
	s->next = NULL;
	Q.rear->next = s;//新结点插入rear之后
	Q.rear = s;//修改表尾指针
	return true;
}

//新元素x入队（不带头结点）
bool EnQueue(LinkQueue& Q, ElemType x)
{
	QNode* s = (QNode*)malloc(sizeof(QNode));
	s->date = x;
	if (Q.front == NULL)//在空队列插入第一个元素
	{
		Q.front = s;
		Q.rear = s;
	}
	else
	{
		s->next = NULL;
		Q.rear->next = s;//新结点插入到rear指针之后
		Q.rear = s;//修改rear指针
	}
	return true;
}

//队头元素出队（带头结点）
bool DeQueue(Queue& Q, ElemType& x)
{
	if (Q.front == Q.rear)//队空
		return false;
	QNode* p = Q.front->next;//指针p指向头结点的下一个结点（出队的结点）
	x = p->date;
	Q.front->next = p->next;
	if (p == Q.rear)//最后一个结点出队
		Q.rear = Q.front;//修改队尾指针
	free(p);
	return true;
}

//队头元素出队（不带头结点）
bool DeQueue(LinkQueue& Q, ElemType& x)
{
	if (Q.front == NULL)//队空
		return false;
	QNode* p = Q.front;//指针p指向出队结点
	x = p->date;
	Q.front = p->next;
	if (p = Q.rear)//最后一个结点出队
	{
		Q.front = NULL;
		Q.rear = NULL;
	}
	free(p);
	return false;
}


void testLinkQueue()
{
   LinkQueue Q;//声明一个队列
   InitQueue(Q);//初始化队列

}