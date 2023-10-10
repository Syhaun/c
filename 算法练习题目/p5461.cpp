#include<stdio.h>
#include<math.h>
int n;
int a[1234][1234];
int main()
{
	scanf("%d",&n);
	n = pow(2,n);
	a[0][n+1] = 1;
	for( int i=1;i<=n;++i)
	{
		for( int j=1;j<=n;++j)
		{
			a[i][j] = a[i-1][j] ^ a[i-1][j+1];
			printf("%d ",a[i][j]);
		}
		printf("\n");
	}
	return 0;
}

