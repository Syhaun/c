#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int data;
    struct ListNode *next;
};

struct ListNode *reverse(struct ListNode *head) {
    struct ListNode *prev = NULL; 
    struct ListNode *current = head;
    struct ListNode *next = NULL;

    while (current != NULL) {
        next = current->next; 
        current->next = prev; 

        prev = current; 
        current = next;
    }

  
    return prev;
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
    head = reverse(head);
    printlist(head);

    return 0;
}


