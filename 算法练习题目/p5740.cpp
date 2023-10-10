#include<stdio.h>
int N;
typedef struct student
{
	char name[9];
	int a;
	int b;
	int c;
 } Student;
 int main()
 {
 	scanf("%d",&N);
 	Student student[1001];
 	int result = 0;
 	int tmp=0;
 	for(int i = 0;i < N;i++)
 	{
 		scanf("%s%d%d%d",&student[i].name,&student[i].a,&student[i].b,&student[i].c);
	    int sum = student[i].a + student[i].b + student[i].c;
	    if(sum>result)
	    {
	    	int temp = sum;
	    	sum = result;
	    	result = temp;
	    	tmp = i;
		}
	 }
	 printf("%s %d %d %d",student[tmp].name,student[tmp].a,student[tmp].b,student[tmp].c);
	 return 0;
 }
