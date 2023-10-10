#include<stdio.h>
#include<string.h>
	int a[10];
void quick_sort(int left,int right)
{
	int temp = a[(left+right)/2];
	
	if(left>=right)
	return ;
	int i = left;int j = right;
	while(i<j)
	{
		while(a[j]>temp)
		j--;
		while(a[i]<temp)
		i++;
		if(i<=j)
		{
			int temp = a[j];
			a[j] = a[i];
			a[i] = temp;
			j--;i++;
		}
	}
	quick_sort(left,j);
	quick_sort(i,right);
}
char dic[30][20]={"zero","one","two","three","four","five","six","seven","eight","nine","ten","eleven","twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen", "twenty","a","both","another","first","second","third"};
int di[30]={0,1,4,9,16,25,36,49,64,81,00,21,44,69,96,25,56,89,24,61,0,1,2,1,1,4,9};
int main()
{
	char s[100]; 

	int top = 0;
	for(int i = 0; i < 6;i++)
	{
		scanf("%s",&s);
		for(int j = 0;j < 26;j++)
		{
			if(!strcmp(s,dic[j]))
			{
				a[top++] = di[j];
				break;
			}
		}
	 } 
	
	 
	 if(top == 0)
	 {
	 printf("0");
	 return 0;
}
	quick_sort(0,top-1);
	int flag = 1;
	for(int i = 0;i<top;i++)
	{
		if(a[i]==0)
		{
			continue;
		}
		if(a[i]<10&&flag==0)
		printf("%02d",a[i]);
		else
		printf("%d",a[i]);	
		flag=0;
		
	}
	return 0;
}
