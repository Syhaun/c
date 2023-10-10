#include<stdio.h>
int main() {
	double PM2_5[1500];
	int n;
	scanf("%d",&n);
	int count[7] ;
	for(int i = 0; i < n; i++) {
		if(PM2_5[i]>=0&&PM2_5[i]<35) 
		count[1]++;
		if(PM2_5[i]>=35&&PM2_5[i]<75) 
		count[2]++;
		if(PM2_5[i]>=75&&PM2_5[i]<115) 
		count[3]++;
		if(PM2_5[i]>=115&&PM2_5[i]<150) 
		count[4]++;
		if(PM2_5[i]>=150&&PM2_5[i]<250) 
		count[5]++;
		if(PM2_5[i]>=250) 
		count[6]++;
	}
	printf("空气质量为优的天数为：%d",count[1]);
	printf("空气质量为良的天数为：%d",count[2]);
	printf("空气质量为轻度污染的天数为：%d",count[3]);
	printf("空气质量为中度污染的天数为：%d",count[4]);
	printf("空气质量为重度污染的天数为：%d",count[5]);
	printf("空气质量为严重污染的天数为：%d",count[6]);
}
