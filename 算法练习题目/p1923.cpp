#include<stdio.h>
void quick_sort(int *arr,int left,int right)
{
	int temp = arr[(left + right) / 2];
	if(left >= right)
	return ;
	int i = left;
	int j = right;
	while(i < j)
	{
		while(arr[i] < temp)
		i++;
		while(arr[j] > temp)
		j--;
		if(i <= j)
		{
			int temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
			i++;
			j--;
		}
	}
	quick_sort(arr,i,right);
	quick_sort(arr,left,j);
}	
int arr[5000000] = {0};
int main()
{
	int n,k;

	scanf("%d%d",&n,&k);

	for(int i = 0; i < n; i++)
	{
		scanf("%d",&arr[i]);
	}
	quick_sort(arr,0,n-1);
	printf("%d",arr[k]);
	return 0;
 } 
