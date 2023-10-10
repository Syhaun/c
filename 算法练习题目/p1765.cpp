#include<string.h>
#include<stdio.h>
int main()
{

	char ch [200];
	gets(ch);
	int arr[27] = {1,2,3,1,2,3,1,2,3,1,2,3,1,2,3,1,2,3,4,1,2,3,1,2,3,4};
	 int len = strlen(ch),sum  =0;
	 for(int i = 0;i< len;i++)
	 {
	 	 sum+=arr[ch[i]-97];
	 	 if(ch[i]==' ')
	 	 sum++;
	  } 
	  printf("%d",sum);	
	  return 0;
}
