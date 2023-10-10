#include<stdio.h>
int n;int sum = 1;
int num(int n)
{
if(n==1)
	return 1;
	int y = (num(n-1)+1)*2;
	return y;
	
}
int main()
{
	scanf("%d",&n);
	int result = num(n);
	printf("%d",result);
}
