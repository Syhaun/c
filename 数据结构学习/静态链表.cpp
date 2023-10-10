//线性表的静态链表存储结构
#define MAXSIZE 1000//假设链表的最大长度是1000
typedef struct
{
	ElemType data;
	int cur;//游标（Cursor），为0时表示无指向 
 } Component,StaticLinkList[MAXSIZE];
 
 //初始化数组状态
 //将一维数组space中各分量链成一备用链表
 //space[0].cur为头指针，"0"表示空指针
 Status InitList(StaticLinkList space)
 {
 	int i;
 	for(i=0;i<MAXSIZE-1;i++)
 	space[i].cur=i+1;
 	space[MAXSIZE-1].cur=0//目前静态链表为空，最后一个元素的cur为0
	 return 0; 
  } 
  
  //相当于malloc函数 
  //若备用空间链表为非空，则返回分配的结点下标，否则返回0
  int Malloc_SLL(StaticLinkList space)
  {
  	int i=space[0].cur//当前数组的第一个元素的cur存的值
	  //就是要返回的第一个备用空闲的下标
	  if(space[0]cur)
	  space[0]cur=space[i].cur//由于要拿出一个分量来使用，所有我们就得把它的下一个分量用来做备用
	  return i; 
   } 
   //插入元素
   //在L中的第i个元素之前插入新的元素e
   Status ListInsert(StaticLinkList L,int i,ElemType e)
   {
   	int j,k,l;
   	k=MAX_SIZE-1;//注意k首先是最后一个元素的下标
	   if(i<1||i>ListLength(L)+1)
	   return ERROR;
	   j=Malloc_SSL(L);//获得空闲分量的下标
	   if(j)
	   {
	   	L[j].data=e//将数据赋值给此分量的data
		   for(l=1;l<=i-1;l++)//找到第i个元素之前的位置
		   k=L[k].cur;//K是第i个元素前一个元素的下标 
		   L[j].cur=L[k].cur//把第i个元素之前的cur赋值给新元素的cur
		   L[k].cur=j;//把新元素的下标赋给第i个元素之前的元素的cur
		   return OK; 
		} 
		return ERROR;
	} 
	//删除元素
	//删除在L中第i个数据元素e
	Status ListDelete(StaticLinkList L,int i)
	{
		int j,k;
		if(i<1||i>ListLength(L))
		return ERROR;
		k=MAX_SIZE-1;
		for(j=1;j<=i-1;j++)
		k=L[k].cur;//获得要删除的前一个元素的下标 
		j=L[k].cur;//获取要删除元素的下标 
		L[k].cur=L[j].cur;
		Free_SSL(L,j);
		return OK; 
	 } 
	 //相当于free函数
	 //将下标为k的空闲结点回收到备用链表
	 void Free_SSL(StaticLinkList space,int k)
	 {
	 	space[k].cur=space[0].cur//把第一个元素的cur值赋给要删除的分量cur
		 space[0].cur=k;//把要删除的分量的下标赋值给第一个元素的cur 
	  } 
	  
	  //初始条件：静态链表已存在。操作结果：返回L中数据元素的个数
	  int ListLength(StaticLinkList L)
	  {
	  	int j=0;
	  	int i=L[MAXSIZE-1].cur;
	  	while(i)
	  	{
	  		i=L[i].cur;
	  		j++
		  }
		  return j;
	   } 
