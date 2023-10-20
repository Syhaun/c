#include<stdio.h>
#include<stdlib.h>
//��㶨��
typedef struct node
{
    int date;
    struct node *next;
} LNode, *LinkList;
//ͷ�巨
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
//β�巨
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
// ��ֵ����
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
//����,����i��λ�ò���ֵΪtar�Ľ��
LinkList Insert(LinkList H , int i, int tar)
{
    LinkList p = H, q = H;
    int count = 1;
    while(count < i)
    {
        p = p->next;
        if (p == NULL)
        {
            printf("����λ�ô���");
            return NULL;
        }
        count++;
    }
   
    q->date = tar;
    q->next = p->next;
    p->next = q;
    return H;
}
//ɾ��,ɾ����i�����
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
//���������
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