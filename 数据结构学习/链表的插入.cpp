#include<stdio.h>
#include<stdlib.h>
//���ﴴ��һ���ṹ������ʾ����Ľ������
struct node
{
	int data;
	struct node *next;
 } ;
 //������������ 
 int main()
 {
 	struct node *head,*p,*q,*t;
 	int n,a;
 	scanf("%d",&n);
 	head = NULL;//ͷָ��Ϊ��
	for(int i = 0;i < n;i++)//ѭ������n����
	{
	 	scanf("%d",&a);
	 	p = (struct node *)malloc(sizeof(struct node));//��̬����һ���ռ䣬�������һ����㣬������ʱָ��pָ��������
		p->data = a;//�����ݴ洢����ǰ����data����
		p->next = NULL;//���õ�ǰ���ĺ��ָ��ָ��գ�Ҳ���ǵ�ǰ������һ�����Ϊ��
		if(head==NULL)
		head = p;//������ǵ�һ�������Ľ�㣬��ͷָ��ָ��������
		else
		q->next = p;//������ǵ�һ�������Ľ�㣬����һ�����ĺ��ָ��ָ��ǰ���
		q = p;//ָ��qҲָ��ǰ��� 
	} 
	scanf("%d",&a);//������������
	t=head;//������ͷ����ʼ����
	while(t!=NULL)//��û�е�������β����ʱ��ѭ��
	{
		if(t->next->data>a)//�����ǰ�����һ������ֵ���ڴ�����������������뵽�м�
		{
			p = (struct node *)malloc(sizeof(struct node));//��̬����һ���ռ䣬��������������
			p->data = a;
			p->next = t->next;//�������ĺ��ָ��ָ��ǰ���ĺ��ָ����ָ��Ľ��
			t->next = p;//��ǰ���ĺ��ָ��ָ���������
			break;//����ѭ����� 
		 } 
		 t = t -> next;//������һ����� 
	 } 
	 //��������е�������
	 t = head;
	 while(t!=NULL)
	 {
	 	printf("%d ",t->data);
	 	t = t->next;//������һ����� 
	  } 
	return 0;	
 }
