#include <stdio.h>
#include <stdlib.h>
typedef int DataType;
typedef struct node 
{
    DataType data;
    struct node *next;
}LNode,*LinkList;

LinkList CreatLinkList();  //������ͷ��㵥����,������ͷָ�롣
void PrintLinkList(LinkList H);//�������������H�и���Ԫ�ؽ�㣬��Ϊ�ձ������NONE��
LinkList CombineList(LinkList La,LinkList Lb);
main()
{
    LinkList la,lb;
    la = CreatLinkList();
    lb = CreatLinkList();
    la=CombineList(la,lb);
    PrintLinkList(la);
}

LinkList CreatLinkList()
{
    int n,i;
    LNode *nw,*rear=NULL,*head=NULL;
    head=(LNode*)malloc(sizeof(LNode));
    rear=head;
    scanf("%d",&n);//���ս������
    for(i=0;i<n;i++)
    {
        nw=(LNode*)malloc(sizeof(LNode));
        scanf("%d",&nw->data);
        rear->next=nw;
        rear=nw;
    }
    rear->next=NULL;
    return head;
}

void PrintLinkList(LinkList H)
{
    LNode *p;
    if(!(H->next))
    {    
        printf("NONE\n");
        return;
    }
    for(p=H->next;p;p=p->next)
        printf("%d ",p->data);
    printf("\n");
}


/* ����������д�� */
LinkList CombineList(LinkList La, LinkList Lb) {
    LNode *pa = La->next; // ָ��La�ĵ�һ��Ԫ��
    LNode *pb = Lb->next; // ָ��Lb�ĵ�һ��Ԫ��
    LNode *pc = La;       // ָ��ϲ��������ͷ�ڵ�

    int m = 0; // ��¼���� A �ĳ���
    int n = 0; // ��¼���� B �ĳ���

    // �������� A ������ B �ĳ���
    while (pa != NULL) {
        m++;
        pa = pa->next;
    }

    pa = La->next; // ����ָ��La�ĵ�һ��Ԫ��

    while (pb != NULL) {
        n++;
        pb = pb->next;
    }

    pb = Lb->next; // ����ָ��Lb�ĵ�һ��Ԫ��

    if (m <= n) {
        while (m > 0 && n > 0) {
            // ��pb�ڵ���뵽pa�ڵ�֮��
            LNode *tempa = pa->next;
            LNode *tempb = pb->next;
            pa->next = pb;
            pb->next = tempa;

            // �ƶ�pa��pbָ�뵽��һ���ڵ�
            pa = tempa;
            pb = tempb;
            pc = pc->next->next; // �ƶ�pcָ�뵽�ϲ��������β�ڵ����һ���ڵ�

            m--;
            n--;
        }

        if (n > 0) {
            // �������B����ʣ��Ԫ�أ�����ֱ�����ӵ��ϲ��������ĩβ
            pc->next = pb;
        }

        return La; // ���غϲ��������ͷָ��
    } else if (m > n) {
        La = Lb; // ��������A��ͷָ��Ϊ����B��ͷ�ڵ�
        pc = La; // ����pcָ��Ϊ�ϲ��������ͷ�ڵ�

        while (m > 0 && n > 0) {
            // ��pa�ڵ���뵽pb�ڵ�֮��
            LNode *tempa = pa->next;
            LNode *tempb = pb->next;
            pb->next = pa;
            pa->next = tempb;

            // �ƶ�pa��pbָ�뵽��һ���ڵ�
            pb = tempb;
            pa = tempa;
            pc = pc->next->next; // �ƶ�pcָ�뵽�ϲ��������β�ڵ����һ���ڵ�

            m--;
            n--;
        }

        if (m > 0) {
            // �������A����ʣ��Ԫ�أ�����ֱ�����ӵ��ϲ��������ĩβ
            pc->next = pa;
        }

        // �������A������B����������A��β�ڵ��nextָ����ΪNULL
        if (m < 0) {
            pa->next = NULL;
        }

        return La; // ���غϲ��������ͷָ��
    }

    return La; // Ĭ�Ϸ�������A��ͷָ��
}



