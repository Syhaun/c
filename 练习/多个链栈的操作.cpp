#include<stdio.h>
#include<stdlib.h>
typedef struct Stacknode
{
    int data;
    struct Stacknode *next;
} slStacktype;
//入栈操作,将元素x压入链栈top[i]中
int PushDupLs(slStacktype * top[],int i,int x)
{
    slStacktype *p;
    p = (slStacktype *)malloc(sizeof(slStacktype));
    p->data = x;
    p->next = top[i]->next;
    top[i]->next = p;
    return 1;
}
//出栈操作,从链栈top[i]中删除栈顶元素
int PopDupLs(slStacktype *top[],int i)
{
    slStacktype *p;
    int x;
    if(top[i] ->next == NULL)
    {
        printf("此栈为空!");
        return;
    }
    p = top[i]->next;
    top[i]->next = p->next;
    x = p->data;
    return x;
}
int main()
{
    int M = 0;//链栈的个数
    scanf("%d", &M);
    slStacktype **top = (slStacktype**)malloc(M*sizeof(slStacktype*));
    for (int i = 0; i < M; i++)
    {
        top[i] = (slStacktype *)malloc(sizeof(slStacktype));
    }

        return 0;
}