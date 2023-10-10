/*优点： 快
缺点：十分浪费空间，无法解决有小数的排序*/ 
#include<stdio.h>
int main()
{
	int book[1001];
	for(int i=0;i<1001;i++)
	{
		book[i]=0;
	}//或者   int book[1001] = {0};
	int n;
	scanf("%d",&n);//表示有多少个数排序
	for(int i = 0 ;i < n; i++)
	{
		int t;
		scanf("%d",&t);//把每一个变量读入t中
		book[t]++;//进行计数，对编号为t的桶放如一个小旗子 
	 } 
	 for(int i = 1000;i >=0 ;i--)
	 {
	 	for(int j=1;j<=book[i];j++)
	 	{
	 		printf("%d\n",i);
		 }
	 }
	 return 0;
}
