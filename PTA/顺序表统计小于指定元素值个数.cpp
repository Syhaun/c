#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100
typedef int ElemType;
typedef struct
{
    ElemType *elem;
    int length;
} SqList;

void InitList(SqList &L) {
    L.elem = (ElemType *)malloc(MAXSIZE * sizeof(ElemType));
    L.length = 0;
    int num;
    while (scanf("%d", &num) && num != -1) {
        L.elem[L.length++] = num;
    }
}

int GetSmaller(SqList L, ElemType e) {
    int count = 0;
    for (int i = 0; i < L.length; i++) {
        if (L.elem[i] < e) {
            count++;
        }
    }
    return count;
}

int main() {
    SqList L;
    InitList(L);
    ElemType e;
    scanf("%d", &e);
    printf("The number smaller than %d is %d.\n", e, GetSmaller(L, e));
    free(L.elem);
    return 0;
}

