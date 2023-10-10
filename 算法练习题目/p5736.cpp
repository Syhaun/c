#include<stdio.h>
#include<math.h>
int a[101],b[101];
int n;
bool is_prime(int num);
int main()
{
	scanf("%d",&n);
	int j=0;       
	for(int i = 0;i < n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(int i = 0;i < n;i++)
	{
		if(is_prime(a[i]))
		{
			b[j] = a[i];
			j++;
		}
	}
	for(int i = 0;i<j;i++)
	printf("%d ",b[i]);
	return 0;
}
bool is_prime(int num)
{
	if(num<2)
	return false;
	for(int i=2;i<=sqrt(num);i++)
	{
		if(num%i==0)
		return false;
	}
	return true;
}
