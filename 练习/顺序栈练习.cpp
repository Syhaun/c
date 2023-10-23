#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAXSIZE 100
typedef struct
{
    int elem[MAXSIZE];
    int top;
} SeqStack;
// 建立栈空间,然后初始化栈顶指针
SeqStack *InitStack()
{
    SeqStack *s;
    s = (SeqStack *)malloc(sizeof(SeqStack));
    s->top = -1;
    return s;
}
//判空栈
int Empty(SeqStack *s)
{
    if(s->top == -1)
        return -1;
    return 0;
}
//入栈
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
//出栈
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
//取栈顶元素
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