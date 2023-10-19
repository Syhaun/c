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
void print(TSMatrix *M)
{
    int i;

    for (i = 1; i <= M->nums; i++)
    {
        printf("%d %d %d\n", M->data[i].row, M->data[i].col, M->data[i].val);
    }
}

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
    if (A->rows != B->rows || A->cols != B->cols)
    {
        printf("Two Matrixs are not match!\n");
        return -1;
    }

    C->rows = A->rows;
    C->cols = A->cols;
    C->nums = 0;

    for (int i = 1; i <= A->nums; i++)
    {
        int row = A->data[i].row;
        int col = A->data[i].col;
        int val = A->data[i].val;
        C->nums++;
        C->data[C->nums].row = row;
        C->data[C->nums].col = col;
        C->data[C->nums].val = val;
    }

    for (int i = 1; i <= B->nums; i++)
    {
        int row = B->data[i].row;
        int col = B->data[i].col;
        int val = B->data[i].val;
        int found = 0;

        // 查找C中是否已经有相同行、列的元素
        for (int j = 1; j <= C->nums; j++)
        {
            if (C->data[j].row == row && C->data[j].col == col)
            {
                C->data[j].val += val;
                found = 1;
                break;
            }
        }

        // 如果没有找到相同行、列的元素，则将其添加到C中
        if (!found)
        {
            C->nums++;
            C->data[C->nums].row = row;
            C->data[C->nums].col = col;
            C->data[C->nums].val = val;
        }
    }

    return 1;
}