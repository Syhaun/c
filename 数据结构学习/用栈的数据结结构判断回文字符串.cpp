//��ջʵ�ֻ����ַ������ж�
#include<stdio.h>
#include<string.h>
int main()
{
	char a[101],s[101];
	gets(a);//����һ���ַ���
	int len = strlen(a);//���ַ����ĳ���
	int mid = len/2;//���ַ������е�
	int top = 0;//ջ�ĳ�ʼ��
	//��midǰ���ַ�������ջ
	for(int i=0;i<mid;i++)
	{
		s[top++] = a[i];
		
	 } 
	 //�ж��ַ����ĳ��������黹��ż�������ҳ���Ҫ�����ַ�ƥ�����ʼ�±�
		int next;	 
	  if(len%2 == 0)
	  next = mid;
	  else
	  next = mid+1;
	  //��ʼƥ��
	  for(int i = next;i < len;i++)
	  {
	  	top--;
	  	if(a[i]!=s[top])
	  	{
	  		break;
		  }

	   } 
	   //���top��ֵΪ0����˵��ջ�����е��ַ�����һһƥ����
	   if(top == 0)
	   printf("YES");
	   else
	   printf("NO");
	   return 0;
	  
 } 
