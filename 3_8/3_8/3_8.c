#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>

void img()
{
	int m = 0;
	int n = 0;
	int i = 0;
	int j = 0;
	float num;
	int c = 0;
	scanf("%d %d", &m, &n);
	int a[100][100] = { 0 };
	int b[100][100] = { 0 };
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
		{
			scanf("%d", &a[i][j]);
		}
	}
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
		{
			scanf("%d", &b[i][j]);
		}
	}

	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
		{
			if (a[i][j] == b[i][j])
			{
				c++;
			}
		}
	}
	num = (float)100 * c / (m * n);  //强制将运算转换为浮点型
	printf("%.2f",num);
}

void load()
{
	char* user = "admin";
	char* password = "admin";
	char a[20], b[20];
	while (scanf("%19s %19s", &a, &b) != EOF)		//字符串长度
	{
		if (strcmp(a, user) == 0 && strcmp(b, password) == 0)		//基本形式为strcmp(str1,str2)，若str1=str2，则返回零；若str1<str2，则返回负数；若str1>str2，则返回正数
		{
			puts("Login Success!");									//用来向标准输出设备（屏幕）输出字符串并换行
		}
		else
		{
			puts("Login Fail!");
		}
	}

}

int main()
{
	//img();
	load();
}