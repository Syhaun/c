#include <stdio.h>
#include <stdlib.h>
typedef int DataType;
typedef struct node 
{
    DataType data;
    struct node *next;
}LNode,*LinkList;

LinkList CreatLinkList();  //������ͷ��㵥����,������ͷָ�롣
void PrintLinkList(LinkList H);//���������ͷ��㵥����H�и���Ԫ�ؽ�㣬��Ϊ�ձ������NONE��
void MoveLaToLb(LinkList *pa,int i,int len,LinkList *pb,int j);
main()
{
    LinkList la,lb;
    int i,j,len;
    la = CreatLinkList();
    lb = CreatLinkList();
    scanf("%d %d %d",&i,&j,&len);
    MoveLaToLb(&la,i,len,&lb,j);
    PrintLinkList(la);
    PrintLinkList(lb);
}

LinkList CreatLinkList()
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
        rear->next=NULL;
    return head;
}

void PrintLinkList(LinkList H)
{
    LNode *p;
    if(!H)
    {    
        printf("NONE\n");
        return;
    }
    for(p=H;p;p=p->next)
        printf("%d ",p->data);
    printf("\n");
}
void MoveLaToLb(LinkList *pa, int i, int len, LinkList *pb, int j) {
    if (*pa == NULL || *pb == NULL || i < 1 || j < 0)
        return ;

    LinkList la = *pa;
    LinkList lb = *pb;
    int count_la = 1;
    int count_lb = 0;
    int count_lc = 1;
    LinkList prev_la = NULL;
    LinkList prev_lb = NULL;

	if(lb == NULL)
	return ;
    // �������� la���ҵ��� i ���ڵ����ǰ���ڵ�
    while (count_la < i && la != NULL) {
        prev_la = la;
        la = la->next;
        count_la++;
    }
    // �������� lb���ҵ��� j ���ڵ����ǰ���ڵ�
    while (count_lb < j && lb != NULL) {
        prev_lb = lb;
        lb = lb->next;
        count_lb++;
    }
    if(prev_lb == NULL)
    return ;
    LinkList aa = la;
    
    
    while (count_lc < len && la != NULL) {
    	la = la ->next;
    	count_lc++;
	}
	if(la == NULL || len <= 0)
	return ;
	prev_lb -> next = aa;
	prev_la->next = la->next;
	
	la->next = lb;	
}







