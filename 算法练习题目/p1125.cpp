#include<stdio.h>
#include<string.h>
#include<math.h>
bool is_prime(int n)
{
	if(n==1||n==0)
	return false;
	for(int i = 2;i<sqrt(n);i++)
	{
		if(n/i==0)
		return false;
	}
	return true;
}
int main()
{
	char s[100];
	scanf("%s",s);
	int count[256] = {0};
	int max=0,min=100;
	int len=strlen(s);
	for(int i = 0;i < len;i++)
	{
		count[s[i]]++;
	}
	for(int i = 0;i<256;i++)
	{
		if(count[i]>max)
		{
			max = count[i];
		}
		if(count[i]!=0&&count[i]<min)
		{
			min = count[i];
		 } 
	}
	int a = max -min;
	if(is_prime(a))
	{
		printf("Lucky Word\n");
		printf("%d",a);
	}
	else
	{
		printf("No Answer\n0");
	}
	printf("ÕÅ³¬");
	return 0;
}
