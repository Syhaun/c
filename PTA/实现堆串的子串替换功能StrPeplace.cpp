#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct 
{
    /* data */
    char *ch;
    int len;
}HString;

void HStrInit(HString *s) // 初始化堆串
{
    s->ch = NULL;
    s->len = 0;
}
int HStrAssign(HString *s, char *chars) // 堆串赋值
{
    int i = 0;
    while (chars[i] != '\0')
        i++;
    s->len = i;
    if (s->len != 0)
    {
        if (s->ch != NULL)
            free(s->ch);
        s->ch = (char *)malloc((s->len + 1) * sizeof(char));
        if (s->ch == NULL)
            return 0;
        for (i = 1; i <= s->len; i++)
            s->ch[i] = chars[i - 1];
    }
    else
        s->ch = NULL;
    return 1;
}
int main()
{
    HString hs1, hs2, hs3;
    char chars1[80], chars2[80], chars3[80];
    scanf("%s", chars1);
    scanf("%s", chars2);
    scanf("%s", chars3);

    HStrInit(&hs1);
    HStrInit(&hs2);
    HStrInit(&hs3);
    HStrAssign(&hs1, chars1);
    HStrAssign(&hs2, chars2);
    HStrAssign(&hs3, chars3);

    HStrReplace(&hs1, &hs2, &hs3);
    hs1.ch[hs1.len + 1] = '\0';
    printf("%s", &(hs1.ch[1]));
    return 0;
}

/* 请在这里填写答案 */
int HStrReplace(HString *s, HString *T, HString *V)
{
    if (s->len == 0 || T->len == 0)
    {
        return 0; // 无效输入
    }
    int index = 1;        // 从s的第一个字符开始查找子串T
    int replaceCount = 0; // 记录替换的次数

    // 创建一个临时堆串，用于保存替换后的结果
    HString result;
    HStrInit(&result);

    while (index <= s->len)
    {
        // 在s中查找子串T的位置
        int position = index;
        int tIndex = 1; // 用于匹配T的索引
        while (tIndex <= T->len && position <= s->len)
        {
            if (s->ch[position] == T->ch[tIndex])
            {
                tIndex++;
                position++;
            }
            else
            {
                break; // 不匹配
            }
        }

        if (tIndex > T->len)
        {
            // 找到子串T，将子串T替换为串V
            for (int i = 1; i <= V->len; i++)
            {
                result.ch = (char *)realloc(result.ch, (result.len + 1) * sizeof(char));
                result.ch[result.len + 1] = '\0';
                result.ch[result.len + 1] = V->ch[i];
                result.len++;
            }
            index = index + T->len;
            replaceCount++;
        }
        else
        {
            // 将s中的字符添加到result中
            result.ch = (char *)realloc(result.ch, (result.len + 1) * sizeof(char));
            result.ch[result.len + 1] = '\0';
            result.ch[result.len + 1] = s->ch[index];
            result.len++;
            index++;
        }
    }

    // 释放原始堆串的内存
    free(s->ch);

    // 将result中的结果赋值给s
    s->ch = result.ch;
    s->len = result.len;

    return replaceCount;
}
