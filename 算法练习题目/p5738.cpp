#include <stdio.h>
int n, m; 
void quick_sort(int arr[])
 {
 	  for(int i = 0;i<m-1;i++)
 	  {
 	  	for(int j = i;j<m;j++)
 	  	{
 	  		if(arr[i]>arr[j])
 	  		{
 	  			int temp=arr[i];
 	  			arr[i]=arr[j];
 	  			arr[j]=temp;
			   }
		   }
	   }
}

double Average(int arr[][20], int col) {
    double sum = 0.0;
    quick_sort(arr[col]);
    for (int i = 1; i < m - 1; i++) {
        sum += arr[col][i];
    }
    double average = sum / (m - 2); 
    return average;
}

int main() {
    scanf("%d%d", &n, &m);
    int arr[100][20];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &arr[i][j]);
        }
    }
    double result = 0.0;
    for (int i = 0; i < n; i++) 
	{
        double temp = Average(arr, i);
       
        if (result < temp) {
            double t = result;
            result = temp;
            temp = t;
        }
    }
    printf("%.2lf", result);
    return 0;
}

