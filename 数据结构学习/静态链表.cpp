//���Ա�ľ�̬����洢�ṹ
#define MAXSIZE 1000//�����������󳤶���1000
typedef struct
{
	ElemType data;
	int cur;//�α꣨Cursor����Ϊ0ʱ��ʾ��ָ�� 
 } Component,StaticLinkList[MAXSIZE];
 
 //��ʼ������״̬
 //��һά����space�и���������һ��������
 //space[0].curΪͷָ�룬"0"��ʾ��ָ��
 Status InitList(StaticLinkList space)
 {
 	int i;
 	for(i=0;i<MAXSIZE-1;i++)
 	space[i].cur=i+1;
 	space[MAXSIZE-1].cur=0//Ŀǰ��̬����Ϊ�գ����һ��Ԫ�ص�curΪ0
	 return 0; 
  } 
  
  //�൱��malloc���� 
  //�����ÿռ�����Ϊ�ǿգ��򷵻ط���Ľ���±꣬���򷵻�0
  int Malloc_SLL(StaticLinkList space)
  {
  	int i=space[0].cur//��ǰ����ĵ�һ��Ԫ�ص�cur���ֵ
	  //����Ҫ���صĵ�һ�����ÿ��е��±�
	  if(space[0]cur)
	  space[0]cur=space[i].cur//����Ҫ�ó�һ��������ʹ�ã��������Ǿ͵ð�������һ����������������
	  return i; 
   } 
   //����Ԫ��
   //��L�еĵ�i��Ԫ��֮ǰ�����µ�Ԫ��e
   Status ListInsert(StaticLinkList L,int i,ElemType e)
   {
   	int j,k,l;
   	k=MAX_SIZE-1;//ע��k���������һ��Ԫ�ص��±�
	   if(i<1||i>ListLength(L)+1)
	   return ERROR;
	   j=Malloc_SSL(L);//��ÿ��з������±�
	   if(j)
	   {
	   	L[j].data=e//�����ݸ�ֵ���˷�����data
		   for(l=1;l<=i-1;l++)//�ҵ���i��Ԫ��֮ǰ��λ��
		   k=L[k].cur;//K�ǵ�i��Ԫ��ǰһ��Ԫ�ص��±� 
		   L[j].cur=L[k].cur//�ѵ�i��Ԫ��֮ǰ��cur��ֵ����Ԫ�ص�cur
		   L[k].cur=j;//����Ԫ�ص��±긳����i��Ԫ��֮ǰ��Ԫ�ص�cur
		   return OK; 
		} 
		return ERROR;
	} 
	//ɾ��Ԫ��
	//ɾ����L�е�i������Ԫ��e
	Status ListDelete(StaticLinkList L,int i)
	{
		int j,k;
		if(i<1||i>ListLength(L))
		return ERROR;
		k=MAX_SIZE-1;
		for(j=1;j<=i-1;j++)
		k=L[k].cur;//���Ҫɾ����ǰһ��Ԫ�ص��±� 
		j=L[k].cur;//��ȡҪɾ��Ԫ�ص��±� 
		L[k].cur=L[j].cur;
		Free_SSL(L,j);
		return OK; 
	 } 
	 //�൱��free����
	 //���±�Ϊk�Ŀ��н����յ���������
	 void Free_SSL(StaticLinkList space,int k)
	 {
	 	space[k].cur=space[0].cur//�ѵ�һ��Ԫ�ص�curֵ����Ҫɾ���ķ���cur
		 space[0].cur=k;//��Ҫɾ���ķ������±긳ֵ����һ��Ԫ�ص�cur 
	  } 
	  
	  //��ʼ��������̬�����Ѵ��ڡ��������������L������Ԫ�صĸ���
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
