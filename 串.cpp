#define _CRT_SECURE_NO_WARNINGS 1
#define MAXLEN 255//预定义最大串长255
typedef struct//顺序存储
{
	char ch[MAXLEN];//每个分量存储一个字符
	int length;//串的当前长度
}SString;//定义顺序串的类型

typedef struct StringNode//链式存储
{
	char ch;//每个结点存一个字符
	struct StringNode* next;
}StringNode,*String;

//用串Sub返回串S中第pos个字符起长度为len的子串
bool SubString(SString& Sub, SString S, int pos, int len)
{
	//子串范围越界
	if ((pos + len - 1) > S.length)
		return false;
	for (int i = pos; i < pos + len; i++)
	{
		Sub.ch[i - pos + 1] = S.ch[i];
	}
	Sub.length = len;
	return true;

}

//比较操作，若S>T，则返回值>0;若S=T,则返回值=0；若S<T，则返回值<0
int StrCompare(SString S, SString T)
{
	for (int i = 1; S.length >= i && T.length >= i; i++)
	{
		if (S.ch[i] != T.ch[i])//如果相等，比较下一位；如果不相等就可以分出大小
			return S.ch[i] - T.ch[i];
	}
	return S.length - T.length;//每一位都相等，则比较串的长度
}

//定位操作。在主串S中存在与串T相等的子串，则返回它在主串S中第一次出现的位置
int Index(SString S, SString T)
{
	int n = S.length;
	int m = T.length;
	SString Sub;//用于暂存子串
	for (int i = 1; i <= n - m + 1; i++)
	{
		SubString(Sub, S, i, m);
		if (StrCompare(Sub, T) != 0)
			i++;
		else
			return i;//返回子串在主串中的位置
	}
	return 0;//S中不存在与T相等的子串
}

//朴素模式匹配算法
int Index(SString S, SString T)
{
	int k = 1;
	int i = 1; int j = 1;
	while (i <= S.length && j <= T.length)
	{
		if (S.ch[i] = T.ch[j])
		{
			i++;
			j++;
		}
		else
		{
			k++;
			i = k;
			j = 1;
		}
	}
	if (j > T.length)
		return k;
	else
		return 0;
}

//KMP算法
int Index_KMP(SString S, SString T, int next[])
{
	int i = 1;
	int j = 1;
	while (i <= S.length && j <= T.length)
	{
		if (j == 0 || S.ch[i] = T.ch[j])
		{
			i++;
			j++;
		}
		else
			j = next[j];
	}
	if (j > T.length)
		return i - T.length;
	else
		return 0;
}





