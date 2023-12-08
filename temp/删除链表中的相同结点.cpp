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
	LinkList p, q, t;
	p = H->next;
	while (p)
	{
		q = p->next; // 将 q 指针放在 p 的下一个节点

		while (q && p->x == q->x)
		{
			p->next = q->next;
			t = q;
			free(t);
			q = p->next;
		}

		p = q; // 更新 p 指针的位置
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
	print(H);
	printf("\n");
	del(H);
 	print(H);
 	return 0;
}
