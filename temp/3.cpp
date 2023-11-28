#include <stdio.h>
void quick_sort(int num[], int low, int high)
{
    int i, j, temp;
    int tmp;
    i = low;
    j = high;
    tmp = num[low];
    if (i > j)
    {
        return;
    }
    while (i != j)
    {
        while (num[j] >= tmp && j > i)
        {
            j--;
        }
        while (num[i] <= tmp && j > i)
        {
            i++;
        }
        if (j > i)
        {
            temp = num[j];
            num[j] = num[i];
            num[i] = temp;
        }
    }
    num[low] = num[i];
    num[i] = tmp;
    quick_sort(num, low, i - 1);
    quick_sort(num, i + 1, high);
}
struct Stu
{
    char name[10];
    char num[9];
    int score;
};

int main()
{
    int n, arr[100], i;
    printf("������ͬѧ����: ");
    scanf("%d", &n);
    struct Stu students[100];
    for (i = 0; i < n; i++)
    {
        printf("�������%d��ͬѧ������: ", i + 1);
        scanf("%s", students[i].name);
        printf("�������%d��ͬѧ��ѧ��: ", i + 1);
        scanf("%s", students[i].num);
        printf("�������%d��ͬѧ���۲����: ", i + 1);
        scanf("%d", &students[i].score);
    }
    for (i = 0; i < n; i++)
    {
        arr[i] = students[i].score;
    }
    quick_sort(arr, 0, n - 1);
    int rank = 1;
    for (i = 0; i < n; i++)
    {
        printf("��%d��.%s %s %d", rank, students[i].name, students[i].num, students[i].score);
        rank++;
    }
    return 0;
}
