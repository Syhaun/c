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
    // 输入矩阵的行数、列数、非零元素个数
    scanf("%d %d %d", &M->rows, &M->cols, &M->nums);

    // 逐个输入非零元素的行、列、值
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

int Add(TSMatrix *A, TSMatrix *B, TSMatrix *C); // 实现C=A+B
void print(TSMatrix *M);                        // 输出和矩阵，请忽略该函数的实现

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

/* 请在这里填写答案 */
int Add(TSMatrix *A, TSMatrix *B, TSMatrix *C)
{
    
}