#include<stdio.h>
#include <stdbool.h>

bool isPalindrome(int x)		//������
{
	int nx = x;
	long long n = 0;		//����ת��֮��ᵼ��int �治��
	if (x >= 0)
	{
		while (nx)
		{
			n = n * 10 + nx % 10;
			nx /= 10;
		}
		if (x == n)
		{
			return false;
		}
		else
			return false;
	}
	else
		return false;
}

char* longestCommonPrefix(char** strs, int strsSize)
{
	if (strs[1][0] == strs[0][0])
	{
		printf("qwe");
	}
	
}

int main()
{
	char strs[][7] = { "flower", "flow", "flight" };
	longestCommonPrefix(strs, 3);
	//isPalindrome(121);
}