#define _CRT_SECURE_NO_WARNINGS 1
#define MaxSize 100
#include<stdio.h>
#include<stdlib.h>
struct TreeNode
{
	int value;//结点中的数据元素
	bool isEmpty;//结点是否为空
};//定义树的结点类型

TreeNode t[MaxSize];//定义数组t存储树的结点

for (int i = 0; i < MaxSize; i++)
{
	t[i].isEmpty = true;
}//初始化所有结点标记为空

typedef struct BiTNode
{
	ElemType date;
	struct BiTNode* lchild, * rchild;
}BiTNode, * BiTree;//链式存储二叉树的结点

//先序遍历
void PreOrder(BiTree T)
{
	if (T != NULL)
	{
		visit(T);//访问根结点
		PreOrder(T->lchild);//递归遍历左子树
		PreOrder(T->rchild);//递归遍历右子树
	}
}

//中序遍历
void InOrder(BiTree T)
{
	if (T != NULL)
	{
		InOrder(T->lchild);
		visit(T);
		InOrder(T->rchild);
	}
}

//后序遍历
void PostOrder(BiTree T)
{
	if (T != NULL)
	{
		PostOrder(T->lchild);
		PostOrder(T->rchild);
		vist(T);
	}
}

//求二叉树的高度（深度）
int treeDepth(BiTree T)
{
	if (T == NULL)
		return 0;
	int l = treeDepth(T->lchild);
	int r = treeDepth(T->rchild);
	return l > r ? l + 1 : r + 1;
}

//层序遍历
typedef struct LinkNode
{
	BiTNode* date;//存储二叉树结点的指针
	LinkNode* next;
}LinkNode;

typedef struct
{
	LinkNode* front, * rear;//辅助队列队头队尾指针
}LinkQueue;

void LevelOrder(BiTree T)
{
	LinkQueue Q;
	InitQueue(Q);//初始化辅助队列
	BiTree p;//用来接收出队的队头指针
	EnQueue(Q, T);
	while (!IsEmpty(Q))//队列不为空
	{
		DeQueue(Q, p);//队头指针出队赋值给p
		visit(p);
		if (p->lchild != NULL)
			EnQueue(Q, p->lchild);
		if (p->rchild != NULL)
			EnQueue(Q, p->rchild);//左右孩子入队
	}
}

//线索二叉树结点
typedef struct ThreadNode
{
	ElemType date;
	ThreadNode* lchild, * rchild;
	int ltag, rtag;//左右线索标志
}ThreadNode, * ThreadTree;

ThreadNode* pre = NULL;//全局变量,指向当前访问结点的前驱
//中序线索化二叉树
void CreateInThread(ThreadTree T)
{
	if (T != NULL)
	{
		InThread(T);
		if (pre->rchild == NULL)
			pre->rtag = 1;//处理遍历的最后一个结点
	}
}

//中序遍历二叉树，一边遍历一边线索化
void InThread(ThreadTree T)
{
	if (T != NULL)
	{
		InThread(T->lchild);
		visit(T);
		InThread(T->rchild);
	}
}

//先序遍历二叉树，一边遍历一边线索化
void PreThread(ThreadTree T)
{
	visit(T);
	if (T->ltag == 0)//lchild不是前驱线索，如果ltag = 1，出现爱滴魔力转圈圈
	PreThread(T->lchild);
	PreThread(T->rchild);
}


void visit(ThreadNode* q)
{
	if (q->lchild == NULL)//左子树为空，建立前驱线索
	{
		q->lchild = pre;
		q->ltag = 1;
	}
	if (pre != NULL && pre->rchild == NULL)
	{
		pre->rchild = q;//建立前驱结点的后继线索
		pre->rtag = 1;
	}
	pre = q;
}

//中序线索二叉树找中序后继
//找到以p为根结点的子树中，第一个被中序遍历的结点
ThreadNode* Firstnode(ThreadNode* p)
{
	while (p->ltag == 0)
		p = p->lchild;//循环找到最左下结点
	return p;
}

//在中序线索二叉树中找到结点p的后继结点
ThreadNode* Nextnode(ThreadNode* p)
{
	if (p->rtag == 0)
		return Firstnode(p->rchild);//找到右子树中最左下结点
	else
		return p->rchild;
}

//中序线索二叉树找中序前驱
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

//双亲表示法(顺序存储)
#define MAX_TREE_SIZE 100  //树中最多结点数
typedef struct PTNode//树的结点定义
{
	ElemType date;   //数据元素
	int parent;      //双亲位置域
}PTNode;

typedef struct//树的类型定义
{
	PTNode nodes[MAX_TREE_SIZE];
	int n;                       //结点数
}PTree;

//孩子表示法(顺序+链式存储)
typedef struct CTNode
{
	int child;//孩子结点在数组中的位置
	struct CTNode* next;
}CTNode;

typedef struct
{
	ElemType date;
	CTNode* firstChild;//第一个孩子的指针
}CTBox;

typedef struct
{
	CTBox nodes[MAX_TREE_SIZE];
	int n, r;//结点数和根的位置
}CTree;

//孩子兄弟表示法
typedef struct CSNode
{
	ElemType date;
	struct CSNode* firstchild, * nextsibling;
}CSNode, * CSTree;

//二叉查找树(Binary Search Tree) 
typedef struct BSTNode
{
	int key;
	struct BSTNode* lchild, * rchild;
}BSTNode, * BSTree;

//在二叉排序树 T 中查找值为 key 的结点
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

//在二叉排序树 T 中插入值为 k 的结点(递归实现)
bool BST_Insert(BSTree &T, int k)
{
	if (T == NULL)//原树为空，新插入的结点为空结点
	{
		T = (BSTree)malloc(sizeof(BSTNode));
		T->key = k;
		T->lchild = T->rchild = NULL;
		return true;
	}
	else if (T->key == k)
		return false;
	else if (k < T->key)
		return BST_Insert(T->lchild, k);//插到左子树
	else
		return BST_Insert(T->rchild, k);//插到右子树
}

//二叉排序树的构造
//按照 str[] 中的关键字序列建立二叉排序树，n为数组元素个数
void Create_BST(BSTree& T, int str[], int n)
{
	T = NULL;
	for (int i = 0; i < n; i++)
		BST_Insert(T, str[i]);
}













