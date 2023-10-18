#include<stdio.h>
#include<stdlib.h>
#define DataType int

//���Ķ���
typedef struct node
{
    /* data */
    DataType data;
    struct node *next;
} LNode, *LinkList;

//ͷ�巨����������
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
//β�巨����������
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
//������ı�
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
//�������а���Ų�ѯ
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
//��ֵ����
LNode * Locate(LinkList H,int x)
{
    LNode *p = H->next;
    while(p != NULL && p->data != x)
        p = p->next;
    return p;
}
//������Ĳ��� ��H�ĵ�i��λ�ò���ֵΪx��Ԫ��
int Insert_LinkList(LinkList H,int i ,int x)
{
    LNode *p, *s;
    p = Get_LinkList(H, i - 1);
    if(p == NULL)
    {
        printf("����λ��i����");
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
//�������ɾ��
int Del_LinkList(LinkList H,int i)
{
    LinkList p, q;
    p = Get_LinkList(H, i - 1);
    if(p == NULL)
    {
        printf("��i-1����㲻����");
        return 0;
    }
    else
    
    {
        if(p->next == NULL)
        {
            printf("��i����㲻����");
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
//�����������
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