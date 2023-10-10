#include<stdio.h>

typedef struct student 
{
	int num;
	int score;
	int extend;
	double s;
}student;
bool judge(student st)
{
	if(st.score+st.extend>140&&st.score*7+st.extend*3>=800)
	return true;
	return false;
}
int main()
{
	int n;
	scanf("%d",&n);
	student st[n];
	for(int i = 0;i < n;i++)
	{
		scanf("%d%d%d",&st[i].num,&st[i].score,&st[i].extend);
		st[i].s = (double)(st[i].score*0.7+st[i].extend*(0.3));
	}
	for(int i = 0;i<n;i++)
	{
		if(judge(st[i]))
		printf("Excellent\n");
		else
		printf("Not excellent\n"); 
	}
}
