#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#define MAXSIZE 10
#define NotFound 0
typedef int ElementType;
typedef int Position;
typedef struct LNode* List;

struct LNode 
{
    ElementType Data[MAXSIZE];
    Position Last; /* 保存线性表中最后一个元素的位置 */
};

Position BinarySearch(List L, ElementType X)
{
    int front = 1;
    int last = L->Last;
    int mid = 0;
    while (last >= front)
    {
        mid = (front + last) / 2;
        if (L->Data[mid] > X)
        {
            last = mid - 1;
        }
        else if (L->Data[mid] < X)
            front = mid + 1;
        else
            return mid;
    }
    return NotFound;
}

int main()
{
    printf("hehe\n");
    printf("wei\n");
    return 0;
}