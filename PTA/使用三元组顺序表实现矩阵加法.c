#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 20
typedef struct
{
    int row, col;
    int val;
} Triple;
typedef struct
{
    Triple data[MAXSIZE];
    int rows, cols, nums;
} TSMatrix;

int MInit(TSMatrix *M)
{
    M->rows = M->cols = M->nums = 0;
    return 1;
}
int Assign(TSMatrix *M)
{
    int count = 0, i;
    // ������������������������Ԫ�ظ���
    scanf("%d %d %d", &M->rows, &M->cols, &M->nums);

    // ����������Ԫ�ص��С��С�ֵ
    for (i = 1; i <= M->nums; i++)
    {
        scanf("%d %d %d", &M->data[i].row, &M->data[i].col, &M->data[i].val);
        if (M->data[i].row > M->rows || M->data[i].col > M->cols)
        {
            printf("data error!please input again.\n");
            i--;
        }
    }
    return 1;
}

int Add(TSMatrix *A, TSMatrix *B, TSMatrix *C); // ʵ��C=A+B
void print(TSMatrix *M);                        // ����;�������Ըú�����ʵ��

int main()
{
    TSMatrix A, B, C;

    MInit(&A);
    MInit(&B);
    MInit(&C);

    Assign(&A);
    Assign(&B);

    if (Add(&A, &B, &C) != -1)
        print(&C);
}

/* ����������д�� */
int Add(TSMatrix *A, TSMatrix *B, TSMatrix *C)
{
    
}