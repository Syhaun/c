#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int DataType;
typedef struct node
{      DataType  data;
       struct node *next; 
}LNode,*CirLinkQueue;

//队列的基本操作函数定义
CirLinkQueue InitQueue();  //初始化队列，返回值为队列的尾指针。
int IsEmptyQueue(CirLinkQueue Q); //队列判空，若为空，则返回1；非空，返回0。
int EnQueue(CirLinkQueue *Q, DataType x);  //  元素x入队，若操作成功，则返回1；操作失败，则返回0。
int DelQueue(CirLinkQueue *Q, DataType *x);  //  出队一个元素，若操作成功，则返回1；操作失败，则返回0。
void DestroyQueue(CirLinkQueue Q);

int main(void)
{
    char cmd[20];
    CirLinkQueue pQueue = InitQueue();
    DataType x;
    scanf("%s", cmd);
    while (strcmp(cmd, "END") != 0)
    {
        if (strcmp(cmd, "ENQUEUE") == 0)
        {
            scanf("%d", &x);
            if (EnQueue(&pQueue, x) == 0)
                 printf("FULL QUEUE!\n");
        }
        else if (strcmp(cmd, "DELQUEUE") == 0)
        {
            if (DelQueue(&pQueue,&x) == 0)
                  printf("EMPTY QUEUE!\n");
            else
                printf("%d\n",x);
        }
        else if (strcmp(cmd, "ISEMPTY") == 0)
        {
            if (IsEmptyQueue(pQueue) == 0)
                 printf("NOT EMPTY\n");
            else
                  printf("EMPTY\n");
        }
        scanf("%s", cmd);
    }
    DestroyQueue(pQueue);
    return 0;
}

void DestroyQueue(CirLinkQueue Q)
{
    LNode *p,*t;
    p=Q;Q=Q->next;
    p->next=NULL;
    p=Q->next;
    while(p)
    {
        printf("%d ",p->data);
        t=p->next;
        free(p);
        p=t;
    }
    free(Q);
}
CirLinkQueue InitQueue() {
	CirLinkQueue p = (CirLinkQueue)malloc(sizeof(LNode));
	p -> next = p;
	return p;
}
int IsEmptyQueue(CirLinkQueue Q) {
	return Q->next == Q ? 1 : 0;
}
int EnQueue(CirLinkQueue * Q,DataType x)
{
	CirLinkQueue newNode = (CirLinkQueue)malloc(sizeof(LNode));
	if(!newNode)
		return 0;
	newNode->data = x;
	newNode->next = (*Q)->next;
	(*Q)->next = newNode;
	*Q = newNode;
	return 1;
}
int DelQueue(CirLinkQueue *Q, DataType *x)
{
    if (IsEmptyQueue(*Q))
        return 0; 
    CirLinkQueue p =  (CirLinkQueue)malloc(sizeof(LNode));
    p = *Q;
   if(p->next->next == p) 
   {
   	*Q = p->next;
   	*x = p->next->next->data;
   	p->next->next = p->next->next->next;
	}        
    else
    {
	*x = p->next->next->data;
	p->next->next = p->next->next->next;
	}
	return 1;
}

