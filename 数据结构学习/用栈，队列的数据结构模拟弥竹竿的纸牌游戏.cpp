//��ջ�����е����ݽṹģ������͵�ֽ����Ϸ
#include<stdio.h>
struct queue
{
	int datd[1000];
	int head;
	int tail;
 };
 struct stack
 {
 	int data[10];
	 int top;	
 };
 int main()
 {
 	struct queue q1,q2;//�ö�����ģ��С�ߺ�С�����ϵ��� 
 	struct stack s;//��ջ��ģ���ƶ�
	int book[10];//��Ͱģ���ƶ��е��� 
	//��ʼ������
	q1.head = 1;q1.tail = 1;
	q2.head = 1;q2.tail = 1;
	//��ʼ��ջ
	s.top = 0;
	//��ʼ��������ǵ����飬���������Щ���Լ�������
	for(int i = 1;i <= 9;i++)
	{
		book[i] = 0;
	 } 
	 //����������в���6��������ʾС�����е�6����
	 for(int i = 1;i<=6;i++)
	 {
	 	scanf("%d",&q1.datd[q1.tail]);
	 	q1.tail++;
	 }
	 //����������в���6��������ʾС�����е�6����
	 for(int i = 1;i<=6;i++)
	 {
	 	scanf("%d",&q2.datd[q2.tail]);
	 	q2.tail++;
	 }
	 while(q1.head<q1.tail&&q2.head<q2.tail)//�����в�Ϊ�յ�ʱ��ִ��ѭ��
	 {
	 	int t =q1.datd[q1.head];//С�߳�һ����
		 //�ж�С�ߵ�ǰ��������Ƿ���Ӯ��
		 if(book[t]==0)//��������û������Ϊt����
		 {
		 	//С�ߴ���û��Ӯ��
			q1.head++;//С���Ѿ����һ���ƣ�����Ҫ�Ѵ�����Ƴ���
			s.top++;
			s.data[s.top]=t;//�ٰѴ�����Ʒŵ����ϣ�����ջ
			book[t]=1;//������������Ѿ�������t���� 
		  } 
		  else
		  {
		  	//С�ߴ��ֿ���Ӯ��
			q1.head ++;//С���Ѿ����һ���ƣ�����Ҫ�Ѵ�����Ƴ���
			q1.datd[q1.tail]=t;//�����ŰѴ�����Ʒŵ������Ƶ�ĩβ
			q1.tail++;
			while(s.data[s.top]!=t)//�����Ͽ���Ӯ�������ηŵ������Ƶ�ĩβ
			{
				book[s.data[s.top]]=0;//ȡ�����
				q1.datd[q1.tail]=s.data[s.top];//���η����β
				q1.tail++;
				s.top--;//ջ������һ���ƣ�����ջҪ��1 
			 } 
		  }
		  t =q2.datd[q2.head];//С����һ����
		 //�ж�С����ǰ��������Ƿ���Ӯ��
		 if(book[t]==0)//��������û������Ϊt����
		 {
		 	//С������û��Ӯ��
			q2.head++;//С���Ѿ����һ���ƣ�����Ҫ�Ѵ�����Ƴ���
			s.top++;
			s.data[s.top]=t;//�ٰѴ�����Ʒŵ����ϣ�����ջ
			book[t]=1;//������������Ѿ�������t���� 
		  } 
		  else
		  {
		  	//С�����ֿ���Ӯ��
			q2.head ++;//С���Ѿ����һ���ƣ�����Ҫ�Ѵ�����Ƴ���
			q2.datd[q2.tail]=t;//�����ŰѴ�����Ʒŵ������Ƶ�ĩβ
			q2.tail++;
			while(s.data[s.top]!=t)//�����Ͽ���Ӯ�������ηŵ������Ƶ�ĩβ
			{
				book[s.data[s.top]]=0;//ȡ�����
				q2.datd[q2.tail]=s.data[s.top];//���η����β
				q2.tail++;
				s.top--;//ջ������һ���ƣ�����ջҪ��1 
			 } 
		  }
	  } 
	 
	 if(q2.head==q2.tail)
	 {
	 	printf("С��win\n");
	 	printf("С�ߵ�ǰ���е�����");
		 for(int i=q1.head;i<=q1.tail-1;i++)
		 {
		 	printf(" %d",q1.datd[i]);
		  } 
		  if(s.top>0)//�����������������������ϵ���
		  {
		  	printf("\n���ϵ�����");
			  for(int i=1;i<=s.top;i++)
			  {
			  	printf(" %d",s.data[i]);
			   } 
		   } 
		   else
		   {
		   	printf("\n�������ѽ�û������");
		   }
	 }
	else
	 {
	 	printf("С��win\n");
	 	printf("С����ǰ���е�����");
		 for(int i=q2.head;i<=q2.tail-1;i++)
		 {
		 	printf(" %d",q2.datd[i]);
		  } 
		  if(s.top>0)//�����������������������ϵ���
		  {
		  	printf("\n���ϵ�����");
			  for(int i=1;i<=s.top;i++)
			  {
			  	printf(" %d",s.data[i]);
			   } 
		   } 
		   else
		   {
		   	printf("\n�������ѽ�û������");
		   }
	 }
	 return 0;
 }
