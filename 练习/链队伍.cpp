#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
} QNode;//链队伍结点的类型
typedef struct
{
    QNode *front;
    QNode *rear;
} LQueue;//将头尾指针封装在一起的链队伍
//创建一个带头结点的空队
LQueue *Init_LQueue()
{
    LQueue *q;
    QNode *p;
    q = (LQueue *)malloc(sizeof(LQueue));//申请头尾指针结点
    p = (QNode *)malloc(sizeof(QNode));//申请链队列头结点
    p->next = NULL;
    q->front = q->rear = p;
    return q;
}
//判断空
int Empty_LQueue(LQueue *q)
{
    if(q->front == q->rear)
        return 0;
    return 1;
}
//入队
void InLQueue(LQueue *q,int x)
{
    QNode *p;
    p = (QNode *)malloc(sizeof(QNode));//申请新结点
    p->data = x;
    p->next = NULL;
    q->rear->next = p;
    q->rear = p;
}
//出队
int Out_LQueue(LQueue *q,int *x)
{
    QNode *p;
    if(Empty_LQueue(q))
    {
        printf("队空");
        return 0;
    }
    else
    {
        p = q->front->next;
        q->front->next = p->next;
        *x = p->data;
        free(p);
        if(q->front->next == NULL)//只有一个元素时,出队后队空,修改队尾指针
            q->rear = q->front;
        return 1;
    }
}

int main()
{
    LQueue *q;
    return 0;
}