#include<stdio.h>
#include<string.h>
int main()
{
    char s[1000];
    char p=0;//�ŷ��� 
    int cnt=0; 
    scanf("%s",s);;
    for(int i=0;i<strlen(s);i++)
    {
        if(s[i]>='0'&&s[i]<='9')
		cnt++;//��¼��һ��������
        else    //�������ţ���¼������ 
        {
            p=s[i];
            break;
        } 
    }
    int x=cnt;//���ŵ�λ�ã�����Ƿ�����С����Ҫ�� 
    cnt--;
    while(s[cnt]=='0'&&cnt>0) 
	cnt--;//ȥ������ǰ��0�� 
    for(int i=cnt;i>=0;i--)//�����һ���� 
       printf("%c",s[i]);
       
    if(p==0) return 0;//�޷���return 0 
    
    else
      if(p=='%')
      {
          printf("%c",p);
          return 0;
      } 
      
      else printf("%c",p);//�������� 
      
    int m=strlen(s)-1;    //���һ��Ԫ���±�
    
    while(s[x+1]=='0'&&x<m-1) x++;//ȥ��ĩβ0 
    while(s[m]=='0'&&m>x+1) m--; //ȥ������ǰ��0
    for(int i=m;i>x;i--)//����ڶ����� 
        printf("%c",s[i]);
    return 0; 
}

