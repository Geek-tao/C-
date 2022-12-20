#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
typedef struct Node
{
	ElemType date;
	struct Node* next;
}Node, * LinkList;

bool InitList(LinkList& L)//初始化一个单链表（不带头结点）
{
	L = NULL;
	return true;
}

bool InitList(LinkList& L)//初始化一个单链表（带头结点）
{
	L = (Node*)malloc(sizeof(Node));//分配一个头结点
	if (L == NULL)//内存不足，分配失败
		return false;
	L->next = NULL;
	return true;
}

bool Empty(LinkList L)//判断单链表（带头结点）是否为空
{
	return (L->next == NULL);
}

//在第i个位置插入元素e（带头结点）
bool ListInsert(LinkList& L, int i, ElemType e)
{
	if (i < 1)
		return false;
	Node* p;//指针p指向当前扫描到的结点
	int j = 0;//当前p指向的是第几个结点
	p = L;
	while (p != NULL && j < i - 1)//循环找到第i-1个结点
	{
		p = p->next;
		j++;
	}
	if (p == NULL)
		return false;
	Node* s = (Node*)malloc(sizeof(Node));
	s->date = e;
	s->next = p->next;
	p->next = s;
	return true;
}

//后插操作：在P结点之后插入元素e
bool InsertNextNode(Node* p, ElemType e)
{
	if (p == NULL)
		return false;
	Node* s = (Node*)malloc(sizeof(Node));
	s->date = e;
	s->next = p->next;
	p->next = s;
	return true;
}

//前插操作：在p结点之前插入元素e
bool InsertPriorNode(Node* p, ElemType e)
{
	if (p == NULL)
	{
		return false;
	}
	Node* s = (Node*)malloc(sizeof(Node));
	if (s == NULL)//内存不足，分配失败
		return false;
	s->next = p->next;
	p->next = s;
	s->date = p->date;
	p->date = e;
	return true;
}

//按位序删除（带头结点），并用e返回被删除的值
bool ListDelete(LinkList& L, int i, ElemType& e)
{
	if (i < 1)
		return false;
	Node* p;//指针p指向当前扫描到的结点
	int j = 0;//指针p指向的是第几个结点
	p = L;//指针p指向头结点,头结点是第0个结点
	while (p != NULL && j < i - 1)//循环找到第i-1个结点
	{
		p = p->next;
		j++;
	}
	if (p == NULL || p->next == NULL)
		return false;
	Node* q = p->next;
	e = q->date;
	p->next = q->next;
	free(q);
	return true;
}

//删除指定结点p
bool DeleteNode(Node* p)
{
	if (p == NULL)
		return false;
	Node* q = p->next;
	p->date = p->next->date;//如果p->next == NULL,则出错！！！
	p->next = q->next;
	free(q);
	return true;
}

//按位查找：返回第i个元素（带头结点）
Node* GetElem(LinkList L, int i)
{
	if (i < 0)
		return NULL;
	Node* p;
	int j = 0;
	p = L;
	while (p != NULL && j < i)//循环找到第i个结点
	{
		p = p->next;
		j++;
	}
	return p;
}

//按值查找，找到数据域==e的结点
Node* LocateElem(LinkList L, ElemType e)
{
	Node* p = L->next;//从第一个结点开始查找值为e的结点
	while (p != NULL && p->date != e)//如果ElemType是struct类型，不能用!=或==来判断结构体是否相等，而应该逐一对比成员是否相等
	{
		p = p->next;//移动指针到下一结点
	}
	return p;//找到后返回该结点指针，否则返回NULL
}

//求表的长度
int length(LinkList L)
{
	int len = 0;//统计表长
	Node* p = L;
	while (p->next != NULL)
	{
		p = p->next;
		len++;
	}
	return len;
}

//尾插法建立链表
LinkList List_TailInsert(LinkList &L)//正向建立单链表
{
	int x;
	L = (LinkList)malloc(sizeof(Node));
	Node* s, * r = L;//r为表尾指针
	scanf("%d", &x);
	while (x != 9999)//输入9999表示结束
	{
		s = (Node*)malloc(sizeof(Node));
		s->date = x;
		r->next = s;
		r = s;//r指向新的表尾结点
		scanf("%d", &x);
	}
	r->next = NULL;//尾结点指针置空
	return L;
}

//头插法建立链表
LinkList List_HeadInsert(LinkList& L)//逆向建立单链表
{
	Node* s;
	int x;
	L = (LinkList)malloc(sizeof(Node));//创建头结点
	L->next = NULL;//!!!
	scanf("%d", &x);
	while (x != 9999)//输入9999表示结束
	{
		s = (Node*)malloc(sizeof(Node));//创建新结点
		s->date = x;
		s->next = L->next;
		L->next = s;
		scanf("%d", &x);
	}
	return L;
}

//销毁单链表
bool ClearList(LinkList& L)
{
	Node* p, q;
	Node* p = L->next;//指针p指向第一个结点
	while (p)//当p不为NULL时，执行操作销毁p结点
	{
		q = p->next;
		free(p);
		p = q;
	}
	L->next = NULL;//头结点指针域为空
	return true;
}


void test()
{
	LinkList L;    //声明一个指向单链表的指针
	InitList(L);
	//......
}

typedef struct DNode
{
	ElemType date;
	struct DNode* prior, * next;
}DNode, * DLinkList;

//初始化双链表
bool InitDLinkList(DLinkList& L)
{
	L = (DNode*)malloc(sizeof(DNode));//分配一个头结点
	if (L = NULL)//内存不足，分配失败
		return false;
	L->prior = NULL;//头结点的prior永远指向NULL
	L->next = NULL;
	return true;
}

//在p结点后插入s结点
bool InsertNextDNode(DNode* p, DNode* s)
{
	if (p == NULL || s == NULL)//非法参数
		return false;
	s->next = p->next;
	if(p->next != NULL)//p结点有后继结点
		p->next->prior = s;
	p->next = s;
	s->prior = p;
}

//删除p结点的后继结点
bool DeleteNextDNode(DNode* p)
{
	if (p == NULL || p->next == NULL)
		return false;
	DNode* q = p->next;//找到p的后继结点
	p->next = q->next;
	if (q->next != NULL)
		q->next->prior = p;
	free(q);
	return true;
}

void testDLinkList()
{
	DLinkList L;//声明一个指向双链表的指针
	InitDLinkList(L);
	//......
}