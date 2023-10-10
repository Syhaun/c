#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ERROR 1e8
typedef int ElementType;
typedef enum { push, pop, end } Operation;
typedef enum { false, true } bool;
typedef int Position;
struct SNode {
    ElementType *Data;
    Position Top1, Top2;
    int MaxSize;
};
typedef struct SNode *Stack;

Stack CreateStack( int MaxSize )
{
    Stack s;
    s=(Stack)malloc(sizeof(struct SNode));
    s->MaxSize=MaxSize;
    s->Data=(ElementType *)malloc(sizeof(ElementType)*MaxSize);
    s->Top1=-1;
    s->Top2=MaxSize;
    return s;
}

/* 请在这里填写答案 */

Operation GetOp()  
{
    char op[5];
    fflush(stdin);
    scanf("%s",op);
    if(strcmp(op,"Push")==0)
        return 0;
    else if(strcmp(op,"Pop")==0)
        return 1;
    else if(strcmp(op,"End")==0)
        return 2;
    return ERROR;
}
void PrintStack( Stack S, int Tag ) 
{
    int i;
    if(Tag==1)
    {
        printf("Pop from Stack 1:");
        i=S->Top1;
        while(i!=-1)
        {
            printf("%d ",S->Data[i]);
            i--;
        }
        S->Top1=-1;
        printf("\n");
    }
    else if(Tag==2)
    {
        printf("Pop from Stack 2:");
        i=S->Top2;
        while(i!=S->MaxSize)
        {
            printf("%d ",S->Data[i]);
            i++;
        }
        S->Top2=S->MaxSize;
        printf("\n");
    }
}

int main()
{
    int N, Tag, X;
    Stack S;
    int done = 0;

    scanf("%d", &N);
    S = CreateStack(N);
    while ( !done ) {
        switch( GetOp() ) {
        case push: 
            scanf("%d %d", &Tag, &X);
            if (!Push(S, X, Tag)) 
                printf("Stack %d is Full!\n", Tag);
            break;
        case pop:
            scanf("%d", &Tag);
            X = Pop(S, Tag);
            if ( X==ERROR ) 
                printf("Stack %d is Empty!\n", Tag);
            break;
        case end:
            PrintStack(S, 1);
            PrintStack(S, 2);
            done = 1;
            break;
        }
    }
    return 0;
}
