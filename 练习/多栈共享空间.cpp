#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 100
typedef struct
{
    int elem[MAXSIZE];
    int lefttop;
    int righttop;
} Dupsqtck;
//栈的初始化
int InitDupStack(Dupsqtck *s)
{
    //创建两个共享邻接空间的空栈由指针s指出
    if((s = (Dupsqtck *)malloc(sizeof(Dupsqtck))) == NULL)
        return 0;
    s->lefttop = -1;
    s->righttop = MAXSIZE;
    return 1;
}
//入栈操作
int PushDuqStack(Dupsqtck *s,char status,int x)
{
    //把数据元素x压入左栈或右栈
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
//出栈操作
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