#include <stdio.h>
#include<string.h>
#define MAXS 30

char *search(char *s, char *t);
void ReadString(char s[]); /* 裁判提供，细节不表 */

int main()
{
    char s[MAXS], t[MAXS], *pos;

    ReadString(s);
    ReadString(t);
    pos = search(s, t);
    if (pos != NULL)
        printf("%d\n", pos - s);
    else
        printf("-1\n");

    return 0;
}

/* 你的代码将被嵌在这里 */
char *search(char *s, char *t)
{
    int len1 = strlen(s);
    int len2 = strlen(t);
    for (int i = 0; i <= len1 - len2; i++)
    {
        int j;
        for (j = 0; j < len2; j++)
        {
            if (s[i + j] != t[j])
                break;
        }
        if (j == len2)
            return &s[i];
    }

    return NULL;
}
void ReadString(char s[])
{
    fgets(s, MAXS, stdin);
    // 移除换行符，如果存在的话
    size_t len = strlen(s);
    if (len > 0 && s[len - 1] == '\n')
    {
        s[len - 1] = '\0';
    }
}