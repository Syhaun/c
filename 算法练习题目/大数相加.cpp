#include <stdio.h>
#include <string.h>
int ca[150], cb[150], ia[600], ib[600], c[600], i, j, flag, l, k;
int main()
{
    for (scanf("%s%s", &ca, &cb), l = 0, k = strlen((char *)ca) + strlen((char *)cb) + 1198; l < k; l < strlen((char *)ca) ? (l == 0 ? (i = strlen((char *)ca) - 1, j = 599) : 1, ia[j] = ((char *)ca)[i] - '0', i--, j--) : (l >= strlen((char *)ca) && l < k - 1198 ? (l == strlen((char *)ca) ? (i = strlen((char *)cb) - 1, j = 599) : 1, ib[j] = ((char *)cb)[i] - '0', i--, j--) : (l >= k - 1198 && l < k - 599 ? (l == k - 1198 ? i = 599 : 1, ia[i] + ib[i] + c[i] < 10 ? c[i] += ia[i] + ib[i] : (c[i] = (ia[i] + ib[i] + c[i]) % 10, c[i - 1] = 1), i--) : (l == k - 599 ? i = 0 : 1, flag == 0 ? (c[i] != 0 ? (printf("%d", c[i]), flag = 1) : 1) : printf("%d", c[i]), i++))), l++)
        ;
    return printf("%d", c[599]) & 0;
}