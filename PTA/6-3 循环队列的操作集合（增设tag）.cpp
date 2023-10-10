#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXSIZE 4 //���е��������
typedef int ElemType;
typedef struct
{      
    ElemType  elem[MAXSIZE];
    int rear;  //��βԪ�ص�λ��
    int front; //��ͷԪ�ص�ǰһ��λ��
    int tag;//��־���һ�ζ��в�������ӻ��ǳ��ӡ������Ϊ1��������Ϊ0��
}SeqQueue;

//���еĻ���������������
SeqQueue * InitQueue();  //��ʼ�����У�����ֵΪָ����е�ָ�롣
void DestroyQueue(SeqQueue *Q); //�������������Ԫ��ֵ�����ͷſռ䡣

int IsEmptyQueue(SeqQueue *Q); //�����пգ���Ϊ�գ��򷵻�1���ǿգ�����0��
int IsFullQueue(SeqQueue *Q); //������������Ϊ�����򷵻�1������������0��
int EnQueue(SeqQueue *Q, ElemType x);  //  Ԫ��x��ӣ��������ɹ����򷵻�1������ʧ�ܣ��򷵻�0��
int DelQueue(SeqQueue *Q, ElemType *x);  //  ����һ��Ԫ�أ��������ɹ����򷵻�1������ʧ�ܣ��򷵻�0��


int main(void)
{
    char cmd[20];
    SeqQueue *pQueue=InitQueue();
    ElemType x;
    scanf("%s", cmd);
    while (strcmp(cmd, "END") != 0)
    {
        if (strcmp(cmd, "ENQUEUE") == 0)
        {
            scanf("%d", &x);
            if (EnQueue(pQueue, x) == 0)
                 printf("FULL QUEUE!\n");
        }
        else if (strcmp(cmd, "DELQUEUE") == 0)
        {
            if (DelQueue(pQueue,&x) == 0)
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
        else if (strcmp(cmd, "ISFULL") == 0)
        {
            if (IsFullQueue(pQueue) == 0)
                 printf("NOT FULL\n");
            else
                  printf("FULL\n");
        }
        scanf("%s", cmd);
    }
    DestroyQueue(pQueue);
    return 0;
}

void DestroyQueue(SeqQueue *Q)
{
    ElemType x;
    while(!IsEmptyQueue(Q))
    {
        DelQueue(Q,&x);
        printf("%d ",x);
    }
    printf("\n");
    free(Q);
}

/* ����������д�� */
SeqQueue *InitQueue()
{
    SeqQueue *Q = (SeqQueue *)malloc(sizeof(SeqQueue));
    if (Q)
    {
        Q->rear = 0;
        Q->front = 0;
        Q->tag = 0;
        return Q;
    }
    return NULL;
}
int IsEmptyQueue(SeqQueue *Q)
{
    return (Q->tag == 0 && Q->rear == Q->front);
}
int IsFullQueue(SeqQueue *Q)
{
    return (Q->tag == 1 && Q->rear == Q->front);
}
int EnQueue(SeqQueue *Q, ElemType x)
{
    if (IsFullQueue(Q))
        return 0; 
    Q->elem[Q->rear] = x;
    Q->rear = (Q->rear + 1) % MAXSIZE;
    Q->tag = 1; 
    return 1; 
}
int DelQueue(SeqQueue *Q, ElemType *x)
{
    if (IsEmptyQueue(Q))
        return 0;
    *x = Q->elem[Q->front];
    Q->front = (Q->front + 1) % MAXSIZE;
    Q->tag = 0;
    return 1; 
}
