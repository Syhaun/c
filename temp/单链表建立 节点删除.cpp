#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
typedef struct student
{
	long num;
	char name[100];
	char sex[100];
	int age;
	struct student* next; 
} LNode, *LinkList;
//��������(�����˳�ʼ���� 
LinkList creat(LinkList H)
{
	H = (LinkList)malloc(sizeof(LNode));  
	H -> next = NULL;  //����ͷ���
	LNode *r = H;
	LinkList s = (LinkList)malloc(sizeof(LNode));
	while(s->num!=-1)
	{
		s=(LNode*)malloc(sizeof(LNode));
		scanf("%ld%s%s%d",&s->num,s->name,s->sex,&s->age);
		r->next=s;
		r=s;
	}
	r->next=NULL;
	return H;
}
void del(LinkList H, int x)
{
	LinkList p,q;          //pָ���i-1��λ�� qָ��i��λ�� 
	p=q=(LNode*)malloc(sizeof(LNode));
	p=H;
	int j=0;
	while(j<x-1&&p)
	{
		p=p->next;
		j++;
	} 
	if(p==NULL||p->next==NULL)
	  printf("��㲻���ڣ�");
	else
	{
		q=p->next;
		p->next=q->next;
		free(q);
	 } 
}
void print(LinkList H)
{
	LNode* p;
	p = H -> next;
	while (p)
	{
		printf(" % ld % s % s % d", p->num, p->name, p->sex, p->age);
		p = p->next;
	}
}
int main()
{
	LinkList Head;
	printf("������ѧ�š��������Ա�����\n");
	LinkList H = creat(Head);
	print(H);
	printf("������Ҫɾ��������\n");
	int x;
	scanf("%d", &x);
	del(H,x);
	print(H);
	return 0;
}
