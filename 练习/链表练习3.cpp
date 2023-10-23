#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct Node
{
    int date;
    struct Node *next;
} *LinkList, LNode;
//ͷ�巨
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
//β�巨
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
//����k��λ�ò���Ԫ��e
int Insert (LinkList H,int k,int e)
{
    int count = 1;
    LinkList p = H;
    while(count < k)
    {
        p = p->next;
        if(p == NULL)
        {
            printf("�����λ�ô���");
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
//ɾ����k��λ�õ�Ԫ��
int Delect(LinkList H,int k,int *e)
{
    LinkList p = H;
    int count = 1;
    while(count < k)
    {
        p = p->next;
        if(p == NULL || p ->next == NULL)
        {
            printf("ɾ����λ�ô���");
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
//��ֵ���ҷ���
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