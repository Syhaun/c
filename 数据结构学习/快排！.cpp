//���Ż��ڶ���˼��
//�ŵ㣺�Ȳ��˷ѿռ䣬�����ٶ��ֺܿ�
#include<stdio.h>
#include<stdlib.h>
int *a=(int*)malloc(100*sizeof(int));
int n;

void quicksort(int left,int right)
{
	int temp=a[left];//temp�д���ǻ�׼�� 
	if(left>right)
	{
		return ; 
	}
	
	int i=left,j=right;
	while(i!=j)
	{
		//˳��������������
		while(a[j]>=temp&&i<j)
		{
			j--;
		}//���ұ������� 
		while(a[i]<=temp&&i<j)
		{
			i++;
		}//����������� 
	//�����������������е�λ��
		if(i<j)
		{
			int temp=a[i];
			a[i]=a[j];
			a[j]=temp;
	 	} 
	}
	//�ڽ���׼����λ
	a[left]=a[i];
	a[i]=temp; 
	quicksort(left,i-1);//����������ߵ�,������һ���ݹ�Ĺ��� 
	quicksort(i+1,right);// ���������ұߵģ�����Ҳ��һ���ݹ�Ĺ��� 
}
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	quicksort(0,n-1);
	for(int i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
	return 0;
 }












