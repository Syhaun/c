#include<stdio.h>
int main() 
{
	int PM2_5[1500];
	int count[7] = {0};
	for(int i = 0; i < 1096; i++) 
	scanf("%d",&PM2_5[i]);
	for(int i = 0; i < 1096; i++) {
		if(PM2_5[i]>=0&&PM2_5[i]<35)
		count[1]++;
		else if(PM2_5[i]>=35&&PM2_5[i]<75)
		count[2]++;
		else if(PM2_5[i]>=75&&PM2_5[i]<115)
		count[3]++;
		else if(PM2_5[i]>=115&&PM2_5[i]<150)
		count[4]++;
		else if(PM2_5[i]>=150&&PM2_5[i]<250)
		count[5]++;
		else if(PM2_5[i]>=250)
		count[6]++;
		
	}
	printf("��������Ϊ�ŵ�����Ϊ��%d\n",count[1]);
	printf("��������Ϊ��������Ϊ��%d\n",count[2]);
	printf("��������Ϊ�����Ⱦ������Ϊ��%d\n",count[3]);
	printf("��������Ϊ�ж���Ⱦ������Ϊ��%d\n",count[4]);
	printf("��������Ϊ�ض���Ⱦ������Ϊ��%d\n",count[5]);
	printf("��������Ϊ������Ⱦ������Ϊ��%d\n",count[6]);
	
}
