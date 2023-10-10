//T为非空串。若主串S中的第pos个字符之后存在与T相等的子串           
//则返回第一个这样的字串在S中的位置，否则返回0
int Index(String S,String T,int pos)
{
	int n,m,i;
	String sun;
	if(pos>0)
	{
		n = StrLength(S);//得到主串的长度
		m = Strlength(T);//得到字串的长度
		i = pos;
		while(i <= n-m+1)
		{
			SubString(sub,S,i,m)//取主串的第i个位置
			//长度与T相等字串给sub
			if(StrCompare(sub,T) != 0)//如果两串不相等
			++i;
			else			//如果两串相等 
			return i; 		//则返回i值 
		 } 
	}
	return 0;//若无字串与T相等，返回0 
 } 
