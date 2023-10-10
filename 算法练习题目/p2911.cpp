#include<stdio.h>
int main()
{
	int s1,s2,s3;
	scanf("%d%d%d",&s1,&s2,&s3);
	int d[s1*s2*s3];
	int n=0;
	for(int i=1;i<=s1;i++)
	{
		for(int j=1;j<=s2;j++)
		{
			for(int k=1;k<=s3;k++)
			{
				d[n]=i+j+k;
				n++;
			}
		}
	}
	int result=0;
	int temp=1;
	for(int i=0;i<s1*s2*s3;i++)
	{
		int count=0;
		int num=d[i];
		for(int j=0;j<s1*s2*s3;j++)
		{

			if(d[i]==d[j])
			{
				count++;
			}
		}
		if(count>temp)
		{
			temp=count;
			result=num;
		}
	}
	printf("%d",result);
}
