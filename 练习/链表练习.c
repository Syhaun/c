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
int main() {
    Create_LinkList1();
    LinkList p = (LinkList)malloc(sizeof(LNode));
}