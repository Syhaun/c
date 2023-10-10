#include<stdio.h>
int main()
{
	int arr[1000] = {0};
	int n,m;
	scanf("%d%d",&n,&m);
	int ij[2000000];
	for(int i = 0; i < m; i++)
	{
		scanf("%d",&ij[i]);
		arr[ij[i]]++;
	}
	for(int i = 1; i <= n ; i++)
	{
		while(arr[i]-- != 0)
		printf("%d ",i);
	}
	return 0;
}
