#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXSIZE 4 //���е��������
typedef int ElemType;
typedef struct
{
    ElemType elem[MAXSIZE];
    int rear;    //��βԪ�ص�λ��
    int quelen;  //����Ԫ�صĸ���
} SeQueue;

//���еĻ���������������
SeQueue *InitQueue(); //��ʼ�����У�����ֵΪָ����е�ָ�롣
void DestroyQueue(SeQueue *Q); //�������������Ԫ��ֵ�����ͷſռ䡣

int IsEmptyQueue(SeQueue *Q); //�����пգ���Ϊ�գ��򷵻�1���ǿգ�����0��
int IsFullQueue(SeQueue *Q); //������������Ϊ�����򷵻�1������������0��
int EnQueue(SeQueue *Q, ElemType x); // Ԫ��x��ӣ��������ɹ����򷵻�1������ʧ�ܣ��򷵻�0��
int DelQueue(SeQueue *Q, ElemType *x); // ����һ��Ԫ�أ��������ɹ����򷵻�1������ʧ�ܣ��򷵻�0��

SeQueue *InitQueue() //��ʼ�����У�����ֵΪָ����е�ָ�롣
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
        return 0; // ��������������ʧ��
    }
    else
    {
        Q->rear = (Q->rear + 1) % MAXSIZE; // ��βλ���ƶ�
        Q->elem[Q->rear] = x;             // Ԫ�����
        Q->quelen++;                      // ����Ԫ�ظ�����1
        return 1;                          // �����ɹ�
    }
}

int DelQueue(SeQueue *Q, ElemType *x)
{
    if (IsEmptyQueue(Q))
    {
        return 0; // ����Ϊ�գ�����ʧ��
    }
    else
    {
        *x = Q->elem[(Q->rear - Q->quelen + 1 + MAXSIZE) % MAXSIZE]; // ��ȡ��ͷԪ��
        Q->quelen--;                                                  // ����Ԫ�ظ�����1
        return 1;                                                      // �����ɹ�
    }
}

