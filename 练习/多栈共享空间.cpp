#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 100
typedef struct
{
    int elem[MAXSIZE];
    int lefttop;
    int righttop;
} Dupsqtck;
//ջ�ĳ�ʼ��
int InitDupStack(Dupsqtck *s)
{
    //�������������ڽӿռ�Ŀ�ջ��ָ��sָ��
    if((s = (Dupsqtck *)malloc(sizeof(Dupsqtck))) == NULL)
        return 0;
    s->lefttop = -1;
    s->righttop = MAXSIZE;
    return 1;
}
//��ջ����
int PushDuqStack(Dupsqtck *s,char status,int x)
{
    //������Ԫ��xѹ����ջ����ջ
    if(s->lefttop +1 == s->righttop)
        return 0;
    if(status == 'L')
        s->elem[++s->lefttop] = x;
    else if(status == 'R')
        s->elem[--s->righttop] = x;
    else
        return 0;
    return 1;
}
//��ջ����
int PopDupStack(Dupsqtck *s,char status)
{
    if(status == 'L')
    {
        if(s->lefttop < 0)
            return NULL;
        else
            return (s->elem[s->lefttop--]);
    }
    else if(status == 'R')
    {
        if(s->righttop >MAXSIZE - 1)
            return NULL;
        else
            return (s->elem[s->righttop++]);
    }
    else
        return NULL;
}
int main()
{
    return 0;
}