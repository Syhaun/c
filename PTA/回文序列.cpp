#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int top;
    char elem[128];
} SeqStack;

SeqStack *initStack() {
    SeqStack *s;
    s = (SeqStack *)malloc(sizeof(SeqStack));
    s->top = -1;
    return s;
}

int IsEmpty(SeqStack *s) {
    return s->top == -1 ? 1 : 0;
}

int IsFull(SeqStack *s) {
    return s->top == 127 ? 1 : 0;
}

int push(SeqStack *s, char x) {
    if (!IsFull(s)) {
        s->top++;
        s->elem[s->top] = x;
        return 1;
    } else {
        return 0;
    }
}

int pop(SeqStack *s, char *x) {
    if (!IsEmpty(s)) {
        *x = s->elem[s->top];
        s->top--;
        return 1;
    } else {
        return 0;
    }
}

int gettop(SeqStack *s, char *x) {
    if (!IsEmpty(s)) {
        *x = s->elem[s->top];
        return 1;
    } else {
        return 0;
    }
}

char *hw_judge(char *str) {
    SeqStack *s = initStack();
    int len = strlen(str);
    int mid = len / 2;
    int i = 0;
    
	while (str[i] != '&' && i < mid)
	{
	push(s,str[i]);
	i++;
	}
	
	if(i < mid)
	{
		free(s);
		return "NO";
	}


	if(len % 2 == 0)
	i++;
	
	
	while(str[i] != '@' && i < len)
	{
		char x;
        if (pop(s, &x) != 1 || x != str[i])
		{
            free(s);
            return "NO";
        }
        i++;
	}
	
	if (i < len)
	{
        free(s);
        return "NO";
    }

	if(!IsEmpty(s)) {
		free(s);
		return "NO";
	}
    free(s);
	return "YES";		
}

int main() {
    char str[80];
    scanf("%s", str);
    printf("%s", hw_judge(str));
    return 0;
}

