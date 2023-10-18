#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct 
{
    /* data */
    char *ch;
    int len;
}HString;

void HStrInit(HString *s) // ��ʼ���Ѵ�
{
    s->ch = NULL;
    s->len = 0;
}
int HStrAssign(HString *s, char *chars) // �Ѵ���ֵ
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

/* ����������д�� */
int HStrReplace(HString *s, HString *T, HString *V)
{
    if (s->len == 0 || T->len == 0)
    {
        return 0; // ��Ч����
    }
    int index = 1;        // ��s�ĵ�һ���ַ���ʼ�����Ӵ�T
    int replaceCount = 0; // ��¼�滻�Ĵ���

    // ����һ����ʱ�Ѵ������ڱ����滻��Ľ��
    HString result;
    HStrInit(&result);

    while (index <= s->len)
    {
        // ��s�в����Ӵ�T��λ��
        int position = index;
        int tIndex = 1; // ����ƥ��T������
        while (tIndex <= T->len && position <= s->len)
        {
            if (s->ch[position] == T->ch[tIndex])
            {
                tIndex++;
                position++;
            }
            else
            {
                break; // ��ƥ��
            }
        }

        if (tIndex > T->len)
        {
            // �ҵ��Ӵ�T�����Ӵ�T�滻Ϊ��V
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
            // ��s�е��ַ���ӵ�result��
            result.ch = (char *)realloc(result.ch, (result.len + 1) * sizeof(char));
            result.ch[result.len + 1] = '\0';
            result.ch[result.len + 1] = s->ch[index];
            result.len++;
            index++;
        }
    }

    // �ͷ�ԭʼ�Ѵ����ڴ�
    free(s->ch);

    // ��result�еĽ����ֵ��s
    s->ch = result.ch;
    s->len = result.len;

    return replaceCount;
}
