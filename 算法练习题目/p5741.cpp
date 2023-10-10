#include<stdio.h>
#include<math.h>
int N;
typedef struct student
{
	char name[9];
	int a;
	int b;
	int c;
	int sum;
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
	   student[i].sum = student[i].a + student[i].b + student[i].c; 
	 }
	for(int i = 0;i < N-1;i++)
	{
		for(int j = i+1 ;j < N;j++)
		{
			if(abs(student[i].a-student[j].a)<=5&&abs(student[i].b-student[j].b)<=5&&abs(student[i].c-student[j].c)<=5&&abs(student[i].sum-student[j].sum)<=10){
			printf("%s %s\n",student[i].name,student[j].name);
			
			}
		}
	}
	 return 0;
 }
