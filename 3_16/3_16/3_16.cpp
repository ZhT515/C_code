#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>

int Spin(const char * aa,char * bb)
{
	char tmp[256] = { 0 };
	strcpy(tmp, aa);		//strcpy，即string copy（字符串复制）的缩写。strcpy是C++语言的一个标准函数，strcpy把含有'\0'结束符的字符串复制到另一个地址空间，返回值的类型为char * 。
	strcat(tmp, aa);  //C 库函数 char *strcat(char *dest, const char *src) 把 src 所指向的字符串追加到 dest 所指向的字符串的结尾。
	return strstr(tmp, bb) != NULL;		//strstr是C语言中的函数，作用是返回字符串中首次出现子串的地址。
}

void Spin2(const char* aa, int k)
{
	char tmp[256] = { 0 };
	strcpy(tmp, aa);
	strcat(tmp, aa);
	char bb[256] = { 0 };
	char* str = tmp;
	str = str + k;
	for (int i = 0; i < sizeof(aa); i++)
	{
		bb[i] = *str;
		str++;
	}
}

int Young_matrix(int a[][5], int x, int y, int n)			//由于杨氏矩阵的特点决定了针对表中的任一元素，下方和右方的数据一定大于我，左方和上方的数据一定小于。
{
	int i = x - 1;
	int j = 0;
	while (j < y && i >= 0)
	{
		if (a[j][i] > n)
		{
			i--;
		}
		else if (a[j][i] < n)
		{
			j++;
		}
		else
		{
			return 1;
		}
	}
	return 0;
}

int main()
{
	/*char a[] = "AABCD";
	char b[] = "BCDAA";
	int ret = Spin(a, b);
	printf("%d", ret);
	Spin2(a, 2);*/

	int a[][5] = { {1, 3, 5 ,7 ,9},
					{2, 4, 6, 8, 10},
					{3, 6, 9, 12, 15},
					{4, 8, 12, 16, 20},
					{5, 10, 15, 20, 25} };
	int n = 25;
	if (Young_matrix(a, 5, 5, n) == 1)
	{
		printf("找到了");
	}
	else
	{
		printf("没找到");
	}

	return 0;
}