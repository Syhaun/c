#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 32
typedef struct {
	int elem[MAXSIZE];
	int len;
}SeqList;
void selectMax2 (SeqList * L ){
	if(L -> len == 0)
	printf("none");
	else if(L -> len == 1)
	printf("First=%d",L -> elem[1]);
	else
	{
		int max1 = 0,max2 = 0;
		if(L -> elem[1] > L -> elem[2]) {
			max1 = L->elem[1];
            max2 = L->elem[2];
        } else {
            max1 = L->elem[2];
            max2 = L->elem[1];
        }
        for(int i = 3; i <= L -> len; i++) {
        	if (L -> elem[i] > max1) {
                max2 = max1;
                max1 = L -> elem[i];
            } else if (L -> elem[i] > max2) {
                max2 = L -> elem[i];
            }
		}
		printf("First=%d,Second=%d\n", max1, max2);
	}
		 
}
void createSeq(SeqList *L)
{
   int x;
   L->len=0;
   scanf("%d",&x);
   while(x!=-1)
   {
       L->elem[L->len+1]=x;
       L->len++;
       scanf("%d",&x);
   }
}
int main()
{
    SeqList L;
    L.len=0;
    createSeq(&L);//输入-1表示结束
    selectMax2(&L);
    return 0;
}

/* 请在这里填写答案 */

