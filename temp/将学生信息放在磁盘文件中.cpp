#include<stdio.h>
struct student
{
	int id;
	char name[20];
    float scores[3];
    float average;
}; 
int main()
{
	int i;
	struct student stu[10];
	for(i=0;i<5;i++)
	{
		if(scanf("%d%s%f%f%f",&stu[i].id,stu[i].name,&stu[i].scores[0],&stu[i].scores[1],&stu[i].scores[2])!=5)
	    {
	       printf("�������\n");
	        return 1;}
	    stu[i].average=(stu[i].scores[0]+stu[i].scores[1]+stu[i].scores[2])/3.0;
	}
	FILE *f1 = fopen("D:/�����ļ��м�/c����/temp/����/stu.txt", "w");
	if(f1==NULL)
	{
		printf("error");
		return 1;
	}
	for(i=0;i<5;i++)
	{
		if(fprintf(f1,"%d %s %.1f %.1f %.1f %.1lf\n",stu[i].id,stu[i].name,stu[i].scores[0],stu[i].scores[1],stu[i].scores[2],stu[i].average)<0)
            {
            	printf("error\n");
            	fclose(f1);
            	return 1;
				}	
	}
	int j;
	for(i=0;i<4;i++)       //��ƽ�������� ��������һ���ļ��� 
	{
		for(j=0;j<4-i;j++)
		{
			if (stu[j].average < stu[j + 1].average)
			{
				// ���������ṹ
				struct student temp = stu[j];
				stu[j] = stu[j + 1];
				stu[j + 1] = temp;
			}
		}
	}
	FILE *f2 = fopen("D:/�����ļ��м�/c����/temp/����/sort.txt", "w");
	if(f2==NULL)
	{
		printf("error");
		return 1;
	}
	for(i=0;i<5;i++)
	fprintf(f2,"%d %s %.1f %.1f %.1f %.1lf\n",stu[i].id,stu[i].name,stu[i].scores[0],stu[i].scores[1],stu[i].scores[2],stu[i].average);
	FILE *f3 = fopen("D:/�����ļ��м�/c����/temp/����/add.txt", "w");
	if(f3==NULL)
	{
		printf("error");
		return 1; 
	}
	scanf("%d %s %.1f %.1f %.1f",&stu[5].id,stu[5].name,&stu[5].scores[0],&stu[5].scores[1],&stu[5].scores[2]);
	stu[5].average=(stu[5].scores[0]+stu[5].scores[1]+stu[5].scores[2])/3.0;
	fprintf(f3,"%d %s %.1f %.1f %.1f %.1lf\n",stu[5].id,stu[5].name,stu[5].scores[0],stu[5].scores[1],stu[5].scores[2],stu[5].average);
	for(i=0;i<5;i++)       //��ƽ�������� ��������һ���ļ��� 
	{
		for(j=0;j<5-i;j++)
		{
			if (stu[j].average < stu[j + 1].average)
			{
				// ���������ṹ
				struct student temp = stu[j];
				stu[j] = stu[j + 1];
				stu[j + 1] = temp;
			}
		}
	}
	for(i=0;i<6;i++)
	fprintf(f3,"%d %s %.1f %.1f %.1f %.1lf\n",stu[i].id,stu[i].name,stu[i].scores[0],stu[i].scores[1],stu[i].scores[2],stu[i].average);
	fclose(f1);
	fclose(f2);
	fclose(f3);
	return 0;
}
