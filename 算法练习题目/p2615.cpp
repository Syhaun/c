#include<stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    int arr[40][40] = {0};
    int x = 1;
    int y = (n+1)/2;
    for(int i=1;i<=n*n;i++)
    {
        arr[x][y]=i;
        if(!arr[(x-2+n)%n+1][(y%n+n)%n+1])
        {
            x=(x-2+n)%n+1;
            y=(y%n+n)%n+1;
        }
        else
        {
            x=x%n+1;
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j =1;j<=n;j++)
        {
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }
    return 0; 
}
