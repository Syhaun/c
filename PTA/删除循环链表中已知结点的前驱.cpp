#include <stdio.h>
#include <stdlib.h>
typedef int DataType;
typedef struct node 
{
    DataType data;
    struct node *next;
}LNode,*LinkList;

LinkList Creat_CircularList();  //������ͷ���ѭ��������,������ͷָ�롣
LNode * SetPointerS(LinkList H,int x);//����ָ���x������ָ�롣
void PrintCircularList(LNode *S);//��ָ��S��ָ��㿪ʼ�����������������ֵ��
LNode* DelPrior(LNode *S);
main()
{
    LNode *s;
    LinkList H;
    int x;
    H = Creat_CircularList();
    scanf("%d",&x);
    s=SetPointerS(H,x);
    s=DelPrior(s);
    PrintCircularList(s);
}

LinkList Creat_CircularList()
{
    int n,i;
    LNode *nw,*rear=NULL,*head=NULL;
    scanf("%d",&n);//���ս������
    for(i=0;i<n;i++)
    {
        nw=(LNode*)malloc(sizeof(LNode));
        scanf("%d",&nw->data);
        if(rear==NULL)
            rear=head=nw;
        else
        {
            rear->next=nw;
            rear=nw;
        }
    }
    if(rear)
        rear->next=head;
    return head;
}

void PrintCircularList(LinkList s)
{
    LNode *p;
    for(p=s;p->next!=s;p=p->next)
        printf("%d ",p->data);
    printf("%d",p->data);
}

LNode * SetPointerS(LinkList H,int x)
{
    int i;
    LNode *s=H;
    for(i=1;i<x;i++)
        s=s->next;
    return s;
 }


/* ����������д�� */
LNode* DelPrior (LNode * S ){
	if(S == NULL || S->next == NULL)
	return S;
	LinkList p = (LinkList)malloc(sizeof(LNode)); 
	p = S;
	while(S->next->next != p) {
		S = S->next;
	}
	LinkList temp = S->next;
	if(temp == S)
	return NULL;
	S->next = temp->next;
	free(temp);
	return p;
}
