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
//创建链表(包含了初始化） 
LinkList creat()
{
	LinkList H = (LinkList)malloc(sizeof(LNode));  
	H -> next = NULL;  //创建头结点
	LNode *r = H;
	LinkList s = (LinkList)malloc(sizeof(LNode));

	while(1)
	{
		scanf("%ld%s%s%d",&s->num,s->name,s->sex,&s->age);
		if(s->num==-1)
		{
			free(s);
			break;
		}
		r->next=s;
		r=s;
		s=(LNode*)malloc(sizeof(LNode));
	}
	r->next=NULL;
	return H;
}
void del(LinkList H, int x)
{
	LinkList t, p = H->next, pre = H;
	while (p)
	{
		while (p && p->age != x)
		{
			p = p->next;
			pre = pre->next;
		}
		if (p)
		{
			t = p;
			pre->next = p->next;
			p = p->next; // 保持 p 不变，只更新 pre
			free(t);
		}
	}
}
void print(LinkList H)
{
	LNode* p;
	p = H->next;
	while (p)
	{
		printf(" % ld % s % s % d\n", p->num, p->name, p->sex, p->age);
		p = p->next;
	}
}
int main()
{
	printf("请输入学号、姓名、性别、年龄\n");
	LinkList H = creat();
	print(H);
	printf("请输入要删除的年龄\n");     //按值删除 
	int x;
	scanf("%d", &x);
	del(H,x);
	print(H);
	return 0;
}
