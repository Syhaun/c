#include<stdio.h>
#include<string.h>
int main()
{
	int book[27]={0};
	char a[4][101],b[101],c[101],d[101];

	for(int i = 0;i<4;i++)
	{
		gets(a[i]);
		for(int j = 0;j<strlen(a[i]);j++)
		{
			book[a[i][j]-'A']++;
		}
	}
	int max = 0;
	for(int i = 0;i<26;i++)
	{
		if(max<book[i])
		max = book[i];
	}
	for(int j=max;j>=1;j--)
	{
		for(int i = 0;i<26;i++)
		{
			if(book[i]>=j)
			printf("* ");
			else
			printf("  ");
		}
		printf("\n");
	}
	for(int i = 0;i<26;i++)
	{
		printf("%c ",'A'+i);
	}
	return 0;

 } 
