#include<stdio.h>
#include<string.h>

int romanToInt(char* s)			//罗马数字转整数  
{
	int ret = 0;
	while (*s)		//遇到\0停止
	{
		switch (*s++)	//指针指,SWITCH语句优秀
		{
			case'I':
				ret += (*s == 'V' || *s == 'X') ? -1 : 1;		//因为上边是s++,先判断再加，所以这里只需要直接判断
				break;
			case'V':
				ret +=  5;
				break;
			case'X':
				ret += (*s  == 'L' || *s == 'C') ? -10 : 10;
				break;
			case'L':
				ret += 50;
				break;
			case'C':
				ret += (*s == 'D' || *s == 'M') ? -100 : 100;
				break;
			case'D':
				ret += 500;
				break;
			case'M':
				ret += 1000;
				break;
			default:		//空字符串的情况
				return 0;
		}
	}
	return ret;
}

int main()
{
	char s[] = "LVIII";
	printf("%d",romanToInt(s));
}