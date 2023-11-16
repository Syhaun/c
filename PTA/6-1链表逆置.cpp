#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int data;
    struct ListNode *next;
};

struct ListNode *reverseList(struct ListNode *head)
{
    struct ListNode *dim = (struct ListNode *)malloc(sizeof(struct ListNode));
    dim->next = head;

    struct ListNode *p;
    struct ListNode *q;
    p = dim->next;
    dim->next = NULL;
    while (p)
    {
        q = p->next;
        p->next = dim -> next;
        dim->next = p;
        p = q;
    }

    head = dim->next;
    free(dim);
    return head;
}

struct ListNode *createlist() {
    struct ListNode *head = NULL;
    struct ListNode *current = NULL;
    int data;
    scanf("%d", &data);
    while (data != -1) {
        struct ListNode *newNode = (struct ListNode *)malloc(sizeof(struct ListNode));
        newNode->data = data;
        newNode->next = NULL;
        if (head == NULL) {
            head = newNode;
            current = newNode;
        } else {
            current->next = newNode;
            current = newNode;
        }
        scanf("%d", &data);
    }

    return head;
}

void printlist(struct ListNode *head) {
    struct ListNode *p = head;
    while (p) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

int main() {
    struct ListNode *head;

    head = createlist();
    head = reverseList(head);
    printlist(head);

    return 0;
}


