#include<stdio.h>
#include<malloc.h>
typedef struct data1
{
	int a;
	struct data1 *next;
}LNode1,*LinkList1;
LinkList1 creat1()
{
	LinkList1 H1=(LNode1*)malloc(sizeof(LNode1));
	H1->next=NULL;
	LinkList1 r = H1;
	LinkList1 s = (LNode1 *)malloc(sizeof(LNode1));
	while(1)
	{
		scanf("%d", &(s->a));
		if (s->a == -1)
		{
			free(s);
			break;
		}
		r->next = s;
		r = s;
		s = (LNode1 *)malloc(sizeof(LNode1));
	}
	r->next=NULL;
	return H1;
}
void print1(LinkList1 H1)
{
	LinkList1 p=H1->next;
	while(p)
	{
		printf("%d ",p->a);
		p=p->next;
	}
	printf("\n");
}
void del(LinkList1 H1,LinkList1 H2)
{
	LinkList1 t,p=H1->next,pre=H1;
	LinkList1 q=H2;
	while(p)
	{
		q=H2->next;     //qÿ�δ��׽�㿪ʼ�� 
		while(q)
		{
		  if(p->a==q->a)
	      {
	    	t=p;        //p����Ҫɾ�Ľ�� 
	    	pre->next=p->next;
	    	p=pre;           //��Ϊ�����ж����ظ�Ҫɾ�Ľ�� ����pһֱ������ ��ÿ��ɾ����ɾ��ǰһ����ʼ�� 
	    	free(t);
		  }
		  q=q->next;
	    }
	    pre=p;         //pre ��¼��p��Ҫɾ�Ľ���ǰһ����� Ϊ�´����λ�õĺ�һ����p�ͱ���q���Ƿ�����ȵ��̵� 
	    p=p->next;    //Ѱ��p����һ������Ƿ���Ҫɾȥ 
	}
}
int main()
{
	LinkList1 H1=creat1();
	LinkList1 H2=creat1();
	//print1(H1);
	//print1(H2);
	del(H1,H2);
	print1(H1);
	return 0;
}
