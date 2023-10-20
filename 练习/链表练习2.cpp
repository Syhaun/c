#include<stdio.h>
#include<stdlib.h>
//结点定义
typedef struct node
{
    int date;
    struct node *next;
} LNode, *LinkList;
//头插法
LinkList Head_Init()
{
    LinkList H = (LinkList)malloc(sizeof(LNode));
    H->next = NULL;
    LinkList p = NULL;
    int x;
    scanf("%d",&x);
    while(x != -1)
    {
        p = (LinkList)malloc(sizeof(LNode));
        p->date = x;
        p->next = H->next;
        H->next = p;
        scanf("%d", &x);
    }
    return H;
}
//尾插法
LinkList Tail_Init()
{
    LinkList H = (LinkList)malloc(sizeof(LNode));
    H->next = NULL;
    LinkList p, q = H;
    int x;
    scanf("%d",&x);
    while(x != -1)
    {
        p = (LinkList)malloc(sizeof(LNode));
        p->date = x;
        q -> next = p;
        q = p;
        scanf("%d", &x);
    }
    p->next = NULL;
    return H;
}
// 按值查找
LinkList Search(LinkList H,int tar)
{
    LinkList p = H;
    while(p -> next != NULL)
    {
        p = p->next;
        if(p -> date == tar)
            return p;
    }
    return NULL;
}
//插入,往第i个位置插入值为tar的结点
LinkList Insert(LinkList H , int i, int tar)
{
    LinkList p = H, q = H;
    int count = 1;
    while(count < i)
    {
        p = p->next;
        if (p == NULL)
        {
            printf("插入位置错误");
            return NULL;
        }
        count++;
    }
   
    q->date = tar;
    q->next = p->next;
    p->next = q;
    return H;
}
//删除,删除第i个结点
int Delect(LinkList H, int i, int *x)
{
    LinkList p = H;
    LinkList q = (LinkList)malloc(sizeof(LNode));
    int count = 1;
    while(count < i)
    {
        p = p->next;
        if(p == NULL || p -> next == NULL)
            return 0;
        count++;
    }
    q = p->next;
    p->next = q->next;
    *x = q->date;
    return 1;
}
//链表的逆置
LinkList Reserse(LinkList H)
{
    LinkList p = H->next;
    LinkList q;
    H->next = NULL;
    while(p)
    {
        q = p;
        p = p->next;
        q->next = H->next;
        H->next = q;
    }
    return q;
}
int main()
{
    LinkList H = Tail_Init();
    LinkList p = H ->next;
    int *x = (int *)malloc(sizeof(int));
    Delect(H, 3, x);
    printf("%d\n", *x);
    p = Reserse(H);
    // Insert(H, 6, 100);
    while (p)
    {
        printf("%d\n", p->date);
        p = p->next;
    }
    // LinkList q = Search(H, 5);
    // printf("%d", q->date);
    
    return 0;
}