#include<stdio.h>
#include<string.h>

int romanToInt(char* s)			//��������ת����  
{
	int ret = 0;
	while (*s)		//����\0ֹͣ
	{
		switch (*s++)	//ָ��ָ,SWITCH�������
		{
			case'I':
				ret += (*s == 'V' || *s == 'X') ? -1 : 1;		//��Ϊ�ϱ���s++,���ж��ټӣ���������ֻ��Ҫֱ���ж�
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
			default:		//���ַ��������
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