//ѭ������
typedef int QElemType;//QElemType���͸���ʵ������������������Ϊint��
//ѭ�����е�˳��洢�ṹ
typedef struct
{
	QElemType data[MAXSIXE];
	int front;//ͷָ��
	int rear;//βָ�룬�����в��գ�ָ�����βԪ�ص���һ��λ�� 
 } SqQueue;
 
 //ѭ�����еĳ�ʼ��
 //��ʼ��һ���ն���
 Status InitQueue(SqQueue *Q)
 {
 	Q->front = 0;
 	q->rear = 0;
 	return OK;
  } 
  
  //ѭ����������鳤��
  //����Q��Ԫ�ظ�����Ҳ���Ƕ��еĵ�ǰ����
  int QueueLength(SqQueue Q)
  {
  	return (Q.rear - Q.front+MAXSIZE)%MAXSIZE;
   } 
   
   //ѭ�����е���Ӳ���
   //������δ���������Ԫ��eΪQ�µĶ�βԪ��
  Status EnQueue(SqQueue *Q,QElemType e)
  {
  		if((Q->rear+1)%MAXSIZE == Q->front)//���������жϵ��ж�
  		{
  			return ERROR;
  			Q->data[Q->rear] = e;//��Ԫ��e��ֵ����β
			Q->rear = (Q->rear+1)%MAXSIZE//rearָ�������һλ��
			//���������ת������ͷ�� 
		  }
		  return OK;
  }
  
  //ѭ�����еĳ����в���
  //�����в��գ���ɾ��Q�ж�ͷԪ�أ���e������ֵ
  Status DeQueue(SqQueue *Q,QElemType *e)
  {
  	if(Q->front == Q->rear)//���пյ��ж�
	  {
	  	return ERROR;
	   } 
	 *e = Q->data[Q->front];//����ͷԪ�ظ�ֵ��e
	 Q->front = (Q->front+1)%MAXSIZE//frontָ�������һλ��
	 //���������ת������ͷ��
	 return OK;  
   } 
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
	  	
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
    
