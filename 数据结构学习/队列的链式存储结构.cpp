//���е���ʽ�洢�ṹ
//�����еĽṹ
typedef int QElemType;//QElemType���͸���ʵ������������������Ϊint
typedef struct QNode//���ṹ
{
	QElemType data;
	struct QNode *next;
 } QNode,*QueuePtr;
 typedef struct//���е�����ṹ
 {
 	QueuePtr front,rear;//��ͷ����βָ�� 
  } LinkQueue;
  
  //��Ӳ���
  //����Ԫ��eΪQ���µĶ�βԪ��
  Status EnQueue(LinkQueue *Q,QElemType e)
  {
  	QueuePtr s = (QueuePtr)malloc(sizeof(QNode));
  	if(!s)//�洢����ʧ��
	  exit(OVERFLOW);
	  s->data = e;
	  s->next = NULL;
	  Q->rear->next = s;//��ӵ��Ԫ��e�½ڵ�s��ֵ��ԭ��β���ĺ��
	  Q->rear = s;//�ѵ�ǰ��s����Ϊ��β��㣬rearָ��s
	  return OK; 
   } 
   
   //���Ӳ���
   //�����в��գ�ɾ��Q�Ķ�ͷԪ�أ���e������ֵ��������OK�����򷵻�ERROR
   Status DeQueue(LinkQueue *Q,QElemType *e)
   {
   		QueuePtr p;
		if(Q->front == Q->rear)
		{
			return ERROR;
			}	
		p = Q->front->next;//��Ҫɾ���Ķ�ͷ����ݴ��p
		*e = p->data;//��Ҫɾ���Ķ�ͷ����ֵ��ֵ��e
		Q->front->next = p->next//��ԭ��ͷ�����p->next��ֵ��ͷ�����
		if(Q->rear == p)//����ͷ�Ƕ�β����ɾ����rearָ��ͷ���
		{
			Q->rear = Q->front;
		 } 
		 free(p);
		 return Ok;    
   }
   
   
   
   
   
   
   
   
   
   
   
   
   
   
