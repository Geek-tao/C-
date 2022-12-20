#define _CRT_SECURE_NO_WARNINGS 1
#define MaxSize 10                  //定义栈中元素的最大个数
typedef struct
{
	ElemType date[MaxSize];//静态数组存放栈中元素
	int top;//栈顶指针，指示数组下标
}SqStack;                           //定义顺序栈的类型

void InitStack(SqStack& S)
{
	S.top = -1;                    //初始化栈顶指针
}//判断栈是否为空，只需判断top指针是否为-1

//入栈操作
bool Push(SqStack& S, ElemType x)
{
	if (S.top == MaxSize - 1)//栈满
		return false;
	S.top++;//指针先加1
	S.date[S.top] = x;//新元素入栈
	return true;
}

//出栈操作，出栈元素的值用x返回
bool Pop(SqStack& S, ElemType& x)
{
	if (S.top == -1)//栈空
		return false;
	x = S.date[S.top];//栈顶元素先出栈
	S.top--;//指针再减1
	return true;
}

//读取栈顶元素，值用x返回
bool GetTop(SqStack S, ElemType& x)
{
	if (S.top == -1)//栈空
		return false;
	x = S.date[S.top];//x记录栈顶元素
	return true;
}

void testStack()
{
	SqStack S;                     //声明一个顺序栈(分配空间)
	InitStack(S);//初始化顺序栈
	//......
	ElemType x;
	Pop(S,x);
}