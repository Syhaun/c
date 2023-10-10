#include<stdio.h>
int factorial(int num)
{
	
	int result=1;
	if(num>0)result=num*factorial(num-1);
	return result;
}
int main()
{
	int n;
	scanf("%d",&n);
	printf("%d",factorial(n));
	return 0;
}
