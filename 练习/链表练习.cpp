#include<stdio.h>
#include<stdlib.h>
#define DataType int

//结点的定义
typedef struct node
{
    /* data */
    DataType data;
    struct node *next;
} LNode, *LinkList;

//头插法建立单链表
LinkList Create_LinkList1()
{
    LinkList H = (LinkList)malloc(sizeof(LNode));
    H->next = NULL;
    LNode *s;
    int x;
    scanf("%d", &x);
    while(x!=-1) {
        s = (LinkList)malloc(sizeof(LNode));
        s->data = x;
        s->next = H->next;
        H->next = s;
        scanf("%d", &x);
    }
    return H;
}
//尾插法建立单链表
LinkList Create_LinkList2()
{
    LinkList H = (LinkList)malloc(sizeof(LNode));
    H->next = NULL;
    LNode *s, *r = H;
    int x;
    scanf("%d", &x);
    while(x != -1)
    {
        s = (LinkList)malloc(sizeof(LNode));
        s->data = x;
        r->next = s;
        r = s;
        scanf("%d", &x);
    }
    r->next = NULL;
    return H;
}
//求单链表的表长
int length_LinkList(LinkList H)
{
    LNode *p = H;
    int count = 0;
    while(p->next)
    {
        p = p->next;
        count++;
    }
    return count;
}
//单链表中按序号查询
LinkList Get_LinkList(LinkList H ,int k)
{
    LNode *p = H;
    int count = 0;
    while(p ->next != NULL && count <k)
    {
        p = p->next;
        count++;
    }
    if(count = k)
        return p;
    else
        return NULL;
}
//按值查找
LNode * Locate(LinkList H,int x)
{
    LNode *p = H->next;
    while(p != NULL && p->data != x)
        p = p->next;
    return p;
}
//单链表的插入 在H的第i个位置插入值为x的元素
int Insert_LinkList(LinkList H,int i ,int x)
{
    LNode *p, *s;
    p = Get_LinkList(H, i - 1);
    if(p == NULL)
    {
        printf("插入位置i错误");
        return 0;
    }
    else
    {
        s = (LinkList)malloc(sizeof(LNode));
        s->data = x;
        s->next = p->next;
        p->next = s;
        return 1;
    }
}
//单链表的删除
int Del_LinkList(LinkList H,int i)
{
    LinkList p, q;
    p = Get_LinkList(H, i - 1);
    if(p == NULL)
    {
        printf("第i-1个结点不存在");
        return 0;
    }
    else
    
    {
        if(p->next == NULL)
        {
            printf("第i个结点不存在");
        return 0;
        }
        else
        {
        q = p->next;
        p->next = q->next;
        free(q);
        return 1;
        }
    }
}
//单链表的逆置
void Reverse(LinkList H)
{
    LNode *p, *q;
    p = H->next;
    H->next = NULL;
    while(p)
    {
        q = p;
        p = p->next;
        q->next = H->next;
        H->next = q;
    }
}
int main() {
    LinkList H = Create_LinkList2();
    LinkList p = H->next;
    while(p)
    {
        printf("%d\n", p->data);
        p = p->next;
    }
    int count = length_LinkList(H);
    printf("%d\n", count);
    return 0;
}