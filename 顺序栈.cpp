#define _CRT_SECURE_NO_WARNINGS 1
#define MaxSize 10                  //����ջ��Ԫ�ص�������
typedef struct
{
	ElemType date[MaxSize];//��̬������ջ��Ԫ��
	int top;//ջ��ָ�룬ָʾ�����±�
}SqStack;                           //����˳��ջ������

void InitStack(SqStack& S)
{
	S.top = -1;                    //��ʼ��ջ��ָ��
}//�ж�ջ�Ƿ�Ϊ�գ�ֻ���ж�topָ���Ƿ�Ϊ-1

//��ջ����
bool Push(SqStack& S, ElemType x)
{
	if (S.top == MaxSize - 1)//ջ��
		return false;
	S.top++;//ָ���ȼ�1
	S.date[S.top] = x;//��Ԫ����ջ
	return true;
}

//��ջ��������ջԪ�ص�ֵ��x����
bool Pop(SqStack& S, ElemType& x)
{
	if (S.top == -1)//ջ��
		return false;
	x = S.date[S.top];//ջ��Ԫ���ȳ�ջ
	S.top--;//ָ���ټ�1
	return true;
}

//��ȡջ��Ԫ�أ�ֵ��x����
bool GetTop(SqStack S, ElemType& x)
{
	if (S.top == -1)//ջ��
		return false;
	x = S.date[S.top];//x��¼ջ��Ԫ��
	return true;
}

void testStack()
{
	SqStack S;                     //����һ��˳��ջ(����ռ�)
	InitStack(S);//��ʼ��˳��ջ
	//......
	ElemType x;
	Pop(S,x);
}