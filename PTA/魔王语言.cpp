#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// 定义节点类型
typedef struct node{
    char data;
    struct node* next;
} LinkNode, *Link_Node;

// 栈
typedef struct {
    Link_Node top;
} Stack;

// 队列
typedef struct {
    Link_Node rear, front;
} Queue;

// 初始化栈
void InitStack(Stack* stack) {
    stack->top = NULL;
}

// 初始化队列
void InitQueue(Queue* queue) {
    queue->front = NULL;
    queue->rear = NULL;
}

// 进栈
void inStack(Stack *stack, char ch) {
    Link_Node newNode = (Link_Node) malloc(sizeof(LinkNode));
    newNode->data = ch;
    newNode->next = stack->top;
    stack->top = newNode;
}

// 出栈
char pop(Stack *stack) {
    if (stack->top == NULL) return 0;
    Link_Node p = stack->top;
    char ch = p->data;
    stack->top = p->next;
    free(p);
    return  ch;
}

// 入队
void Enqueue(Queue* queue,char ch){
    Link_Node newNode = (Link_Node)malloc(sizeof(LinkNode));
    newNode->data = ch;
    newNode->next = NULL;

    if (queue->front == NULL){
        queue->front = queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
}

// 出队
char Dequeue(Queue *queue) {
    if (queue->front == NULL) return 0;
    Link_Node p = queue->front;
    char ch = queue->front->data;
    queue->front = p->next;
    free(p);
    return ch;
}

// 规则1.1
void ruleOne_one(Queue *queue, char* ch) {
    int i = 0;
    //将魔王语言入队,同时应用规则1.1,将字母 B 转化为 t A d A
    while(ch[i] != '\0'){
        if(ch[i] == 'B'){
            Enqueue(queue,'t');
            Enqueue(queue,'A');
            Enqueue(queue,'d');
            Enqueue(queue,'A');
        } else {
            Enqueue(queue,ch[i]);
        }
        i++;
    }
}

// 规则1.2
void ruleOne_two(Queue *queue) {
    Queue temp;
    InitQueue(&temp);
  // 将队列中的'A'转换成'sae'的形式，并重新创建一个新的队列来存储转换后的编码
    while (queue->front){
        if(queue->front->data == 'A'){
            Enqueue(&temp,'s');
            Enqueue(&temp,'a');
            Enqueue(&temp,'e');
            Dequeue(queue);
        } else {
            Enqueue(&temp, Dequeue(queue));
        }
    }
    *queue = temp;
}

// 规则2
void ruleTwo(Queue *queue) {
    Queue temp;
    InitQueue(&temp);
    Stack stack;
    InitStack(&stack);

    while (queue->front){
        if(queue->front->data == '('){
            Dequeue(queue);
            char str = Dequeue(queue);
            Enqueue(&temp,str);
            while (queue->front->data != ')'){
                inStack(&stack,Dequeue(queue));
            }
            while (stack.top){
                Enqueue(&temp, pop(&stack));
                Enqueue(&temp,str);
            }
        } else {
            Enqueue(&temp, Dequeue(queue));
        }
    }
    *queue = temp;
}

int main(){
    char ch[50];
    char s[100] ="tdsaezgxnh";
    char str[100][100] = {"天","地","上","一只","鹅","追","赶","下","蛋","恨"};
    printf("请输入你的魔王语言: \n");
    scanf("%s",ch);
    Queue queue;
    InitQueue(&queue);
    ruleOne_one(&queue,ch);
    ruleOne_two(&queue);
    ruleTwo(&queue);
    printf("该魔王语言对应的人话是: \n");
    while (queue.front){
        char ch = Dequeue(&queue);
        for(int i = 0; i < strlen(s); i++) {
            if (ch == s[i]) {
                printf("%s", str[i]);
            }
        }
    }
    return 0;
}