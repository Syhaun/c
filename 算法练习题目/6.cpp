#include<stdio.h>
#include<math.h>
int main()
{
 int i,n,j,b; 
 scanf("%d",&n);
 int a[n];
 for(i=pow(10,n-1);i<=pow(10,n+1)-1;i++)
 {
 	int sum = 0;
  b=i;
 	int temp = i; 
  	for(j=0;j<n;j++)
 	 {
  	 a[j]=temp%10;
   	temp=temp/10;
   	sum+=pow(a[j],3);
  	}
  	if(b==sum)
  	{
   	printf("%d\n",b);
  	}
 }
 printf("张超");
 return 0;
 }
