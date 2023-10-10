//���Ա��˳��洢�Ľṹ���� 
#define MAXSIZE 20
typedef int ElemType;
typedef struct
{
	ElemType data[MAXSIZE];
	int length;
}SqList;

//��ȡԪ�ز�������ʵGetElem���� 
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
typedef int Status;
/*Status�Ǻ��������ͣ���ֵ�Ǻ��������״̬���룬��ok��*/
/*��ʼ������˳�����Ա�L�Ѵ��ڣ�1<=i<=ListLength(L)*/
/*�����������e����L�еĵ�i������Ԫ�ص�ֵ*/
Status GetElem(SqList L,int i,ElemType*e)
{
	if(L.length==0||i<1||i>L.length)
		return ERROR;
		*e=L.data[i-1];
		return OK;
 } 
 
 //�������
 /*��ʼ������˳�����Ա�L�Ѵ��ڣ�1<=i<=ListLength(L),*/
 /*�����������L�е�i��λ��֮ǰ�����µ�����Ԫ��e��L�ĳ��ȼ�1*/
 Status ListInsert(SqList*L,int i,ElemType e)
 {
 	int k;
 	if(L->length==MAXSIZE)/*˳�����Ա��Ѿ���*/
	  return ERROR;
	if(i<1||i>L->length+1)//��i���ڷ�Χ��ʱ 
		return ERROR;
	if(i<=L->length)//����������λ�ò��ڱ�β 
	{
		for(k=L->length-1;k>=i-1;k--)//��Ҫ�����λ�ú�����Ԫ������ƶ�һλ
		L->data[k+1]=L->data[k]; 
	}
	L->data[i-1]=e;//����Ԫ�ز���
	L->length++;
	return OK; 
  } 
  
  //ɾ������
  /*��ʼ������˳�����Ա�L�Ѵ��ڣ�1<=i<=ListLength(L)
  ���������ɾ��L�ĵ�i������Ԫ�أ�����e������ֵ��L�ĳ��ȼ�1*/
  Status ListDelate(SqList *L,int i,ElemType*e)
  {
  	int k;
  	if(L->length==0)//���Ա�Ϊ��
	  return ERROR;
	  if(i<1||i>L->length)//ɾ����λ�ò���ȷ
	  return ERROR;
	  *e=L->data[i-1];
	  if(i<L->length)//���ɾ���������λ��
	  {
	  	for(k=i;k<L->length;k++)//��ɾ��λ�ú��Ԫ��ǰ��
		  L->data[k-1]=L->data[k]; 
	   } 
	   L->length--;
	   return OK;
   } 
   
