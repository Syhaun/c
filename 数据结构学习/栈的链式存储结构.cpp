//ջ����ʽ�洢�ṹ
//�ṹ����
typedef struct StackNode
{
	SElemType data;
	struct StackNode *next;
 } StackNode,*LinkStackPtr;
 
 typedef struct LinkStack
 {
 	LinkStackPtr top;
 	int count;
 }LinkStack;
 
 //����Ԫ��eΪ�µ�ջ��Ԫ��
 Status Push(LinkStack*S,SElemType e)
 {
 	LinkStackPtr s = (LinkStackPtr)malloc(sizeof(StackNode));
 	s->data = e;
 	s->next = S->top;//�ѵ�ǰ��ջ��Ԫ�ظ�ֵ���½���ֱ�Ӻ��
	S->top = s;//���½��s��ֵ��ջ��ָ�� 
	s->count++;
	return OK; 
  } 
  
  //��ջ����
  //��ջ���գ���ɾ��S��ջ��Ԫ�أ���e������ֵ��������OK�����򷵻�ERROR
  Status Pop(LinkStack*S,SElemType*e)
  {
  	LinkStackPtr p;
  	if(StackEmpty(*S))
  	return ERROR;
  	*e =S->top->data;
  	p = S->top;//��ջ����㸳ֵ��p
	s->top = S->top->next;//ʹ��ջ��ָ������һλ��ָ���һ���
	free(p);//�ͷŽ��p
	S->count--;
	return OK; 
   } 
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
