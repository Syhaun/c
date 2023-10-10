#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

#define Stack_Size 50
typedef char ElemType;
typedef struct
{      ElemType  data[Stack_Size];
       int  top; 
}SeqStack;

//栈的基本操作函数定义
SeqStack* InitStack();  //栈初始化
int IsEmpty(SeqStack *S); //栈判空
int IsFull(SeqStack *S);  //栈判满
int Push(SeqStack * S, ElemType x);  //  入栈
int Pop(SeqStack * S, ElemType *x);  //  出栈
int GetTop(SeqStack *S, ElemType *x); // 取栈顶元素


int IsBracketMatch(char *str);//判断str中括号是否匹配。

int main()
{
    char s[20];
    scanf("%s",s);
    if( IsBracketMatch(s))
        printf("Match!\n"); 
    else
        printf("Not Match!\n");
}


SeqStack* InitStack()
{
    SeqStack *s;
    s=(SeqStack *)malloc(sizeof(SeqStack));
    s->top=-1;
    return s;
}
int IsEmpty(SeqStack *S)     
{
      return(S->top==-1?TRUE:FALSE);
}
int IsFull(SeqStack *S)
{
   return(S->top== Stack_Size-1?TRUE:FALSE);
}
int Push(SeqStack * S, ElemType x)
{
     if(S->top== Stack_Size-1)  
         return(FALSE); 
     S->top++;
     S->data[S->top]=x;
     return(TRUE);
}
int Pop(SeqStack * S, ElemType *x)
{     if(S->top==-1)     
             return(FALSE);
      *x= S->data[S->top];
      S->top--;    
      return(TRUE);
}
int GetTop(SeqStack *S, ElemType *x)
{  
      if(S->top==-1)
            return(FALSE);
      *x = S->data[S->top];
      return(TRUE);
}

/* 请在这里填写答案 */

int IsBracketMatch(char *str)
{
    SeqStack *stack = InitStack();  // 创建一个栈用于存储括号
    int len = strlen(str);

    for (int i = 0; i < len; i++)
    {
        char currentChar = str[i];

        if (currentChar == '(' || currentChar == '[' || currentChar == '{')
        {
            // 遇到左括号，将其入栈
            Push(stack, currentChar);
        }
        else if (currentChar == ')' || currentChar == ']' || currentChar == '}')
        {
            // 遇到右括号，检查栈是否为空
            if (IsEmpty(stack))
            {
                // 如果栈为空，右括号没有匹配的左括号，返回不匹配
                free(stack);
                return FALSE;
            }

            char topChar;
            Pop(stack, &topChar);

            // 检查栈顶元素是否与当前右括号匹配
            if ((currentChar == ')' && topChar != '(') ||
                (currentChar == ']' && topChar != '[') ||
                (currentChar == '}' && topChar != '{'))
            {
                // 括号不匹配，返回不匹配
                free(stack);
                return FALSE;
            }
        }
    }

    // 所有字符处理完毕后，检查栈是否为空
    int isMatch = IsEmpty(stack) ? TRUE : FALSE;

    free(stack);
    return isMatch;
}













