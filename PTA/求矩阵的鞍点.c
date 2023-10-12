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
void print(saddle *S, int count); // �������������ʵ��

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

/* ����������д�� */
int find(int Matrix[N][M], saddle *result)
{
    int count = 0;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            int val = Matrix[i][j];
            int is_saddle = 1; // ���赱ǰԪ���ǰ���

            // ��鵱ǰԪ���Ƿ�С�ڵ�ǰ�е���������Ԫ��
            for (int k = 0; k < M; k++)
            {
                if (k != j && val > Matrix[i][k])
                {
                    is_saddle = 0; // ��ǰԪ�ز��ǰ���
                    break;
                }
            }

            // ��鵱ǰԪ���Ƿ���ڵ�ǰ�е���������Ԫ��
            for (int k = 0; k < N; k++)
            {
                if (k != i && val < Matrix[k][j])
                {
                    is_saddle = 0; // ��ǰԪ�ز��ǰ���
                    break;
                }
            }

            // �����ǰԪ���ǰ��㣬�����¼����
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
