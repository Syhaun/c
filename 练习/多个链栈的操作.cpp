#include<stdio.h>
#include<stdlib.h>
typedef struct Stacknode
{
    int data;
    struct Stacknode *next;
} slStacktype;
//��ջ����,��Ԫ��xѹ����ջtop[i]��
int PushDupLs(slStacktype * top[],int i,int x)
{
    slStacktype *p;
    p = (slStacktype *)malloc(sizeof(slStacktype));
    p->data = x;
    p->next = top[i]->next;
    top[i]->next = p;
    return 1;
}
//��ջ����,����ջtop[i]��ɾ��ջ��Ԫ��
int PopDupLs(slStacktype *top[],int i)
{
    slStacktype *p;
    int x;
    if(top[i] ->next == NULL)
    {
        printf("��ջΪ��!");
        return;
    }
    p = top[i]->next;
    top[i]->next = p->next;
    x = p->data;
    return x;
}
int main()
{
    int M = 0;//��ջ�ĸ���
    scanf("%d", &M);
    slStacktype **top = (slStacktype**)malloc(M*sizeof(slStacktype*));
    for (int i = 0; i < M; i++)
    {
        top[i] = (slStacktype *)malloc(sizeof(slStacktype));
    }

        return 0;
}