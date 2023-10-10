#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 20

typedef int ElemType;

typedef struct{
    ElemType elem[MAXSIZE];
    int length;
 }SeqList;

void InitList(SeqList *L)
{
   int x;
   L->length=0;
   scanf("%d",&x);
   while(x!=-1)
   {
       L->elem[L->length+1]=x;
       L->length++;
       scanf("%d",&x);
   }
}
int Delete(SeqList *L,int i,int *elem){
	if(i < 0 || i > L->length) 
	return 0;
	*elem = L -> elem[i];
	for(int j = i; j < L -> length; j++)
	L->elem[j - 1] = L -> elem[j];
	L -> length--;
	return 1;
	
}


int main()
{
    SeqList L;
    int i,elem;
    InitList(&L);
      scanf("%d",&i);
      if(!Delete(&L,i,&elem))
           printf("The location of the element is illegal.");
      else
           printf("The No.%d element is deleted, its value is %d.",i,elem);
    
	return 0;
}


