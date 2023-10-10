#include<stdio.h>
#include<string.h>
int main()
{
	char ch[10];
	gets(ch);
	int len = strlen(ch);
	int count = 0;
	for(int i = 0;i< len;i++)
	{
		if(ch[i]>='0'&&ch[i]<='9')
		count++;
		else if(ch[i]>='a'&&ch[i]<='z')
		count++;
		else if(ch[i]>='A'&&ch[i]<='Z')
		count++;
	}
	 printf("%d",count);
	 return 0;
 } 
