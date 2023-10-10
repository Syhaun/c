#include<stdio.h>
char a[12][12], b[12][12], c[12][12], d[12][12];
int n;
int compare(void)
{
 int i, j;
 for (i = 0; i < n; i++)
  for (j = 0; j < n; j++)
   if (c[i][j] != b[i][j])
    return(0);
 return(1);

}
int operate1(void)
{
 int i, j;
 for (i = 0; i < n; i++)
  for (j = 0; j < n; j++)
   b[i][j] = a[n - 1-j][i];
 return(compare());
}
int operate2(void)
{
 int i, j;
 for (i = 0; i < n; i++)
  for (j = 0; j < n; j++)
   b[i][j] = a[n -1- i][n-1-j];
 return(compare());
}
int operate3(void)
{
 int i, j;
 for (i = 0; i < n; i++)
  for (j = 0; j < n; j++)
   b[i][j] = a[j][n-1-i];
 return(compare());
}
int operate4(void)
{
 int i, j;
 for (i = 0; i < n; i++)
  for (j = 0; j < n; j++)
   b[i][j] = a[i][n-1-j];
 return(compare());
}
int operate5(void)
{
 int i, j;
 for (i = 0; i < n; i++)
  for (j = 0; j < n; j++)
   d[i][j] = a[i][n-1-j];
 for (i = 0; i < n; i++)
  for (j = 0; j < n; j++)
   b[i][j] = d[n -1- j][i];
 if(compare()==1)
  return(1);
 else
 {
  for (i = 0; i < n; i++)
   for (j = 0; j < n; j++)
    b[i][j] = d[n - 1 - i][n -1- j];
  if (compare()==1)
   return(1);
  else
  {
   for (i = 0; i < n; i++)
    for (j = 0; j < n; j++)
     b[i][j] = d[j][n - 1 - i];
   if (compare()==1)
    return(1);
  }
 }
 return(0);
}
int operate6(void)
{
 int i, j;
 for (i = 0; i < n; i++)
  for (j = 0; j < n; j++)
   b[i][j] = a[i][j];
 return(compare());
}
int main(void)
{
 int i,j;
 scanf("%d", &n);
 getchar();
 for (i = 0; i < n; i++)
 {
  for (j = 0; j <=n; j++)
  { a[i][j] = getchar();
  }
 }
 for (i = 0; i < n; i++)
 {
  for (j = 0; j <=n; j++)
   {c[i][j] = getchar();
   }
 }
 if (operate1()==1)
  printf("1");
 else if (operate2()==1)
  printf("2");
 else if (operate3()==1)
  printf("3");
 else if (operate4()==1)
  printf("4");
 else if (operate5()==1)
  printf("5");
 else if (operate6()==1)
  printf("6");
 else 
  printf("7");
 return(0);
}
