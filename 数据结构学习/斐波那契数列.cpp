#include<stdio.h>
int main()
{
 int i, j, n;
 long fact, sum = 0;
 scanf("%d", &n);
 for (i = 1; i <= n; i++)
 {
  for (j = 1, fact = 1; j <= i; j++)
  {
   fact *= j;
   
  }
  sum += fact;
 }
 printf("\n%ld", sum);
}
