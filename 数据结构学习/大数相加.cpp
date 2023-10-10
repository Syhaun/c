#include <stdio.h>
#include <string.h>
int main(void)
{
   char a[20],b[20];
   int af[20],bf[20],x,y,c[21],max;
   int num;  //用来判断是否进位
   scanf("%s %s",&a,&b);
   x=strlen(a);
   y=strlen(b);
   max= x>y?x:y;
   for(int i=0;i<x;i++)
{
   af[i]=a[x-i-1]-'0'; //将字符转化为数字
}
   for(int i=0;i<y;i++)
{
    bf[i]=b[y-i-1]-'0';
}

for(int i=0;i<max;i++)
{
   num=bf[i]+af[i]+num;
   if(num>=10)
   {
     c[i]=num%10;
     num=num/10;
   }
   else
   {
      c[i]=num;
      num=0;
   } 
}
 if(num>0)
{
   printf("%d",num);
   for(int i=max-1;i>=0;i--)
   {
       printf("%d",c[i]);
   }
}
else
{
    for(int i=max-1;i>=0;i--)
   {
       printf("%d",c[i]);
   }
}
return 0; 
}
  

      


