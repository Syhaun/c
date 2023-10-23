#include<stdio.h>
#include<stdlib.h>
typedef struct Stacknode
{
    int data;
    struct Stacknode *next;
} slStacktype;
//入栈操作
int PushLstack(slStacktype *top,int x)
{
    slStacktype *p = (slStacktype *)malloc(sizeof(slStacktype));
    p->data = x;
    p->next = top->next;
    top->next = p;
    return 1;
}
//出栈操作
int PopLstack(slStacktype *top)
{
    slStacktype *p;
    int x;
    if(top ->next == NULL)
    {
        printf("此栈未空!");
        return 0;
    }
    p = top->next;
    top->next = p->next;
    x = p->data;
    free(p);
    return x;
}
int main()
{
    return 0;
}