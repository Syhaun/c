#include<stdio.h>
int main()
{
	int n;
	scanf("%d",&n);
	char a[101]={0};
    scanf("%s",a);

	int cnt=0;
	for(int i=0;i<n;i++)
	{
		if(a[i]=='V'&&a[i+1]=='K'){
			cnt++;
			a[i]='M'; 
			a[i+1]='M';
		}
		
	}
	for(int i=0;i<n;i++)
	{
		if(a[i]!='M'&&a[i]==a[i+1])
		{
			cnt++;
			break;
		}
	}
	printf("%d",cnt);
	return 0;
}
