//快排基于二分思想
//优点：既不浪费空间，排序速度又很快
#include<stdio.h>
#include<stdlib.h>
int *a=(int*)malloc(100*sizeof(int));
int n;

void quicksort(int left,int right)
{
	int temp=a[left];//temp中存的是基准数 
	if(left>right)
	{
		return ; 
	}
	
	int i=left,j=right;
	while(i!=j)
	{
		//顺序必须从右往左找
		while(a[j]>=temp&&i<j)
		{
			j--;
		}//从右边往左找 
		while(a[i]<=temp&&i<j)
		{
			i++;
		}//从左边往右找 
	//交换两个数再数组中的位置
		if(i<j)
		{
			int temp=a[i];
			a[i]=a[j];
			a[j]=temp;
	 	} 
	}
	//在将基准数归位
	a[left]=a[i];
	a[i]=temp; 
	quicksort(left,i-1);//继续处理左边的,这里是一个递归的过程 
	quicksort(i+1,right);// 继续处理右边的，这里也是一个递归的过程 
}
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	quicksort(0,n-1);
	for(int i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
	return 0;
 }












