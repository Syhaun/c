//用栈，队列的数据结构模拟弥竹竿的纸牌游戏
#include<stdio.h>
struct queue
{
	int datd[1000];
	int head;
	int tail;
 };
 struct stack
 {
 	int data[10];
	 int top;	
 };
 int main()
 {
 	struct queue q1,q2;//用队列来模拟小哼和小哈手上的牌 
 	struct stack s;//用栈来模拟牌堆
	int book[10];//用桶模拟牌堆中的牌 
	//初始化队列
	q1.head = 1;q1.tail = 1;
	q2.head = 1;q2.tail = 1;
	//初始化栈
	s.top = 0;
	//初始化用来标记的数组，用来标记哪些牌以及在桌上
	for(int i = 1;i <= 9;i++)
	{
		book[i] = 0;
	 } 
	 //依次向队列中插入6个数来表示小哼手中的6张牌
	 for(int i = 1;i<=6;i++)
	 {
	 	scanf("%d",&q1.datd[q1.tail]);
	 	q1.tail++;
	 }
	 //依次向队列中插入6个数来表示小哈手中的6张牌
	 for(int i = 1;i<=6;i++)
	 {
	 	scanf("%d",&q2.datd[q2.tail]);
	 	q2.tail++;
	 }
	 while(q1.head<q1.tail&&q2.head<q2.tail)//当队列不为空的时候执行循环
	 {
	 	int t =q1.datd[q1.head];//小哼出一张牌
		 //判断小哼当前打出的牌是否能赢牌
		 if(book[t]==0)//表明桌上没有牌面为t的牌
		 {
		 	//小哼此轮没有赢牌
			q1.head++;//小哼已经打出一张牌，所以要把打出的牌出队
			s.top++;
			s.data[s.top]=t;//再把打出的牌放到桌上，即入栈
			book[t]=1;//标记桌上现在已经又牌面t的牌 
		  } 
		  else
		  {
		  	//小哼此轮可以赢牌
			q1.head ++;//小哼已经打出一张牌，所以要把打出的牌出队
			q1.datd[q1.tail]=t;//紧接着把打出的牌放到手中牌的末尾
			q1.tail++;
			while(s.data[s.top]!=t)//把桌上可以赢的牌依次放到手中牌的末尾
			{
				book[s.data[s.top]]=0;//取消标记
				q1.datd[q1.tail]=s.data[s.top];//依次放入队尾
				q1.tail++;
				s.top--;//栈中少了一张牌，所以栈要减1 
			 } 
		  }
		  t =q2.datd[q2.head];//小哈出一张牌
		 //判断小哈当前打出的牌是否能赢牌
		 if(book[t]==0)//表明桌上没有牌面为t的牌
		 {
		 	//小哈此轮没有赢牌
			q2.head++;//小哈已经打出一张牌，所以要把打出的牌出队
			s.top++;
			s.data[s.top]=t;//再把打出的牌放到桌上，即入栈
			book[t]=1;//标记桌上现在已经又牌面t的牌 
		  } 
		  else
		  {
		  	//小哈此轮可以赢牌
			q2.head ++;//小哈已经打出一张牌，所以要把打出的牌出队
			q2.datd[q2.tail]=t;//紧接着把打出的牌放到手中牌的末尾
			q2.tail++;
			while(s.data[s.top]!=t)//把桌上可以赢的牌依次放到手中牌的末尾
			{
				book[s.data[s.top]]=0;//取消标记
				q2.datd[q2.tail]=s.data[s.top];//依次放入队尾
				q2.tail++;
				s.top--;//栈中少了一张牌，所以栈要减1 
			 } 
		  }
	  } 
	 
	 if(q2.head==q2.tail)
	 {
	 	printf("小哼win\n");
	 	printf("小哼当前手中的牌是");
		 for(int i=q1.head;i<=q1.tail-1;i++)
		 {
		 	printf(" %d",q1.datd[i]);
		  } 
		  if(s.top>0)//如果桌上有牌则依次输出桌上的牌
		  {
		  	printf("\n桌上的牌是");
			  for(int i=1;i<=s.top;i++)
			  {
			  	printf(" %d",s.data[i]);
			   } 
		   } 
		   else
		   {
		   	printf("\n桌子上已近没有牌了");
		   }
	 }
	else
	 {
	 	printf("小哈win\n");
	 	printf("小哈当前手中的牌是");
		 for(int i=q2.head;i<=q2.tail-1;i++)
		 {
		 	printf(" %d",q2.datd[i]);
		  } 
		  if(s.top>0)//如果桌上有牌则依次输出桌上的牌
		  {
		  	printf("\n桌上的牌是");
			  for(int i=1;i<=s.top;i++)
			  {
			  	printf(" %d",s.data[i]);
			   } 
		   } 
		   else
		   {
		   	printf("\n桌子上已近没有牌了");
		   }
	 }
	 return 0;
 }
