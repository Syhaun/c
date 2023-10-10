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
    if (*pa == NULL || *pb == NULL || i <= 0 || j < 0)
        return;
    
    LNode *prea = NULL;
    LNode *cura = *pa;
    
    // �ҵ�la�е�i��Ԫ�ص�ǰһ���ڵ�
    for (int k = 1; k < i; k++) {
        if (cura == NULL)
            return;
        prea = cura;
        cura = cura->next;
    }
    
    LNode *preb = NULL;
    LNode *curb = *pb;
    
    // �ҵ�lb�е�j��Ԫ�ص�ǰһ���ڵ�
    for (int k = 0; k < j; k++) {
        if (curb == NULL)
            return;
        preb = curb;
        curb = curb->next;
    }

    LNode *temp = NULL;
    
    // �ƶ�Ԫ��
    for (int k = 0; k < len; k++) {
        if (cura == NULL)
            return ;
        temp = cura;
        cura = cura->next;
        if (preb != NULL) {
            preb->next = temp;
            preb = temp;
        } else {
            preb = temp;
            *pb = temp;
        }
    }
    
    // ����pa��ͷָ��
    if (prea != NULL) {
        prea->next = cura;
    } else {
        *pa = cura;
    }

    // ��temp��next����Ϊcurb������ʣ���lbԪ��
    temp->next = curb;
}

