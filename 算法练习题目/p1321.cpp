#include<stdio.h>
#include<string.h>
int main()
{
	char ch[256] = {'0'};
	gets(ch);
	int count = 0,cnt = 0;
	for(int i = 0;i < strlen(ch)-2;i++)
	{
		if(ch[i] == 'b' || ch[i+1] == 'o' || ch[i+2] == 'y')
		count++;
	}
	for(int i = 0;i < strlen(ch)-3;i++)
	{
		if(ch[i] == 'g' || ch[i+1] == 'i' || ch[i+2] == 'r' || ch[i+3] == 'l')
		cnt++;
	}
	printf("%d\n%d",count,cnt);
}
