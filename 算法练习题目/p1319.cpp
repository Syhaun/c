#include<stdio.h>
int main()
{
 int n, m;
 int row=1, column=1;
 int arr[201][201] = { 0 };
 scanf("%d", &n); 
 int sum=0;
    int temp=0;
    int p=n;
    while(sum<n*n){
    int m;
    scanf("%d",m);
        temp++;
        for(int i=1;i<=m;i++){
            if(temp%2==1)
            {arr[row][column]=0;}
            else{arr[row][column]=1;}
                column++;
                sum++;
                if(column==n+1){
                    row++;
                    column=1;
                }
            }

        }
  for (int i=1;i<=p;i++)
  {
   for (int j=1;j<=p;j++)
   {
    printf("%d",arr[i][j]);
   }
   printf("\n");
  }
 return 0;
}
