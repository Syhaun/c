#include<stdio.h>
int c=0;
void move(char x,int n,char z)
{
 printf("��%i������%i���̴�%c->%c\n",++c,n,x,z);
}
void hanoi(int n,char x,char y,char z)
{
 if(n==1)
  move(x,1,z);
 else
 {
  hanoi(n-1,x,z,y);
  move(x,n,z);
  hanoi(n-1,y,x,z);
 }
}
int main()
{
 int n;
 while(printf("3������Ϊa��b��c��Բ�������a��������b���Ƶ�c����������Բ������")!=EOF){
 scanf("%d",&n);
 hanoi(n,'a','b','c'); 
 }
}
