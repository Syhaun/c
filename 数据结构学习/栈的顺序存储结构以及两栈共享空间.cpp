//栈的顺序存储结构
//栈的结构定义
typedef int SElemType;//SElemType类型根据实际情况而定，这里假设为int
typedef struct
{
	SElemType data[MAXSIZE];
	int top;//用于栈顶指针 
 } SqStack;
 
 //进栈操作
 //插入元素e为新的栈顶元素
 Status Push(SqStack*S,SElemType e)
 {
 	if(S->top==MAXSIZE-1)//栈满
	 {
	 	return ERROR;
	  } 
	  S->top++;//栈顶指针增加一
	  S->data[S->top]=e;//将新插入元素赋值给栈顶空间
	  return OK; 
  } 
  
  //出栈操作
  //若栈不空，则删除S的栈顶元素，用e返回其值，并返回OK;否则返回ERROR
  Status Pop(SqStack*S,SElemType*e)
  {
  	if(S->top==1)
  	return ERROR;
  	*e=S->data[S->top];//将要删除的栈顶元素赋值给e
	  S->top--;//栈顶指针减一
	  rteurn OK; 
   } 
   
   //两栈共享空间的结构
   typedef struct
   {
   	SElemType data[MAXSIZE];
   	int top1;//栈1栈顶指针
	int top2;//栈2栈顶指针    
	} SqDoubleStack;
	
	//两栈共享空间进栈操作
	//除了要插入元素值参数外，还需要有一个判断是栈1还是栈2的栈号参数stackNumber
	//插入元素为e的新的栈顶元素
	Status Push(SqDoubleStack*S,SElemType e,int stackNumber)
	{
		if(S->top1+1==S->top2)//栈已满，不能再push新元素了
		return ERROR;
		if(stackNumber==1)//栈1有元素进栈
		S->data[++S->top1]=e//若栈1则先top1+1后给数组元素赋值
		else if(stackNumber==2)//栈2有元素进栈
		S->data[--S->top2]=e;//若栈2则先top2-1后给数组元素赋值
		rteurn OK; 
	 } 
	 
	 //两栈共享空间出栈操作
	 //若栈不空，则删除S的栈顶元素，用e返回其值，并返回OK；否则返回ERROR
	 Status Pop(SqDoubleStack*S,SElemType*e,int stackNumber)
	 {
	 	if(stackNumer==1)
	 	{
	 		if(S->top1==-1)
	 		return ERROR//说明栈1已经是空栈，溢出
			 *e=S->data[S->top1--];//将栈1的栈顶元素出栈 
		 }
		 else if(stackNumber==2)
		 {
		 	if(S->top2==MAXSIZE)
		 	return ERROR;//说明栈2已经是空栈，溢出
			 *e=S->data[S->top2++]//将栈2的栈顶元素出栈 
		 }
		 return OK; 
	  } 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	  
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
