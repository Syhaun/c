#include<stdio.h>
#include<string.h>
int main()
{
    char ch[11];
    char text[1000010];
    text[0]=' ';  //��text��һ��λ�ú����һ��λ����Ϊ�ո񣬷���Ƚ�
    scanf("%s",ch);
    getchar();
    gets(&text[1]);
    text[strlen(text)]=' ';
    int len=strlen(ch),len2=strlen(text),place,cnt=0,flag=0;
    for (int i=0; i<len; i++)//ͳһ��Сд
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
        if (text[i]==' '&&text[i+len+1]==' ')  //�ҳ���������ʳ���һ���ĵ���
        {
            for (int j=0; j<len; j++)
            {
                if (ch[j]==text[j+i+1])  //���αȽ�ÿ����ĸ�Ƿ���ͬ
                {
                    a++;  //��¼��ͬ��ĸ�ĸ���
                }
                else break;  //��������ͬ����ĸ��������ѭ������Ѱ����һ������
            }
        }
        if (a==len)  //�ҵ�ָ���ĵ���
        {
            cnt ++;  //���ʳ��ֵĴ�����1
            if (flag==0){  //�жϸõ����ǲ��ǵ�һ�γ��֣����ǣ���place��¼��λ��
                place=i;
                flag++;
            }
 
        }
    }
    if (cnt==0)
        printf("-1\n");  //ָ������δ�������-1
    else printf("%d %d\n",cnt,place);
}
