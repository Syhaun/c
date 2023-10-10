#include <stdio.h>
#include <stdlib.h>
typedef int DataType;
typedef struct node 
{
    DataType data;
    struct node *next;
}LNode,*LinkList;

LinkList CreatLinkList();  //创建带头结点单链表,并返回头指针。
void PrintLinkList(LinkList H);//依次输出单链表H中各个元素结点，若为空表则输出NONE。
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
    scanf("%d",&n);//接收结点总数
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


/* 请在这里填写答案 */
LinkList CombineList(LinkList La, LinkList Lb) {
    LNode *pa = La->next; // 指向La的第一个元素
    LNode *pb = Lb->next; // 指向Lb的第一个元素
    LNode *pc = La;       // 指向合并后链表的头节点

    int m = 0; // 记录链表 A 的长度
    int n = 0; // 记录链表 B 的长度

    // 计算链表 A 和链表 B 的长度
    while (pa != NULL) {
        m++;
        pa = pa->next;
    }

    pa = La->next; // 重新指向La的第一个元素

    while (pb != NULL) {
        n++;
        pb = pb->next;
    }

    pb = Lb->next; // 重新指向Lb的第一个元素

    if (m <= n) {
        while (m > 0 && n > 0) {
            // 将pb节点插入到pa节点之后
            LNode *tempa = pa->next;
            LNode *tempb = pb->next;
            pa->next = pb;
            pb->next = tempa;

            // 移动pa和pb指针到下一个节点
            pa = tempa;
            pb = tempb;
            pc = pc->next->next; // 移动pc指针到合并后链表的尾节点的下一个节点

            m--;
            n--;
        }

        if (n > 0) {
            // 如果链表B还有剩余元素，将其直接链接到合并后链表的末尾
            pc->next = pb;
        }

        return La; // 返回合并后链表的头指针
    } else if (m > n) {
        La = Lb; // 更新链表A的头指针为链表B的头节点
        pc = La; // 更新pc指针为合并后链表的头节点

        while (m > 0 && n > 0) {
            // 将pa节点插入到pb节点之后
            LNode *tempa = pa->next;
            LNode *tempb = pb->next;
            pb->next = pa;
            pa->next = tempb;

            // 移动pa和pb指针到下一个节点
            pb = tempb;
            pa = tempa;
            pc = pc->next->next; // 移动pc指针到合并后链表的尾节点的下一个节点

            m--;
            n--;
        }

        if (m > 0) {
            // 如果链表A还有剩余元素，将其直接链接到合并后链表的末尾
            pc->next = pa;
        }

        // 如果链表A比链表B长，将链表A的尾节点的next指针置为NULL
        if (m < 0) {
            pa->next = NULL;
        }

        return La; // 返回合并后链表的头指针
    }

    return La; // 默认返回链表A的头指针
}



