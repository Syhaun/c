//ͨ�����㷵���ִ�T��next���� 
void get_next(char* T,int *next)
{
	int i=1,j = 0;
	next[1] = 0;
	while(i<T[0])//�˴�T[0]��ʾ��T�ĳ���
	{
		if(j == 0||T[i] == T[j]) //T[i]��ʾ��׺�ĵ����ַ���T[j]��ʾǰ׺�ĵ����ַ�
		{
			++i;
			++j; 
			next[i] = j; 
		 } 
		 else
		 j = next[j];//���ַ���ͬ����jֵ���� 
	 } 
}
//�����Ӵ�T������S�е�pos���ַ�֮���λ�ã��������ڣ�����ֵ����0
// T �ǿգ�1<=pos<=StrLength(S)
int Index_KMP(char* S��char* T,int pos)
{
	int i = pos;//i��������S��ǰλ���±�ֵ����pos��Ϊ1�����posλ�ÿ�ʼƥ��
	int j = 1;//j�����Ӵ�T�е�ǰλ���±�ֵ
	int next[255];//����һnext����
	get_next(T,next);//�Դ�T���������õ�next����
	while(i <= S[0] && j<= T[0])//��iС��S�ĳ�����jС��T�ĳ���ʱ��ѭ������
	{
		if(j==0||S[i] == T[j])//����ĸ��������������������㷨�����ˡ�j=0�ж�
		{
			++i;
			++j; 
		 } 
		 else//ָ��������¿�ʼƥ��
		 {
		 	j = next[j]//j�˻غ��ʵ�λ�ã�iֵ���� 
		  } 
	 } 
	 if(j > T[0])
	 return i-T[0];
	 else
	 return 0;
 } 
 
 
 
 //KMPģʽƥ���㷨�Ľ�
  
