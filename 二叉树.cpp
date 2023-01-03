#define _CRT_SECURE_NO_WARNINGS 1
#define MaxSize 100
#include<stdio.h>
#include<stdlib.h>
struct TreeNode
{
	int value;//����е�����Ԫ��
	bool isEmpty;//����Ƿ�Ϊ��
};//�������Ľ������

TreeNode t[MaxSize];//��������t�洢���Ľ��

for (int i = 0; i < MaxSize; i++)
{
	t[i].isEmpty = true;
}//��ʼ�����н����Ϊ��

typedef struct BiTNode
{
	ElemType date;
	struct BiTNode* lchild, * rchild;
}BiTNode, * BiTree;//��ʽ�洢�������Ľ��

//�������
void PreOrder(BiTree T)
{
	if (T != NULL)
	{
		visit(T);//���ʸ����
		PreOrder(T->lchild);//�ݹ����������
		PreOrder(T->rchild);//�ݹ����������
	}
}

//�������
void InOrder(BiTree T)
{
	if (T != NULL)
	{
		InOrder(T->lchild);
		visit(T);
		InOrder(T->rchild);
	}
}

//�������
void PostOrder(BiTree T)
{
	if (T != NULL)
	{
		PostOrder(T->lchild);
		PostOrder(T->rchild);
		vist(T);
	}
}

//��������ĸ߶ȣ���ȣ�
int treeDepth(BiTree T)
{
	if (T == NULL)
		return 0;
	int l = treeDepth(T->lchild);
	int r = treeDepth(T->rchild);
	return l > r ? l + 1 : r + 1;
}

//�������
typedef struct LinkNode
{
	BiTNode* date;//�洢����������ָ��
	LinkNode* next;
}LinkNode;

typedef struct
{
	LinkNode* front, * rear;//�������ж�ͷ��βָ��
}LinkQueue;

void LevelOrder(BiTree T)
{
	LinkQueue Q;
	InitQueue(Q);//��ʼ����������
	BiTree p;//�������ճ��ӵĶ�ͷָ��
	EnQueue(Q, T);
	while (!IsEmpty(Q))//���в�Ϊ��
	{
		DeQueue(Q, p);//��ͷָ����Ӹ�ֵ��p
		visit(p);
		if (p->lchild != NULL)
			EnQueue(Q, p->lchild);
		if (p->rchild != NULL)
			EnQueue(Q, p->rchild);//���Һ������
	}
}

//�������������
typedef struct ThreadNode
{
	ElemType date;
	ThreadNode* lchild, * rchild;
	int ltag, rtag;//����������־
}ThreadNode, * ThreadTree;

ThreadNode* pre = NULL;//ȫ�ֱ���,ָ��ǰ���ʽ���ǰ��
//����������������
void CreateInThread(ThreadTree T)
{
	if (T != NULL)
	{
		InThread(T);
		if (pre->rchild == NULL)
			pre->rtag = 1;//������������һ�����
	}
}

//���������������һ�߱���һ��������
void InThread(ThreadTree T)
{
	if (T != NULL)
	{
		InThread(T->lchild);
		visit(T);
		InThread(T->rchild);
	}
}

//���������������һ�߱���һ��������
void PreThread(ThreadTree T)
{
	visit(T);
	if (T->ltag == 0)//lchild����ǰ�����������ltag = 1�����ְ���ħ��תȦȦ
	PreThread(T->lchild);
	PreThread(T->rchild);
}


void visit(ThreadNode* q)
{
	if (q->lchild == NULL)//������Ϊ�գ�����ǰ������
	{
		q->lchild = pre;
		q->ltag = 1;
	}
	if (pre != NULL && pre->rchild == NULL)
	{
		pre->rchild = q;//����ǰ�����ĺ������
		pre->rtag = 1;
	}
	pre = q;
}

//����������������������
//�ҵ���pΪ�����������У���һ������������Ľ��
ThreadNode* Firstnode(ThreadNode* p)
{
	while (p->ltag == 0)
		p = p->lchild;//ѭ���ҵ������½��
	return p;
}

//�������������������ҵ����p�ĺ�̽��
ThreadNode* Nextnode(ThreadNode* p)
{
	if (p->rtag == 0)
		return Firstnode(p->rchild);//�ҵ��������������½��
	else
		return p->rchild;
}

//��������������������ǰ��
ThreadNode* Lastnode(ThreadNode* p)
{
	while (p->rtag == 0)
		p = p->rchild;
	return p;
}

ThreadNode* Prenode(ThreadNode* p)
{
	if (p->ltag == 0)
		return Lastnode(p->lchild);
	else
		return p->lchild;
}

//˫�ױ�ʾ��(˳��洢)
#define MAX_TREE_SIZE 100  //�����������
typedef struct PTNode//���Ľ�㶨��
{
	ElemType date;   //����Ԫ��
	int parent;      //˫��λ����
}PTNode;

typedef struct//�������Ͷ���
{
	PTNode nodes[MAX_TREE_SIZE];
	int n;                       //�����
}PTree;

//���ӱ�ʾ��(˳��+��ʽ�洢)
typedef struct CTNode
{
	int child;//���ӽ���������е�λ��
	struct CTNode* next;
}CTNode;

typedef struct
{
	ElemType date;
	CTNode* firstChild;//��һ�����ӵ�ָ��
}CTBox;

typedef struct
{
	CTBox nodes[MAX_TREE_SIZE];
	int n, r;//������͸���λ��
}CTree;

//�����ֵܱ�ʾ��
typedef struct CSNode
{
	ElemType date;
	struct CSNode* firstchild, * nextsibling;
}CSNode, * CSTree;

//���������(Binary Search Tree) 
typedef struct BSTNode
{
	int key;
	struct BSTNode* lchild, * rchild;
}BSTNode, * BSTree;

//�ڶ��������� T �в���ֵΪ key �Ľ��
BSTNode* BST_Search(BSTree T, int key)
{
	if (T != NULL && key != T->key)
	{
		if (key < T->key)
			T = T->lchild;
		else
			T = T->rchild;
	}
	return T;
}

//�ڶ��������� T �в���ֵΪ k �Ľ��(�ݹ�ʵ��)
bool BST_Insert(BSTree &T, int k)
{
	if (T == NULL)//ԭ��Ϊ�գ��²���Ľ��Ϊ�ս��
	{
		T = (BSTree)malloc(sizeof(BSTNode));
		T->key = k;
		T->lchild = T->rchild = NULL;
		return true;
	}
	else if (T->key == k)
		return false;
	else if (k < T->key)
		return BST_Insert(T->lchild, k);//�嵽������
	else
		return BST_Insert(T->rchild, k);//�嵽������
}

//�����������Ĺ���
//���� str[] �еĹؼ������н���������������nΪ����Ԫ�ظ���
void Create_BST(BSTree& T, int str[], int n)
{
	T = NULL;
	for (int i = 0; i < n; i++)
		BST_Insert(T, str[i]);
}













