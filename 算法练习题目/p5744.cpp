#include<stdio.h>
struct Student
{
	char name[20];
	int age;
	int score;
};
int main()
{
	int n;
	scanf("%d",&n);
	struct Student student[6];
	for(int i = 0; i < n;i++)
	{
		scanf("%s%d%d",&student[i].name,&student[i].age,&student[i].score);
		printf("%s %d ",student[i].name,student[i].age+1);
		if((int)(student[i].score*1.2)>600)
		printf("600\n");
		else
		printf("%d\n",(int)(student[i].score*1.2));
	}
	return 0;
}
