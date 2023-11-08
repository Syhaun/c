#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
typedef struct student
{
	long num;
	char name[20];
	char sex[2];
	int age;
	struct student* next; 
}student, * Student;
//创建链表(包含了初始化） 
student* creat()
{
	printf("请输入：\n");
	student  *head = (student*)malloc(sizeof(student));  
	head -> next = NULL;
	student *s = (student*)malloc(sizeof(student));
	student *r = head;    //*s 新创建的结点 
	scanf("%ld%s%s%d", &s->num, s->name, s->sex, &s->age);
	while (s->num != 0)   //改进？ 
	{
		s = (student*)malloc(sizeof(student));   
		r->next = s;      //原来的结点指向新结点 
		r = s;		
		scanf("%ld%s%s%s", &s->num, s->name, &s->sex, &s->age);
	}
	s->next = NULL;
	return head;
}
student* search(student* head, int x)
{
	student* p;     //循环所用的临时指针
	p = head;
	while (p != NULL) //判断头指针指向的链表有结点，否则为空
	{
		if (p->age == x)
			return p;
		p = p->next;
	}
	return NULL;
}
student* del(student* head, int x)
{
	student* s,* r;
	if (head == NULL)      //空链表
	{
		printf("null\n");
		return NULL;
	}
	s = head;        //s用来找到要删除的结点 从首结点开始
	while (s->age != x && s->next != NULL) //
	{
		s = s->next;       //向后遍历
		r=s;             //记录当前结点的位置
	}
	if (s->age == x)       
	{
		if (s == head)    //首结点
			head = s->next;  //删除此结点 头指针向后移 释放此空间
		else r->next = s->next;  //r也跟着往后移
		free(s);
	}
	else printf("no find\n");
	return head;
}
void print(student* head)
{
	student* p;
	p = head;
	while (p != NULL)
	{
		printf(" % ld % s % s % d", p->num, p->name, p->sex, p->age);
		p = p->next;
	}
}
int main()
{
	student* head;
	head = creat();
	student * temp = head -> next;
	print(head);
	int x;
	scanf("%d", &x);
	do
	{
		temp = del(temp, x);
	} while (search(temp, x) != NULL);
	print(temp);
	return 0;
}
