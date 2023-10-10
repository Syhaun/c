#include<math.h>
#include<stdio.h>
int N;
bool is_prime(int n)
{
	if(n<2)
	return false;
	for(int i = 2;i <= sqrt(n);i++)
	{
		if(n%i==0)
		return false;
	}
	return true;
}
int main()
{
	scanf("%d",&N);
	for(int i = 4;i <= N;i+=2)
	{
		int flag = 0;
		int a = 2,b = i-a;
		while(a<i/2)
		{
			if(is_prime(a)&&is_prime(b))
			break;
			a++;
			b = i-a;
		}
		printf("%d=%d+%d\n",i,a,b);
	}
 } 
