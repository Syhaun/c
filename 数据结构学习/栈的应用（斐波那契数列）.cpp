int main()
{
	int i;
	int a[40];
	a[0] = 0;
	a[1] = 1;
	printf("%d",a[0]);
	printf("%d",a[1]);
	for(int i = 2;i < 40;i++)
	{
		a[i] = a[i-1] + a[i-2];
		printf(" %d ",a[i]);
	}
	return 0;
 }
 
 //쳲������ĵݹ麯��
 int Fbi(int i)
 {
 	if( i < 2)
 	return i == 0 ? 0 : 1;
 	return Fbi(i-1) + Fbi(i-2);//����Fbi���Ǻ����Լ������ٵ����Լ� 
  } 
  int main()
  {
  	int i;
  	for(int i = 0;i < 40;i++)
  	{
  		printf(" %d ", Fbi(i));
	  }
	  return 0;
   } 
