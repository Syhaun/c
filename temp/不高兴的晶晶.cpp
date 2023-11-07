#include <stdio.h>
int main()
{
    int t1 = 0;
    int t2 = 0;
    int max = 0;
    int result = 0;
    int i;
    for (i = 1; i <= 7; i++)
    {
        scanf("%d %d", &t1, &t2);
        if (t1 + t2 > 8 && t1 + t2 > max)
        {
            max = t1 + t2;
            result = i;
        }
    }
    printf("%d\n", result);
    return 0;
}