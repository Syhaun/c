#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct node{
    int val;
    struct node *next;

} MyLinkedList;


MyLinkedList* myLinkedListCreate() {
    MyLinkedList* head = (MyLinkedList*)malloc(sizeof(MyLinkedList));
    head->next= NULL;
    return head; 
}

int myLinkedListGet(MyLinkedList* obj, int index) {
    if(index < 0 || obj->next == NULL)
    return -1;
    int i = 0;
    MyLinkedList *p = obj->next;
    while(p && i < index)
    {
        p = p->next;
        i++;
    }
    if(p)
    {
        return p->val;
    }
    return -1;
}

void myLinkedListAddAtHead(MyLinkedList* obj, int val) {
    MyLinkedList *p = (MyLinkedList*)malloc(sizeof(MyLinkedList));
    p->val = val;
    p->next = obj->next;
    obj->next = p;
}

void myLinkedListAddAtTail(MyLinkedList* obj, int val) {
    MyLinkedList *p = obj;
    while(p->next)
    {
        p = p->next;
    }
    MyLinkedList *q = (MyLinkedList*)malloc(sizeof(MyLinkedList));
    q->val = val;
    q->next = NULL;
    p->next = q;
}

void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val) {
    MyLinkedList *p = obj;
    int i = 0;
    while(p&&i<index)
    {
        p = p->next;
        i++;
    }
    if(!p||i >index)
    return ;
    MyLinkedList *q = (MyLinkedList*)malloc(sizeof(MyLinkedList));
    q->val = val;
    q->next = p->next;
    p->next = q;

}

void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index) {
  MyLinkedList *p = obj;
    int i = 0;
    while(p->next&&i<index)
    {
        p = p->next;
        i++;
    }
    if(!(p->next)||i > index)
    {
        return ;
    }
    p->next = p->next->next;
}

void myLinkedListFree(MyLinkedList* obj) {
    free(obj);
}
int main(){
	MyLinkedList* obj = myLinkedListCreate();
	myLinkedListAddAtHead(obj,1);
	myLinkedListAddAtTail(obj,3);
	myLinkedListAddAtIndex(obj,1,2);
	printf("%d\n",myLinkedListGet(obj,0));
		printf("%d\n",myLinkedListGet(obj,1));
			printf("%d\n",myLinkedListGet(obj,2));
			myLinkedListDeleteAtIndex(obj, 2); // The linked list should be: 0 -> 1 -> 3

    // Get elements from the modified linked list and print the values
    printf("Element at index 0: %d\n", myLinkedListGet(obj, 0)); // Output: 0
    printf("Element at index 1: %d\n", myLinkedListGet(obj, 1)); // Output: 1
    printf("Element at index 2: %d\n", myLinkedListGet(obj, 2)); // Output: 3
	}
/**
 * Your MyLinkedList struct will be instantiated and called as such:
 * MyLinkedList* obj = myLinkedListCreate();
 * int param_1 = myLinkedListGet(obj, index);
 
 * myLinkedListAddAtHead(obj, val);
 
 * myLinkedListAddAtTail(obj, val);
 
 * myLinkedListAddAtIndex(obj, index, val);
 
 * myLinkedListDeleteAtIndex(obj, index);
 
 * myLinkedListFree(obj);
*/
