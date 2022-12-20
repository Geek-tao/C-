#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
typedef struct Node
{
	ElemType date;
	struct Node* next;
}Node, * LinkList;

bool InitList(LinkList& L)//��ʼ��һ������������ͷ��㣩
{
	L = NULL;
	return true;
}

bool InitList(LinkList& L)//��ʼ��һ����������ͷ��㣩
{
	L = (Node*)malloc(sizeof(Node));//����һ��ͷ���
	if (L == NULL)//�ڴ治�㣬����ʧ��
		return false;
	L->next = NULL;
	return true;
}

bool Empty(LinkList L)//�жϵ�������ͷ��㣩�Ƿ�Ϊ��
{
	return (L->next == NULL);
}

//�ڵ�i��λ�ò���Ԫ��e����ͷ��㣩
bool ListInsert(LinkList& L, int i, ElemType e)
{
	if (i < 1)
		return false;
	Node* p;//ָ��pָ��ǰɨ�赽�Ľ��
	int j = 0;//��ǰpָ����ǵڼ������
	p = L;
	while (p != NULL && j < i - 1)//ѭ���ҵ���i-1�����
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

//����������P���֮�����Ԫ��e
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

//ǰ���������p���֮ǰ����Ԫ��e
bool InsertPriorNode(Node* p, ElemType e)
{
	if (p == NULL)
	{
		return false;
	}
	Node* s = (Node*)malloc(sizeof(Node));
	if (s == NULL)//�ڴ治�㣬����ʧ��
		return false;
	s->next = p->next;
	p->next = s;
	s->date = p->date;
	p->date = e;
	return true;
}

//��λ��ɾ������ͷ��㣩������e���ر�ɾ����ֵ
bool ListDelete(LinkList& L, int i, ElemType& e)
{
	if (i < 1)
		return false;
	Node* p;//ָ��pָ��ǰɨ�赽�Ľ��
	int j = 0;//ָ��pָ����ǵڼ������
	p = L;//ָ��pָ��ͷ���,ͷ����ǵ�0�����
	while (p != NULL && j < i - 1)//ѭ���ҵ���i-1�����
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

//ɾ��ָ�����p
bool DeleteNode(Node* p)
{
	if (p == NULL)
		return false;
	Node* q = p->next;
	p->date = p->next->date;//���p->next == NULL,���������
	p->next = q->next;
	free(q);
	return true;
}

//��λ���ң����ص�i��Ԫ�أ���ͷ��㣩
Node* GetElem(LinkList L, int i)
{
	if (i < 0)
		return NULL;
	Node* p;
	int j = 0;
	p = L;
	while (p != NULL && j < i)//ѭ���ҵ���i�����
	{
		p = p->next;
		j++;
	}
	return p;
}

//��ֵ���ң��ҵ�������==e�Ľ��
Node* LocateElem(LinkList L, ElemType e)
{
	Node* p = L->next;//�ӵ�һ����㿪ʼ����ֵΪe�Ľ��
	while (p != NULL && p->date != e)//���ElemType��struct���ͣ�������!=��==���жϽṹ���Ƿ���ȣ���Ӧ����һ�Աȳ�Ա�Ƿ����
	{
		p = p->next;//�ƶ�ָ�뵽��һ���
	}
	return p;//�ҵ��󷵻ظý��ָ�룬���򷵻�NULL
}

//���ĳ���
int length(LinkList L)
{
	int len = 0;//ͳ�Ʊ�
	Node* p = L;
	while (p->next != NULL)
	{
		p = p->next;
		len++;
	}
	return len;
}

//β�巨��������
LinkList List_TailInsert(LinkList &L)//������������
{
	int x;
	L = (LinkList)malloc(sizeof(Node));
	Node* s, * r = L;//rΪ��βָ��
	scanf("%d", &x);
	while (x != 9999)//����9999��ʾ����
	{
		s = (Node*)malloc(sizeof(Node));
		s->date = x;
		r->next = s;
		r = s;//rָ���µı�β���
		scanf("%d", &x);
	}
	r->next = NULL;//β���ָ���ÿ�
	return L;
}

//ͷ�巨��������
LinkList List_HeadInsert(LinkList& L)//������������
{
	Node* s;
	int x;
	L = (LinkList)malloc(sizeof(Node));//����ͷ���
	L->next = NULL;//!!!
	scanf("%d", &x);
	while (x != 9999)//����9999��ʾ����
	{
		s = (Node*)malloc(sizeof(Node));//�����½��
		s->date = x;
		s->next = L->next;
		L->next = s;
		scanf("%d", &x);
	}
	return L;
}

//���ٵ�����
bool ClearList(LinkList& L)
{
	Node* p, q;
	Node* p = L->next;//ָ��pָ���һ�����
	while (p)//��p��ΪNULLʱ��ִ�в�������p���
	{
		q = p->next;
		free(p);
		p = q;
	}
	L->next = NULL;//ͷ���ָ����Ϊ��
	return true;
}


void test()
{
	LinkList L;    //����һ��ָ�������ָ��
	InitList(L);
	//......
}

typedef struct DNode
{
	ElemType date;
	struct DNode* prior, * next;
}DNode, * DLinkList;

//��ʼ��˫����
bool InitDLinkList(DLinkList& L)
{
	L = (DNode*)malloc(sizeof(DNode));//����һ��ͷ���
	if (L = NULL)//�ڴ治�㣬����ʧ��
		return false;
	L->prior = NULL;//ͷ����prior��Զָ��NULL
	L->next = NULL;
	return true;
}

//��p�������s���
bool InsertNextDNode(DNode* p, DNode* s)
{
	if (p == NULL || s == NULL)//�Ƿ�����
		return false;
	s->next = p->next;
	if(p->next != NULL)//p����к�̽��
		p->next->prior = s;
	p->next = s;
	s->prior = p;
}

//ɾ��p���ĺ�̽��
bool DeleteNextDNode(DNode* p)
{
	if (p == NULL || p->next == NULL)
		return false;
	DNode* q = p->next;//�ҵ�p�ĺ�̽��
	p->next = q->next;
	if (q->next != NULL)
		q->next->prior = p;
	free(q);
	return true;
}

void testDLinkList()
{
	DLinkList L;//����һ��ָ��˫�����ָ��
	InitDLinkList(L);
	//......
}