//求模式串T的next函数修正值并存入数组nextval
void get_nextval(String T,int *nexttval)
{
	int i=1,j = 0;
	naxtval[1] = 0;
	while(i < T[0])//此处T[0]表示串T的长度
	{
		if( j == 0 || T[i] == T[j])//T[i]表示后缀的翻个字符
		 //T[j]表示前缀的单个字符
		 {
		 	++i;
		 	++j;
		 	if(T[i] != T[j])//若当前字符与前缀字符不同 
		 	nextval[i] = j;//则当前的j为nextval在i位置的值
			 else
			 nextval[i] = nextval[j]; //如果与前缀字符相同，则将前缀字符的nextval值赋给nextval在i位置的值  
		  } 
		else
		j = nextval[j];//若字符不相同，则j值回溯 
	 } 
 } 

 //返回子串T在主串S中第pos个字符之后的位置，若不存在，则函数值返回0
// T 非空，1<=pos<=StrLength(S)
int Index_KMP(String S,String T,int pos)/	
{
	int i = pos;//i用于主串S当前位置下标值，若pos不为1，则从pos位置开始匹配
	int j = 1;//j用于子串T中当前位置下标值
	int next[255];//定义一next数组
	get_nextval(T,next);//对串T作分析，得到next数组
	while(i <= S[0] && j<= T[0])//若i小于S的长度且j小于T的长度时，循环继续
	{
		if(j==0||S[i] == T[j])//两字母相等则继续，相等于朴素算法增加了。j=0判断
		{
			++i;
			++j; 
		 } 
		 else//指针后退重新开始匹配
		 {
		 	j = next[j]//j退回合适的位置，i值不变 
		  } 
	 } 
	 if(j > T[0])
	 return i-T[0];
	 else
	 return 0;
 } 
