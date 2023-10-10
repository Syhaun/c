#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXSIZE 4 //队列的最大容量
typedef int ElemType;
typedef struct
{
    ElemType elem[MAXSIZE];
    int rear;    //队尾元素的位置
    int quelen;  //队中元素的个数
} SeQueue;

//队列的基本操作函数定义
SeQueue *InitQueue(); //初始化队列，返回值为指向队列的指针。
void DestroyQueue(SeQueue *Q); //依次输出队列中元素值，并释放空间。

int IsEmptyQueue(SeQueue *Q); //队列判空，若为空，则返回1；非空，返回0。
int IsFullQueue(SeQueue *Q); //队列判满，若为满，则返回1；非满，返回0。
int EnQueue(SeQueue *Q, ElemType x); // 元素x入队，若操作成功，则返回1；操作失败，则返回0。
int DelQueue(SeQueue *Q, ElemType *x); // 出队一个元素，若操作成功，则返回1；操作失败，则返回0。

SeQueue *InitQueue() //初始化队列，返回值为指向队列的指针。
{
    SeQueue *q;
    q = (SeQueue *)malloc(sizeof(SeQueue));
    q->quelen = 0;
    q->rear = -1;
    return q;
}

void DestroyQueue(SeQueue *Q)
{
    ElemType x;
    while (!IsEmptyQueue(Q))
    {
        DelQueue(Q, &x);
        printf("%d ", x);
    }
    printf("\n");
    free(Q);
}

int IsEmptyQueue(SeQueue *Q)
{
    return Q->quelen == 0 ? 1 : 0;
}

int IsFullQueue(SeQueue *Q)
{
    return Q->quelen == MAXSIZE ? 1 : 0;
}

int EnQueue(SeQueue *Q, ElemType x)
{
    if (IsFullQueue(Q))
    {
        return 0; // 队列已满，操作失败
    }
    else
    {
        Q->rear = (Q->rear + 1) % MAXSIZE; // 队尾位置移动
        Q->elem[Q->rear] = x;             // 元素入队
        Q->quelen++;                      // 队中元素个数加1
        return 1;                          // 操作成功
    }
}

int DelQueue(SeQueue *Q, ElemType *x)
{
    if (IsEmptyQueue(Q))
    {
        return 0; // 队列为空，操作失败
    }
    else
    {
        *x = Q->elem[(Q->rear - Q->quelen + 1 + MAXSIZE) % MAXSIZE]; // 获取队头元素
        Q->quelen--;                                                  // 队中元素个数减1
        return 1;                                                      // 操作成功
    }
}

