#include<stdio.h>
#include<malloc.h>
typedef struct node
{
	int x;
	struct node* next;
}l,*LinkList;
LinkList creat()
{
	LinkList H=(l*)malloc(sizeof(l));
	H->next=NULL;
	LinkList r=H,s;
	int x;
	scanf("%d",&x);
	while(x!=-1)
	{
		s=(l*)malloc(sizeof(l));
		s->x=x;
		r->next =s;
		r=s;
		scanf("%d",&x);
	}
	r->next =NULL;
	return H;
}
void del(LinkList H)
{
	LinkList p,q,t;
	p=H->next ;
	q=p->next ;
	while(p)
	{
	   if(p->x==q->x)
	   {
	   	  p->next =q->next ;  //ɾ���ڶ����ظ��Ľ�� q 
	   	  t=q;
	   	  free(t);
	   	  q=p->next ;  //���ܻ��ж���ظ���,p����,q����� 
	   }
	   else 
	   {
	      p=p->next ;
	      q=q->next ;
	   }
	}
}
void print(LinkList H)
{
	LinkList p=H->next ;
	while(p)
	{
		printf("%d ",p->x);
		p=p->next ;
	}
}
 int main()
{
 	LinkList H=creat();
 	del(H);
 	print(H);
 	return 0;
}
