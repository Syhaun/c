//通过计算返回字串T的next数组 
void get_next(char* T,int *next)
{
	int i=1,j = 0;
	next[1] = 0;
	while(i<T[0])//此处T[0]表示串T的长度
	{
		if(j == 0||T[i] == T[j]) //T[i]表示后缀的单个字符，T[j]表示前缀的单个字符
		{
			++i;
			++j; 
			next[i] = j; 
		 } 
		 else
		 j = next[j];//若字符不同，则j值回溯 
	 } 
}
//返回子串T在主串S中第pos个字符之后的位置，若不存在，则函数值返回0
// T 非空，1<=pos<=StrLength(S)
int Index_KMP(char* S，char* T,int pos)
{
	int i = pos;//i用于主串S当前位置下标值，若pos不为1，则从pos位置开始匹配
	int j = 1;//j用于子串T中当前位置下标值
	int next[255];//定义一next数组
	get_next(T,next);//对串T作分析，得到next数组
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
 
 
 
 //KMP模式匹配算法改进
  
