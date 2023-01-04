#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#define MaxSize 10//定义队列中元素的最大个数
typedef struct
{
	ElemType date[MaxSize];//用静态数组存放队列元素
	int front, rear;//队头指针和队尾指针
}SqQueue;//定义顺序队列的类型

//初始化队列
void InitQueue(SqQueue& Q)
{
	Q.front = Q.rear = 0;//初始时 队头、队尾指针指向0
}

//入队
bool EnQueue(SqQueue& Q, ElemType x)
{
	if ((Q.rear + 1) % MaxSize == Q.front)//队满则报错
		return false;
	Q.date[Q.rear] = x;
	Q.rear = (Q.rear + 1) % MaxSize;//用模运算将存储空间在逻辑上变成环状
	return true;
}

//出队（删除一个队头元素，并用x返回）
bool DeQueue(SqQueue& Q, ElemType& x)
{
	if (Q.front == Q.rear)//队空则报错
		return false;
	x = Q.date[Q.front];
	Q.front = (Q.front + 1) % MaxSize;//队头指针循环加1
	return true;
}


void testQueue()
{
	SqQueue Q;//声明一个队列（顺序存储）
	InitQueue(Q);
}