#include<stdio.h>
int arr[100010]={0};
int N;
void quick_sort(int left,int right)
{
	int temp = arr[(left+right)/2];
	if(left>=right)
	{
		return ;
	}
	
	int i = left;
	int j = right;
	while(i<j)
	{
		while(arr[j]>temp)
		{
			j--;
		}
		while(arr[i]<temp)
		{
			i++;
		}
		if(i<=j)
		{
			int temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
			i++,j--;
		}
	}
	
	quick_sort(left,j);

	quick_sort(i,right);
}
int main()
{
	scanf("%d",&N);
	for(int i = 0;i<N;i++)
	{
		scanf("%d",&arr[i]);
	 } 
	 quick_sort(0,N-1);
	 for(int i = 0;i < N; i++)
	 {
	 	printf("%d ",arr[i]);
	 }
	 return 0;
 } 
