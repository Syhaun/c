#include <stdio.h>
#include <stdlib.h>

#define N 3
#define M 4

typedef struct
{
    int row, col;
    int val;
} saddle;
int MAssign(int Matrix[N][M])
{
    int i, j;

    for (i = 0; i < N; i++)
        for (j = 0; j < M; j++)
            scanf("%d", &(Matrix[i][j]));
    return N * M;
}

int find(int Matrix[N][M], saddle *result);
void print(saddle *S, int count); // 忽略输出函数的实现

int main()
{
    int Matrix[N][M];
    int count;
    saddle result[N * M];
    MAssign(Matrix);
    count = find(Matrix, result);
    if (count == 0)
        printf("no saddle point!");
    else
        print(result, count);
}

/* 请在这里填写答案 */
int find(int Matrix[N][M], saddle *result)
{
    int count = 0;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            int val = Matrix[i][j];
            int is_saddle = 1; // 假设当前元素是鞍点

            // 检查当前元素是否小于当前行的所有其他元素
            for (int k = 0; k < M; k++)
            {
                if (k != j && val > Matrix[i][k])
                {
                    is_saddle = 0; // 当前元素不是鞍点
                    break;
                }
            }

            // 检查当前元素是否大于当前列的所有其他元素
            for (int k = 0; k < N; k++)
            {
                if (k != i && val < Matrix[k][j])
                {
                    is_saddle = 0; // 当前元素不是鞍点
                    break;
                }
            }

            // 如果当前元素是鞍点，将其记录下来
            if (is_saddle)
            {
                result[count].row = i;
                result[count].col = j;
                result[count].val = val;
                count++;
            }
        }
    }

    return count;
}
