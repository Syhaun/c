//返回字串T在主串S中第pos个字符之后的位置。若不存在，则函数返回值为0

//假设主串S和要匹配的子串T的长度存在S[0]与T[0]中 
//若T非空，1<=pos<=StrLength(S)
int Index(String S,String T,int pos)
{
	int i = pos;//i用于主串S中当前位置下标，若pos不为1，则从pos位置开始匹配
	int j = 1; //j用于字串T中当前位置下标值
	while( i<= S[0] && j<= T[0])//若i小于S长度q且j小于T的长度时循环
	{
		if(S[i] == T[j])//两字母相等则继续
		{
			++i;
			++j;
		 } 
		 else//指针后退重新开始匹配
		 {
		 	i = i-j+2;//i退回到上次匹配首位的下一位
			 j = 1;//j退回到子串T的首位 
		  } 
	 } 
	 if(j > T[0])
	 return i-T[0];
	 else
	 return 0; 
 } 
