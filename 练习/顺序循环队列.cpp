#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 100
typedef struct
{
    int elem[MAXSIZE];
    int rear, front;
} CSeQueue;
//置空队
CSeQueue * InitSeQueue()
{
   CSeQueue *q = (CSeQueue *)malloc(sizeof(CSeQueue));
   q->front = q->rear = MAXSIZE - 1;
   return q;
}
//入队
int InSeQueue(CSeQueue *q,int x)
{
    if((q->rear + 1) % MAXSIZE == q->front)
    {
        printf("队满");
        return 0;
    }
    else
    {
        q->rear = (q->rear + 1) % MAXSIZE;
        q->elem[q->rear] = x;
        return 1;
    }
}
//出队
int OutSeQueue(CSeQueue *q,int *x)
{
    if(q->front == q->rear)
    {
        printf("队空");
        return 0;
    }
    else
    {
        q->front = (q->front + 1) % MAXSIZE;
        *x = q->elem[q->front];
        return 1;
    }
}
//判队空
int EmptySeQueue(CSeQueue *q)
{
    if(q->front == q->front)
        return 1;
    return 0;
}
int main()
{
    return 0;
}