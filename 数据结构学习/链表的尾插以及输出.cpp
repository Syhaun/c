#include<stdio.h>
#include<stdlib.h>
//这里创建一个结构体来表示链表的结点类型
struct node
{
	int data;
	struct node *next;
 } ;
 //链表的输入输出 
 int main()
 {
 	struct node *head,*p,*q,*t;
 	int n,a;
 	scanf("%d",&n);
 	head = NULL;//头指针为空
	for(int i = 0;i < n;i++)//循环读入n个数
	{
	 	scanf("%d",&a);
	 	p = (struct node *)malloc(sizeof(struct node));//动态申请一个空间，用来存放一个结点，用用临时指针p指向这个结点
		p->data = a;//将数据存储到当前结点的data域中
		p->next = NULL;//设置当前结点的后继指针指向空，也就是当前结点的下一个结点为空
		if(head==NULL)
		head = p;//如果这是第一个创建的结点，则头指针指向这个结点
		else
		q->next = p;//如果不是第一个创建的结点，则将上一个结点的后继指针指向当前结点
		q = p;//指针q也指向当前结点 
	} 
	  //输出链表的所有数
	  t=head;
	  while(t != NULL)
	  {
		  printf("%d ",t->data);
	  	t = t->next;//继续下一个结点 
 	  }
	return 0;	
 }
