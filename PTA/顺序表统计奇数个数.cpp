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
}// ��ʼ��˳���ϸ�ڲ��ṩ

int OddNumber(SqList L) {
    int count = 0; // ����ͳ�������ĸ���
    for (int i = 0; i < L.length; i++) {
        if (L.elem[i] % 2 != 0) {
            count++; // ���Ԫ�������������Ӽ�����
        }
    }
    return count;
}

int main() {
    SqList L;
    InitList(L); // ��ʼ��˳���
    printf("The number of odd numbers is %d.\n", OddNumber(L));
    return 0;
}

