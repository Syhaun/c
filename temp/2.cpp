#include<stdio.h>
    // 求最大公约数
    int fun(int x, int y)
{
    int r, t, a;
    if (x < y)
    {
        t = x;
        x = y;
        y = t;
    }
    while (r = x % y)
    {
        x = y;
        y = r;
    }
    return y;
}
int main()
{
    int a1, b1, a2, b2, c, d, t, a; // c是加起来的分子 d是分母的最小公倍数  t是最后分子分母的最大公约数
    char p;
    scanf("%d%c%d", &a1, &p, &b1);
    scanf("%d%c%d", &a2, &p, &b2);
    a = fun(b1, b2);
    d = b1 * b2 / a;
    c = d / b1 * a1 + d / b2 * a2;
    t = fun(c, d);
    d /= t;
    c /= t;
    if (d == 1)
        printf("%d", c);
    else
        printf("%d/%d", c, d);
    return 0;
}
