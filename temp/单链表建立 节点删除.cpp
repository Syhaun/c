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
//��������(�����˳�ʼ���� 
student* creat()
{
	printf("�����룺\n");
	student  *head = (student*)malloc(sizeof(student));  
	head -> next = NULL;
	student *s = (student*)malloc(sizeof(student));
	student *r = head;    //*s �´����Ľ�� 
	scanf("%ld%s%s%d", &s->num, s->name, s->sex, &s->age);
	while (s->num != 0)   //�Ľ��� 
	{
		s = (student*)malloc(sizeof(student));   
		r->next = s;      //ԭ���Ľ��ָ���½�� 
		r = s;		
		scanf("%ld%s%s%s", &s->num, s->name, &s->sex, &s->age);
	}
	s->next = NULL;
	return head;
}
student* search(student* head, int x)
{
	student* p;     //ѭ�����õ���ʱָ��
	p = head;
	while (p != NULL) //�ж�ͷָ��ָ��������н�㣬����Ϊ��
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
	if (head == NULL)      //������
	{
		printf("null\n");
		return NULL;
	}
	s = head;        //s�����ҵ�Ҫɾ���Ľ�� ���׽�㿪ʼ
	while (s->age != x && s->next != NULL) //
	{
		s = s->next;       //������
		r=s;             //��¼��ǰ����λ��
	}
	if (s->age == x)       
	{
		if (s == head)    //�׽��
			head = s->next;  //ɾ���˽�� ͷָ������� �ͷŴ˿ռ�
		else r->next = s->next;  //rҲ����������
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
