//ջ��˳��洢�ṹ
//ջ�Ľṹ����
typedef int SElemType;//SElemType���͸���ʵ������������������Ϊint
typedef struct
{
	SElemType data[MAXSIZE];
	int top;//����ջ��ָ�� 
 } SqStack;
 
 //��ջ����
 //����Ԫ��eΪ�µ�ջ��Ԫ��
 Status Push(SqStack*S,SElemType e)
 {
 	if(S->top==MAXSIZE-1)//ջ��
	 {
	 	return ERROR;
	  } 
	  S->top++;//ջ��ָ������һ
	  S->data[S->top]=e;//���²���Ԫ�ظ�ֵ��ջ���ռ�
	  return OK; 
  } 
  
  //��ջ����
  //��ջ���գ���ɾ��S��ջ��Ԫ�أ���e������ֵ��������OK;���򷵻�ERROR
  Status Pop(SqStack*S,SElemType*e)
  {
  	if(S->top==1)
  	return ERROR;
  	*e=S->data[S->top];//��Ҫɾ����ջ��Ԫ�ظ�ֵ��e
	  S->top--;//ջ��ָ���һ
	  rteurn OK; 
   } 
   
   //��ջ����ռ�Ľṹ
   typedef struct
   {
   	SElemType data[MAXSIZE];
   	int top1;//ջ1ջ��ָ��
	int top2;//ջ2ջ��ָ��    
	} SqDoubleStack;
	
	//��ջ����ռ��ջ����
	//����Ҫ����Ԫ��ֵ�����⣬����Ҫ��һ���ж���ջ1����ջ2��ջ�Ų���stackNumber
	//����Ԫ��Ϊe���µ�ջ��Ԫ��
	Status Push(SqDoubleStack*S,SElemType e,int stackNumber)
	{
		if(S->top1+1==S->top2)//ջ������������push��Ԫ����
		return ERROR;
		if(stackNumber==1)//ջ1��Ԫ�ؽ�ջ
		S->data[++S->top1]=e//��ջ1����top1+1�������Ԫ�ظ�ֵ
		else if(stackNumber==2)//ջ2��Ԫ�ؽ�ջ
		S->data[--S->top2]=e;//��ջ2����top2-1�������Ԫ�ظ�ֵ
		rteurn OK; 
	 } 
	 
	 //��ջ����ռ��ջ����
	 //��ջ���գ���ɾ��S��ջ��Ԫ�أ���e������ֵ��������OK�����򷵻�ERROR
	 Status Pop(SqDoubleStack*S,SElemType*e,int stackNumber)
	 {
	 	if(stackNumer==1)
	 	{
	 		if(S->top1==-1)
	 		return ERROR//˵��ջ1�Ѿ��ǿ�ջ�����
			 *e=S->data[S->top1--];//��ջ1��ջ��Ԫ�س�ջ 
		 }
		 else if(stackNumber==2)
		 {
		 	if(S->top2==MAXSIZE)
		 	return ERROR;//˵��ջ2�Ѿ��ǿ�ջ�����
			 *e=S->data[S->top2++]//��ջ2��ջ��Ԫ�س�ջ 
		 }
		 return OK; 
	  } 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	  
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
