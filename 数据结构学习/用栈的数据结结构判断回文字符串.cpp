//用栈实现回文字符串的判断
#include<stdio.h>
#include<string.h>
int main()
{
	char a[101],s[101];
	gets(a);//读入一个字符串
	int len = strlen(a);//求字符串的长度
	int mid = len/2;//求字符串的中点
	int top = 0;//栈的初始化
	//将mid前的字符依次入栈
	for(int i=0;i<mid;i++)
	{
		s[top++] = a[i];
		
	 } 
	 //判断字符串的长度是奇书还是偶数，并找出需要进行字符匹配的起始下标
		int next;	 
	  if(len%2 == 0)
	  next = mid;
	  else
	  next = mid+1;
	  //开始匹配
	  for(int i = next;i < len;i++)
	  {
	  	top--;
	  	if(a[i]!=s[top])
	  	{
	  		break;
		  }

	   } 
	   //如果top的值为0；则说明栈内所有的字符都被一一匹配了
	   if(top == 0)
	   printf("YES");
	   else
	   printf("NO");
	   return 0;
	  
 } 
