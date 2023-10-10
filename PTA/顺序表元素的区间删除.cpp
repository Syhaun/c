#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 20

typedef int ElemType;
typedef struct
{
    ElemType elem[MAXSIZE];
    int length;
}SeqList;

/* 请在这里填写答案 */
int Delete(SeqList *L, int minA, int maxA) {
    int len = L->length;
    int i = 0;
    while (i < len) {
        if (L->elem[i] > minA && L->elem[i] < maxA) {
            for (int j = i; j < len - 1; j++) {
                L->elem[j] = L->elem[j + 1];
            }
            len--; 
        } else {
            i++; 
        }
    }
    L->length = len; 
    return len;
}


int main()
{
    int len,minA, maxA, i;
      SeqList L;

    scanf("%d", &len);
    for (i=0; i<len; i++) 
             scanf("%d", &(L.elem[i]));
      L.length=len;
    scanf("%d %d", &minA, &maxA);

    len= Delete(&L,minA,maxA);

    for (i=0; i<len; i++) 
              printf("%d ", L.elem[i]);
    printf("\n");

    return 0;
}

