#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
} QNode;//�������������
typedef struct
{
    QNode *front;
    QNode *rear;
} LQueue;//��ͷβָ���װ��һ���������
//����һ����ͷ���Ŀն�
LQueue *Init_LQueue()
{
    LQueue *q;
    QNode *p;
    q = (LQueue *)malloc(sizeof(LQueue));//����ͷβָ����
    p = (QNode *)malloc(sizeof(QNode));//����������ͷ���
    p->next = NULL;
    q->front = q->rear = p;
    return q;
}
//�жϿ�
int Empty_LQueue(LQueue *q)
{
    if(q->front == q->rear)
        return 0;
    return 1;
}
//���
void InLQueue(LQueue *q,int x)
{
    QNode *p;
    p = (QNode *)malloc(sizeof(QNode));//�����½��
    p->data = x;
    p->next = NULL;
    q->rear->next = p;
    q->rear = p;
}
//����
int Out_LQueue(LQueue *q,int *x)
{
    QNode *p;
    if(Empty_LQueue(q))
    {
        printf("�ӿ�");
        return 0;
    }
    else
    {
        p = q->front->next;
        q->front->next = p->next;
        *x = p->data;
        free(p);
        if(q->front->next == NULL)//ֻ��һ��Ԫ��ʱ,���Ӻ�ӿ�,�޸Ķ�βָ��
            q->rear = q->front;
        return 1;
    }
}

int main()
{
    LQueue *q;
    return 0;
}