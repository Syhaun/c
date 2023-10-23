#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct Node
{
    int date;
    struct Node *next;
} *LinkList, LNode;
//头插法
LinkList Head_Init()
{
    LinkList H = (LinkList)malloc(sizeof(LNode));
    H->next = NULL;
    LinkList p = NULL;
    int x;
    scanf("%d", &x);
    while(x != -1)
    {
        p = (LinkList)malloc(sizeof(LNode));
        p->date = x;
        p->next = H->next;
        H->next = p;
        p = H;
        scanf("%d", &x);
    }
    return H;
}
//尾插法
LinkList Tail_Init()
{
    LinkList H = (LinkList)malloc(sizeof(LNode));
    H->next = NULL;
    LinkList p = H, q = H;
    int x;
    scanf("%d", &x);
    while(x != -1)
    {
        p = (LinkList)malloc(sizeof(LNode));
        p->date = x;
        q->next = p;
        q = p;
        scanf("%d", &x);
    }
    p->next = NULL;
    return H;
}
//往第k个位置插入元素e
int Insert (LinkList H,int k,int e)
{
    int count = 1;
    LinkList p = H;
    while(count < k)
    {
        p = p->next;
        if(p == NULL)
        {
            printf("插入的位置错误");
            return 0;
        }
        count++;
    }
    LinkList q = (LinkList)malloc(sizeof(LNode));
    q->date = e;
    q->next = p->next;
    p->next = q;
    return 1;
}
//删除第k个位置的元素
int Delect(LinkList H,int k,int *e)
{
    LinkList p = H;
    int count = 1;
    while(count < k)
    {
        p = p->next;
        if(p == NULL || p ->next == NULL)
        {
            printf("删除的位置错误");
            return 0;
        }
        count++;
    }
    LinkList q = (LinkList)malloc(sizeof(LNode));
    q = p->next;
    *e = q->date;
    p->next = q->next;
    return 1;
}
//按值查找返回
int main()
{
    LinkList H = Tail_Init();
    LinkList p = (LinkList)malloc(sizeof(LNode));
    p = H;
    //int flag = Insert(p, 3, 100);
    int *e = (int *)malloc(sizeof(int));
    int flag2 = Delect(p, 3, e);
   // printf("%d", &e);
    while(p)
    {
        p = p->next;
        printf("%d\n", p->date);
    }
    return 0;
}