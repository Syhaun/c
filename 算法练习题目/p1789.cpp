#include<stdio.h>
#include<stdlib.h>
int main()
{
	int n,m,k,x,y,ans=0;
	int a[105][105]={0};
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&x,&y);
		x+=3;y+=3;
		for(int j=x-1;j<=x+1;j++)
		{
			for(int k=y-1;k<=y+1;k++)
			{
				a[j][k]=1;
				a[x-2][y]=1,a[x+2][y]=1,a[x][y-2]=1,a[x][y+2]=1;
			}
		}
	}
	for(int i=1;i<=k;i++)
	{
		scanf("%d%d",&x,&y);
		x+=3;y+=3;
		for(int j=x-2;j<=x+2;j++)
		{
			for(int k=y-2;k<=y+2;k++)
			{
				a[j][k]=1;
			}
		}
	}
	for(int i=4;i<=n+3;i++)
	{
		for(int j=4;j<=n+3;j++)
		{
			ans+=a[i][j]==0;
		}
	}
	printf("%d",ans);
	return 0;
}
