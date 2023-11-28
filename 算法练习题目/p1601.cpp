
#include<stdio.h>
#include<string.h>
#define MAX 520  //其实一个n 位数和 一个m位数相加后的数，最大位数不过也只是n和m中最的的数+1；
//题目说a，b都不超过500位,其实MAX定义501即可,多的1既可以用来存'\0'，又可代表c最多也就501位
char a[MAX];//a和b字符串数组用来暂存输入的大整数
char b[MAX];
int a1[MAX];//a1和b1用来存将字符串中的字符数字转换成整型后的数字。
int b1[MAX];
int c[MAX];//c数组用来存二者相加之和
int main(){
	scanf("%s\n%s", a, b);
	int alen = strlen(a);
	int blen = strlen(b);
	int k = alen > blen ? alen : blen;//k获得二者之间最大位数
	for (int i = 0; i < alen; i++) {
		a1[alen - 1 - i] = a[i] - 48;//倒着存入整型数组中，使得整型数组中的第一位是个位。因为相加都是从个位数开始
	}
	for (int i = 0; i < blen; i++) {
		b1[blen - 1 - i] = b[i] - 48;
	}
	k += 1;
	for (int i = 0; i < k; i++) {
		c[i]+= a1[i] + b1[i];//之所以是+=，是因为，上一步的进位数已经存到c[i]中；
		c[i + 1] = c[i] / 10;//大于等于10的进位到下一位
		c[i] %= 10;//每一位应该都是小于10的数字
	}
	while (c[k] == 0 && k >= 1)k--;//去除前导0
 
	for (int i = k; i >= 0; i--)printf("%d", c[i]);//倒着输出，因为当初相加的时候是从个位开始
	
	return 0;
}