//TΪ�ǿմ���������S�еĵ�pos���ַ�֮�������T��ȵ��Ӵ�           
//�򷵻ص�һ���������ִ���S�е�λ�ã����򷵻�0
int Index(String S,String T,int pos)
{
	int n,m,i;
	String sun;
	if(pos>0)
	{
		n = StrLength(S);//�õ������ĳ���
		m = Strlength(T);//�õ��ִ��ĳ���
		i = pos;
		while(i <= n-m+1)
		{
			SubString(sub,S,i,m)//ȡ�����ĵ�i��λ��
			//������T����ִ���sub
			if(StrCompare(sub,T) != 0)//������������
			++i;
			else			//���������� 
			return i; 		//�򷵻�iֵ 
		 } 
	}
	return 0;//�����ִ���T��ȣ�����0 
 } 
