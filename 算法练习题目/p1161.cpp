#include<stdio.h>
int main()
{
	int n,t;
	double a;
	int ans=0;
	scanf("%d",&n);
	while(n--)
	{
		scanf("%lf%d",&a,&t);
		for(int i=1;i<=t;i++)
		{
			int x=(int)(a*i);
			ans^=x;
		}
	}
	printf("%d",ans);
	return 0;
}
