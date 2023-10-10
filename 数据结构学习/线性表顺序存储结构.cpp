//线性表的顺序存储的结构代码 
#define MAXSIZE 20
typedef int ElemType;
typedef struct
{
	ElemType data[MAXSIZE];
	int length;
}SqList;

//获取元素操作，现实GetElem操作 
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
typedef int Status;
/*Status是函数的类型，其值是函数结果的状态代码，如ok等*/
/*初始条件：顺序线性表L已存在，1<=i<=ListLength(L)*/
/*操作结果：用e返回L中的第i个数据元素的值*/
Status GetElem(SqList L,int i,ElemType*e)
{
	if(L.length==0||i<1||i>L.length)
		return ERROR;
		*e=L.data[i-1];
		return OK;
 } 
 
 //插入操作
 /*初始条件：顺序线性表L已存在，1<=i<=ListLength(L),*/
 /*操作结果：在L中第i个位置之前出入新的数据元素e，L的长度加1*/
 Status ListInsert(SqList*L,int i,ElemType e)
 {
 	int k;
 	if(L->length==MAXSIZE)/*顺序线性表已经满*/
	  return ERROR;
	if(i<1||i>L->length+1)//当i不在范围内时 
		return ERROR;
	if(i<=L->length)//若插入数据位置不在表尾 
	{
		for(k=L->length-1;k>=i-1;k--)//将要插入的位置后数据元素向后移动一位
		L->data[k+1]=L->data[k]; 
	}
	L->data[i-1]=e;//将新元素插入
	L->length++;
	return OK; 
  } 
  
  //删除操作
  /*初始条件：顺序线性表L已存在，1<=i<=ListLength(L)
  操作结果：删除L的第i个数据元素，并用e返回其值，L的长度减1*/
  Status ListDelate(SqList *L,int i,ElemType*e)
  {
  	int k;
  	if(L->length==0)//线性表为空
	  return ERROR;
	  if(i<1||i>L->length)//删除的位置不正确
	  return ERROR;
	  *e=L->data[i-1];
	  if(i<L->length)//如果删除不是最后位置
	  {
	  	for(k=i;k<L->length;k++)//将删除位置后继元素前移
		  L->data[k-1]=L->data[k]; 
	   } 
	   L->length--;
	   return OK;
   } 
   
