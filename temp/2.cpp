#include<stdio.h>
    // �����Լ��
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
    int a1, b1, a2, b2, c, d, t, a; // c�Ǽ������ķ��� d�Ƿ�ĸ����С������  t�������ӷ�ĸ�����Լ��
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
