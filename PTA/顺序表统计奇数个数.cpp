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
}// 初始化顺序表，细节不提供

int OddNumber(SqList L) {
    int count = 0; // 用于统计奇数的个数
    for (int i = 0; i < L.length; i++) {
        if (L.elem[i] % 2 != 0) {
            count++; // 如果元素是奇数，增加计数器
        }
    }
    return count;
}

int main() {
    SqList L;
    InitList(L); // 初始化顺序表
    printf("The number of odd numbers is %d.\n", OddNumber(L));
    return 0;
}

