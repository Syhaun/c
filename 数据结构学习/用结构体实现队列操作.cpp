//用结构体实现队列操作
#include<stdio.h>
struct queue
{
	int data[100];//队列的主体，用来存放内容
	int head;//队首
	int tail;//队尾 
}; 
int main()
{
	struct queue q;
	int i;
	int n;
	scanf("%d",&n);
	//初始化队列
	q.head = 0;
	q.tail = 0;
	for(int i = 0;i < n;i++)
	{
		//向队列中依次插入9个数
		scanf("%d",&q.data[q.tail]);
		q.tail++; 
	}
	while(q.head<q.tail)//当队列不为空的时候执行循环
	{
		//打印队首并将队首出队
		printf("%d\n",q.data[q.head]);
		q.head++;
		//先将新队首的数添加到队尾
		q.data[q.tail] = q.data[q.head];
		q.tail++;
		//再将队首出队
		q.head++; 
	 } 
		return 0;
 } 
