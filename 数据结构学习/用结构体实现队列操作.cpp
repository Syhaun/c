//�ýṹ��ʵ�ֶ��в���
#include<stdio.h>
struct queue
{
	int data[100];//���е����壬�����������
	int head;//����
	int tail;//��β 
}; 
int main()
{
	struct queue q;
	int i;
	int n;
	scanf("%d",&n);
	//��ʼ������
	q.head = 0;
	q.tail = 0;
	for(int i = 0;i < n;i++)
	{
		//����������β���9����
		scanf("%d",&q.data[q.tail]);
		q.tail++; 
	}
	while(q.head<q.tail)//�����в�Ϊ�յ�ʱ��ִ��ѭ��
	{
		//��ӡ���ײ������׳���
		printf("%d\n",q.data[q.head]);
		q.head++;
		//�Ƚ��¶��׵�����ӵ���β
		q.data[q.tail] = q.data[q.head];
		q.tail++;
		//�ٽ����׳���
		q.head++; 
	 } 
		return 0;
 } 
