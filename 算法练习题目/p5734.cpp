#include<stdio.h>
#include<string.h>
#define N 105
char s[N],s1[N];
int main()
{
	int n;
	scanf("%d\n%s",&n,s);
	for(int i=0;i<n;i++)
	{
		int t;
		scanf("%d",&t);
	
		if(t==1)
		{
			scanf("%s",s1);
			strcat(s,s1);
			printf("%s\n",s);
		}
		else if(t==2)
		{
			int a,b;
			scanf("%d%d",&a,&b);
			s[a+b]='\0';
			strcpy(s1,&s[a]);
			strcpy(s,s1);
			printf("%s\n",s); 
		}
		else if(t==3)
		{
			int a;
			scanf("%d%s",&a,s1);
			strcat(s1,&s[a]);
			s[a]='\0';
			strcat(s,s1);
			printf("%s\n",s);
		}
		else
		{
			scanf("%s",s1);
			char *ans=strstr(s,s1);
			if(ans!=NULL)
	        {
			printf("%d\n",int(ans-s));
			}
			else
			{
				printf("%d\n",-1);
		    } 
     	}
     }
	return 0;
}

