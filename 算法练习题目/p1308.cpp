#include<stdio.h>
#include<string.h>
int main()
{
    char ch[11];
    char text[1000010];
    text[0]=' ';  //将text第一个位置和最后一个位置设为空格，方便比较
    scanf("%s",ch);
    getchar();
    gets(&text[1]);
    text[strlen(text)]=' ';
    int len=strlen(ch),len2=strlen(text),place,cnt=0,flag=0;
    for (int i=0; i<len; i++)//统一大小写
    {
        if (ch[i]>='A'&&ch[i]<='Z')
            ch[i]+=32;
    }
    for (int i=0; i<len2; i++)
    {
        if (text[i]>='A'&&text[i]<='Z')
            text[i]+=32;
    }
    for (int i=0; i<len2; i++)
    {
        int a=0;
        if (text[i]==' '&&text[i+len+1]==' ')  //找出与给定单词长度一样的单词
        {
            for (int j=0; j<len; j++)
            {
                if (ch[j]==text[j+i+1])  //依次比较每个字母是否相同
                {
                    a++;  //记录相同字母的个数
                }
                else break;  //遇到不相同的字母立即跳出循环继续寻找下一个单词
            }
        }
        if (a==len)  //找到指定的单词
        {
            cnt ++;  //单词出现的次数加1
            if (flag==0){  //判断该单词是不是第一次出现，若是，则place记录其位置
                place=i;
                flag++;
            }
 
        }
    }
    if (cnt==0)
        printf("-1\n");  //指定单词未出现输出-1
    else printf("%d %d\n",cnt,place);
}
