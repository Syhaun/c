/*�ŵ㣺 ��
ȱ�㣺ʮ���˷ѿռ䣬�޷������С��������*/ 
#include<stdio.h>
int main()
{
	int book[1001];
	for(int i=0;i<1001;i++)
	{
		book[i]=0;
	}//����   int book[1001] = {0};
	int n;
	scanf("%d",&n);//��ʾ�ж��ٸ�������
	for(int i = 0 ;i < n; i++)
	{
		int t;
		scanf("%d",&t);//��ÿһ����������t��
		book[t]++;//���м������Ա��Ϊt��Ͱ����һ��С���� 
	 } 
	 for(int i = 1000;i >=0 ;i--)
	 {
	 	for(int j=1;j<=book[i];j++)
	 	{
	 		printf("%d\n",i);
		 }
	 }
	 return 0;
}
