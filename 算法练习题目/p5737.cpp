#include<stdio.h>
bool is_leapYear(int year)
{
	if(year%4==0&&year%100!=0||year%400==0)
	return true;
	return false;
}
int main() 
{
	int x,y;
	int count;
	int arr[2000];
	scanf("%d %d",&x,&y);
	for(int i = x;i <= y;i++)
	{
		if(is_leapYear(i))
		arr[count++] = i;
	}
	printf("%d\n",count);
	for(int i = 0;i < count;i++)
	printf("%d ",arr[i]); 
	return 0;
}
