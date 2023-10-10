#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 100
typedef int ElemType;

//���Ķ���
typedef struct {
    ElemType elem[MAXSIZE];
    int length;
}SeqList;
//��ʼ��
void Init_SeqList(SeqList *L)
{
    L -> length = 0;
}
//�������
int Insert_SeqList(SeqList *L,int i,ElemType x) {
    int j;
    if(L -> length == MAXSIZE - 1)
    {
        printf("����");
        return -1;
    }
    if( i < 0 || i > L -> length + 1)
    {
        printf("λ�ô�λ");
        return -1;
    }
    for(j = L -> length; j > i; j--)
        L  -> elem[j + 1] = L -> elem[j];
    L -> elem[i] = x;
    L -> length++;
    return 1;
}
//ɾ������  ��x����ɾ������ֵ
int Delete_SeqList(SeqList *L, int i, ElemType *e) {
	int j;
	if(i < 0 || i >= L -> length)
	{
		printf("�����ڵ�i��Ԫ��");
		return 0;
	}
	* e = L -> elem[i];
	for(j = i; j < L -> length; j++)
	{
		L -> elem[j] = L -> elem[j + 1];
	}
	L -> length--;
	return 1;
}
//��ֵ����
int Location_SeqList(SeqList *L,ElemType x){
	int i = 0;
	while(i < L->length && L -> elem[i] != x)
	i++;
	if(i >= L ->length)
	return 0;
	else return i;
}
int main() {
	SeqList *L;
	L = (SeqList*)malloc(sizeof(SeqList));
	Init_SeqList(L);
	Insert_SeqList(L,0,100);
	printf("%d\n",L->elem[0]);

	int x = Location_SeqList(L,100);
	printf("%d\n",x);
	
	int *e = (int*)malloc(sizeof(int));
	Delete_SeqList(L,0,&e);
	printf("%d\n",e);
	return 0;
}