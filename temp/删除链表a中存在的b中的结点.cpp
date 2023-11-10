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
		q=H2->next;     //q每次从首结点开始找 
		while(q)
		{
		  if(p->a==q->a)
	      {
	    	t=p;        //p就是要删的结点 
	    	pre->next=p->next;
	    	p=pre;           //因为可能有多组重复要删的结点 所以p一直往后走 而每次删完后从删的前一个开始走 
	    	free(t);
		  }
		  q=q->next;
	    }
	    pre=p;         //pre 记录在p中要删的结点的前一个结点 为下次这个位置的后一个的p和遍历q中是否有相等的铺垫 
	    p=p->next;    //寻找p的下一个结点是否需要删去 
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
