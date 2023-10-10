#include<stdio.h>
#include<string.h>
int main()
{
	char a[7];
	char b[7];
	gets(a);gets(b);
	int result1=1;int result2 = 1; 
	for(int i = 0;i < strlen(a);i++)
	{
		result1*=(a[i]-64);
	}
	for(int i = 0;i < strlen(b);i++)
	{
		result2*=(b[i]-64);
	} 
	if(result1%47==result2%47)
	printf("GO");
	else
	printf("STAY");
	return 0;
 } 
