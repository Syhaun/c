#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAXSIZE 100
typedef struct
{
    int elem[MAXSIZE];
    int top;
} SeqStack;
// ����ջ�ռ�,Ȼ���ʼ��ջ��ָ��
SeqStack *InitStack()
{
    SeqStack *s;
    s = (SeqStack *)malloc(sizeof(SeqStack));
    s->top = -1;
    return s;
}
//�п�ջ
int Empty(SeqStack *s)
{
    if(s->top == -1)
        return -1;
    return 0;
}
//��ջ
int Push(SeqStack *s,int x)
{
    if(s -> top == MAXSIZE - 1)
        return 0;
    else{
        s->top++;
        s->elem[s->top] = x;
        return 1;
    }
}
//��ջ
int Pop(SeqStack *s,int *x)
{
    if(Empty(s))
        return 0;
    else
    {
        *x = s->elem[s->top];
        s->top--;
        return 1;
    }
}
//ȡջ��Ԫ��
int GetTop(SeqStack *s)
{
    if(Empty(s))
        return 0;
    else
        return (s->elem[s->top]);
}
int main()
{
    return 0;
}