#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// ����ڵ�����
typedef struct node{
    char data;
    struct node* next;
} LinkNode, *Link_Node;

// ջ
typedef struct {
    Link_Node top;
} Stack;

// ����
typedef struct {
    Link_Node rear, front;
} Queue;

// ��ʼ��ջ
void InitStack(Stack* stack) {
    stack->top = NULL;
}

// ��ʼ������
void InitQueue(Queue* queue) {
    queue->front = NULL;
    queue->rear = NULL;
}

// ��ջ
void inStack(Stack *stack, char ch) {
    Link_Node newNode = (Link_Node) malloc(sizeof(LinkNode));
    newNode->data = ch;
    newNode->next = stack->top;
    stack->top = newNode;
}

// ��ջ
char pop(Stack *stack) {
    if (stack->top == NULL) return 0;
    Link_Node p = stack->top;
    char ch = p->data;
    stack->top = p->next;
    free(p);
    return  ch;
}

// ���
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

// ����
char Dequeue(Queue *queue) {
    if (queue->front == NULL) return 0;
    Link_Node p = queue->front;
    char ch = queue->front->data;
    queue->front = p->next;
    free(p);
    return ch;
}

// ����1.1
void ruleOne_one(Queue *queue, char* ch) {
    int i = 0;
    //��ħ���������,ͬʱӦ�ù���1.1,����ĸ B ת��Ϊ t A d A
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

// ����1.2
void ruleOne_two(Queue *queue) {
    Queue temp;
    InitQueue(&temp);
  // �������е�'A'ת����'sae'����ʽ�������´���һ���µĶ������洢ת����ı���
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

// ����2
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
    char str[100][100] = {"��","��","��","һֻ","��","׷","��","��","��","��"};
    printf("���������ħ������: \n");
    scanf("%s",ch);
    Queue queue;
    InitQueue(&queue);
    ruleOne_one(&queue,ch);
    ruleOne_two(&queue);
    ruleTwo(&queue);
    printf("��ħ�����Զ�Ӧ���˻���: \n");
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