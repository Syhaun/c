#include<stdio.h> 
int min(int x, int y)
{
    if (x > y)
        return y;
    else
        return x;
}
int max(int x, int y)
{
    if (x > y)
        return x;
    else
        return y;
}
int main()
{
    int x, y, z, a, b, c;
    scanf("%d %d %d", &x, &y, &z);
    char arr[3];
    int sum = x + y + z;
    a = min(min(x, y), z);
    c = max(max(x, y), z);
    b = sum - a - c;
    // char temp1 = getchar();
    // printf("%c", temp1);
    //  printf("111111");
    // char  temp = getchar();
    // printf("%c", temp);
    getchar();
    for (int i = 0; i < 3; i++)
    {
        scanf("%c", &arr[i]);
        if (arr[i] == 'A')
            printf("%d ", a);
        if (arr[i] == 'B')
            printf("%d ", b);
        if (arr[i] == 'C')
            printf("%d ", c);
    }
    return 0;
}