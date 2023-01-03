#define _CRT_SECURE_NO_WARNINGS 1
#define MAXLEN 255//Ԥ������󴮳�255
typedef struct//˳��洢
{
	char ch[MAXLEN];//ÿ�������洢һ���ַ�
	int length;//���ĵ�ǰ����
}SString;//����˳�򴮵�����

typedef struct StringNode//��ʽ�洢
{
	char ch;//ÿ������һ���ַ�
	struct StringNode* next;
}StringNode,*String;

//�ô�Sub���ش�S�е�pos���ַ��𳤶�Ϊlen���Ӵ�
bool SubString(SString& Sub, SString S, int pos, int len)
{
	//�Ӵ���ΧԽ��
	if ((pos + len - 1) > S.length)
		return false;
	for (int i = pos; i < pos + len; i++)
	{
		Sub.ch[i - pos + 1] = S.ch[i];
	}
	Sub.length = len;
	return true;

}

//�Ƚϲ�������S>T���򷵻�ֵ>0;��S=T,�򷵻�ֵ=0����S<T���򷵻�ֵ<0
int StrCompare(SString S, SString T)
{
	for (int i = 1; S.length >= i && T.length >= i; i++)
	{
		if (S.ch[i] != T.ch[i])//�����ȣ��Ƚ���һλ���������ȾͿ��Էֳ���С
			return S.ch[i] - T.ch[i];
	}
	return S.length - T.length;//ÿһλ����ȣ���Ƚϴ��ĳ���
}

//��λ������������S�д����봮T��ȵ��Ӵ����򷵻���������S�е�һ�γ��ֵ�λ��
int Index(SString S, SString T)
{
	int n = S.length;
	int m = T.length;
	SString Sub;//�����ݴ��Ӵ�
	for (int i = 1; i <= n - m + 1; i++)
	{
		SubString(Sub, S, i, m);
		if (StrCompare(Sub, T) != 0)
			i++;
		else
			return i;//�����Ӵ��������е�λ��
	}
	return 0;//S�в�������T��ȵ��Ӵ�
}

//����ģʽƥ���㷨
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

//KMP�㷨
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





